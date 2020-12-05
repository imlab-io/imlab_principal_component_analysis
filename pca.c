#include "lacore.h"
#include "prcore.h"
#include "imcore.h"
#include "iocore.h"

// function to load train and test data
int load_iris(const char *filename, matrix_t *set, vector_t *label)
{
    // try to read the data
    FILE *pData = fopen(filename, "r");
    // print error if not found
    if (pData == NULL)
    {
        printf("Data file not found!\n");
        return -1;
    }

    // get the file size and found number of samples
    int nSample = get_number_of_lines(pData, 0);

    // resize the inputs
    matrix_resize(set, 4, nSample, 1);
    vector_resize(label, nSample);

    int id, i;
    for (id = 0; id < nSample; id++)
    {
        // read data and labels into set and label
        for (i = 0; i < rows(set); i++)
        {
            fscanf(pData, "%f%*c", data(float, set, i, id));
        }
        fscanf(pData, "%d%*c", data(int, label, id));
    }

    // close the pData file
    fclose(pData);

    return nSample;
}

void find_mean_and_extract(matrix_t *input, matrix_t *mean)
{
    int i, j;

    // resize the mean vector
    matrix_resize(mean, rows(input), 1, 1);

    // find and subtract the mean from the input
    for (i = 0; i < rows(input); i++)
    {
        float m = 0;
        for (j = 0; j < cols(input); j++)
        {
            m += atf(input, i, j);
        }
        atf(mean, i, 0) = m / cols(input);

        // subtract the mean
        for (j = 0; j < cols(input); j++)
        {
            atf(input, i, j) -= atf(mean, i, 0);
        }
    }
}

// compute the PCA of the input
void pca(matrix_t *input, matrix_t *eigValues, matrix_t *eigVectors)
{
    // input: DxN features where N is the number of sample and D is the dimesnion of the data
    int i, j;

    // allocate covariance matrix
    matrix_t *cov = matrix_create(float, rows(input), rows(input), 1);
    
    // find covariance matrix of the input matrix
    for (i = 0; i < rows(input); i++)
    {
        for(j = 0; j < rows(input); j++)
        {
            atf(cov, i, j) = covariance(data(float, input, i, 0, 0), data(float, input, j, 0, 0), cols(input));
        }
    }

    // compute the principal components of the input
    eig(cov, eigValues, eigVectors);

    // remove unused covariance matrix
    matrix_free(&cov);
}


int main(int argc, unsigned char *argv[]) 
{
    matrix_t *data_set = matrix_create(float);
    vector_t *data_labels = vector_create(int);

    // import dataset
    int nDataSample = load_iris("../data/iris/iris.data", data_set, data_labels);
    printf("Dataset sample size: %d\n", nDataSample);

    // compute principal components of the train set
    matrix_t *mean = matrix_create(float);

    // extract mean from the input
    find_mean_and_extract(data_set, mean);

    // create space for the principal components
    matrix_t *pValues = matrix_create(float);
    matrix_t *pVectors = matrix_create(float);

    // find PCA
    pca(data_set, pValues, pVectors);

    printf("Mean:\n");
    if (mean != NULL)
    {
        int r;
        for (r = 0; r < rows(mean); r++)
        {
            // create color gradient
            printf("%6.2f ", atf(mean, r, 0));
        }
        printf("\n");
    }

    // print eigen values
    printf("Eigen Values:\n");
    if (pValues != NULL)
    {
        int r,c;
        for (r = 0; r < rows(pValues); r++)
        {
            for (c = 0; c < cols(pValues); c++)
            {
                // create color gradient
                printf("%6.2f ", atf(pValues, r, c));
            }
            printf("\n");
        }
    }

    // print eigen values
    printf("Eigen Vectors:\n");
    if (pVectors != NULL)
    {
        int r, c;
        for (r = 0; r < rows(pVectors); r++)
        {
            for (c = 0; c < cols(pVectors); c++)
            {
                // create color gradient
                printf("%6.2f ", atf(pVectors, r, c));
            }
            printf("\n");
        }
    }

    // do projection from 4D to 2D
    FILE *fResult = fopen("result.csv", "w");

    // print each principal vector as image
    int i, p;
    for (i = 0; i < nDataSample; i++)
    {
        float d1 = 0, d2 = 0, d3 = 0, d4 = 0;
        for (p = 0; p < rows(pVectors); p++)
        {
            d1 += atf(pVectors, p, 3, 0) * atf(data_set, p, i, 0);
            d2 += atf(pVectors, p, 2, 0) * atf(data_set, p, i, 0);
            d3 += atf(pVectors, p, 1, 0) * atf(data_set, p, i, 0);
            d4 += atf(pVectors, p, 0, 0) * atf(data_set, p, i, 0);
        }

        fprintf(fResult, "%03d, %5.2f, %5.2f, %5.2f, %5.2f, %01d\n", i, d1, d2, d3, d4, ati32(data_labels, i));
    }

    fclose(fResult);

    return 0;
}