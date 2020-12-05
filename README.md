---
layout: post
title: Temel Bilesen Analizi
slug: principal-component-analysis
author: Bahri ABACI
categories:
- Lineer Cebir
- Nümerik Yöntemler
- Makine Öğrenmesi
- Veri Analizi
references: ""
thumbnail: /assets/post_resources/principal_component_analysis/thumbnail.png
---

Temel Bileşen Analizi (Principal Component Analysis), bir veri setinin en küçük karesel ortalama hata ile bir alt uzaya (genelde daha küçük boyutlu) izdüşümünü sağlayan dönüşüm matrisini bulmamıza yarayan bir analiz yöntemidir. Temel Bileşen Analizi (TBA) yüksek boyutlu verilerin daha düşük boyutlara indirilerek görselleştirilmesinde, veri setinin gürültüden arındırılmasında, izdüşüm sonrası elde edilen değerlerin bir araya getirilerek kullanılması durumunda ise yüz tanıma, karakter tanıma gibi uygulamalarda öznitelik olarak kullanılabilmektedir. Bu yazımızda TBA' nin matematiksel olarak nasıl hesaplanacağı ispatlandıktan sonra, eğitimcisiz boyut indirgeme yöntemi olarak nasıl çalıştığı incelenecektir.

<!--more-->

[Özdeğer ve Özvektörler]({% post_url 2019-03-26-ozdeger-ve-ozvektorler %}) yazımızda büyük bir veri setinin kovaryans matrisinin özdeğer ve özvektör analizi yapıldığında, özvektörlerin verinin en yüksek değişintiyi gösterdiği düzlemi/ekseni, özdeğerlerin ise bu düzlemdeki değişinti miktarını gösterdiğini söylemiştik. Şimdi bu söylemimizi TBA' nin yazımızda verilen tanımını, <i>"bir veri setinin en küçük karesel ortalama hata ile daha küçük boyutlu bir alt uzaya izdüşümünü sağlayan dönüşüm matrisini bulmamıza yarayan bir analiz yöntemidir"</i>, kullanarak ispatlayalım.

![temel bileşen analizi][pca_proof]

Yukarıda verilen şekilde verilen <img src="assets/post_resources/math//323ccf2ecdede029a515f1524b22bf0c.svg?invert_in_darkmode" align=middle width=53.04254669999999pt height=27.6567522pt/>, <img src="assets/post_resources/math//78ec2b7008296ce0561cf83393cb746d.svg?invert_in_darkmode" align=middle width=14.06623184999999pt height=22.465723500000017pt/> boyutlu uzayda tanımlı bir nokta olsun. Bu noktanın <img src="assets/post_resources/math//df5a289587a2f0247a5b97c1e8ac58ca.svg?invert_in_darkmode" align=middle width=12.83677559999999pt height=22.465723500000017pt/> doğrusu üzerindeki izdüşüm vektörü, <img src="assets/post_resources/math//df5a289587a2f0247a5b97c1e8ac58ca.svg?invert_in_darkmode" align=middle width=12.83677559999999pt height=22.465723500000017pt/> doğrultusundaki birim vektör <img src="assets/post_resources/math//980fcd4213d7b5d2ffcc82ec78c27ead.svg?invert_in_darkmode" align=middle width=10.502226899999991pt height=14.611878600000017pt/> kullanılarak <img src="assets/post_resources/math//007de734cea91a6c098b6cca0d5d09c1.svg?invert_in_darkmode" align=middle width=70.87862759999999pt height=21.839370299999988pt/> işlemi ile bulunur. 

Bu durumda Pisagor teoremi yardımı ile izdüşüm hatasının karesi aşağıdaki formül ile hesaplanabilir.

<p align="center"><img src="assets/post_resources/math//5b7f0215190f2d9ca3c56aa8917e7730.svg?invert_in_darkmode" align=middle width=301.688508pt height=19.789994399999998pt/></p> 

Elimizde <img src="assets/post_resources/math//b0ea07dc5c00127344a1cad40467b8de.svg?invert_in_darkmode" align=middle width=9.97711604999999pt height=14.611878600000017pt/> noktalarından <img src="assets/post_resources/math//f9c4988898e7f532b9f826a75014ed3c.svg?invert_in_darkmode" align=middle width=14.99998994999999pt height=22.465723500000017pt/> tane olması durumunda Denklem <img src="assets/post_resources/math//db250fb3f09eb0b416173fc1f3eb512d.svg?invert_in_darkmode" align=middle width=17.85378704999999pt height=22.831056599999986pt/> kullanılarak ortalama karesel hata <img src="assets/post_resources/math//00349574123095588c4adf4d3ce506af.svg?invert_in_darkmode" align=middle width=37.365261449999984pt height=24.65753399999998pt/> aşağıdaki şekilde yazılabilir: 

<p align="center"><img src="assets/post_resources/math//91bf048f618c1b6d910844c9e7087c17.svg?invert_in_darkmode" align=middle width=451.13469884999995pt height=71.81742645pt/></p>

Amacımız hatanın en küçük olduğu <img src="assets/post_resources/math//df5a289587a2f0247a5b97c1e8ac58ca.svg?invert_in_darkmode" align=middle width=12.83677559999999pt height=22.465723500000017pt/> doğrusunu bulmak olduğundan, <img src="assets/post_resources/math//00349574123095588c4adf4d3ce506af.svg?invert_in_darkmode" align=middle width=37.365261449999984pt height=24.65753399999998pt/> maliyet fonksiyonu <img src="assets/post_resources/math//980fcd4213d7b5d2ffcc82ec78c27ead.svg?invert_in_darkmode" align=middle width=10.502226899999991pt height=14.611878600000017pt/> değişkeni üzerinden optimize edilmelidir. Denklem <img src="assets/post_resources/math//dd76a15e7bc91f29604fe375175e9757.svg?invert_in_darkmode" align=middle width=17.85378704999999pt height=22.831056599999986pt/> de yer alan <img src="assets/post_resources/math//60c7b4cacede851304ff86d03f7c85b7.svg?invert_in_darkmode" align=middle width=16.438418699999993pt height=21.18721440000001pt/> ifadesi <img src="assets/post_resources/math//980fcd4213d7b5d2ffcc82ec78c27ead.svg?invert_in_darkmode" align=middle width=10.502226899999991pt height=14.611878600000017pt/> ye bağlı olmadığından optimizasyona bir katkısı yoktur. Bu terim çıkarıldığında ve <img src="assets/post_resources/math//cfd21abdbb9dcbdcef0f1338936c46e4.svg?invert_in_darkmode" align=middle width=145.15536089999998pt height=32.256008400000006pt/> tanımlandığında, <img src="assets/post_resources/math//00349574123095588c4adf4d3ce506af.svg?invert_in_darkmode" align=middle width=37.365261449999984pt height=24.65753399999998pt/> maliyet fonksiyonunun en küçüklenmesi problemi aşağıdaki optimizasyon problemine dönüşür: 

<p align="center"><img src="assets/post_resources/math//9fe84cd4295036064d49602d1adaeec4.svg?invert_in_darkmode" align=middle width=245.67344175pt height=26.98890315pt/></p>

Denklem <img src="assets/post_resources/math//e8de0e09136d040cbd34b75943c0316e.svg?invert_in_darkmode" align=middle width=17.85378704999999pt height=22.831056599999986pt/> ile verilen optimizasyon problemi [Lagrange Çarpanları]({% post_url 2020-01-13-lagrange-carpanlari-yontemi %}) yardımı ile çözülebilir. <img src="assets/post_resources/math//fd8be73b54f5436a5cd2e73ba9b6bfa9.svg?invert_in_darkmode" align=middle width=9.58908224999999pt height=22.831056599999986pt/> Lagrange çarpanı kullanılarak <img src="assets/post_resources/math//e8de0e09136d040cbd34b75943c0316e.svg?invert_in_darkmode" align=middle width=17.85378704999999pt height=22.831056599999986pt/> ile verilen maliyet fonksiyonu aşağıdaki şekilde ifade edilir: 

<p align="center"><img src="assets/post_resources/math//02f15a4297db9904b64796a5bf88f66c.svg?invert_in_darkmode" align=middle width=221.88513105pt height=16.438356pt/></p> 

Denklem <img src="assets/post_resources/math//1d494a23de25482ba57955537df900a1.svg?invert_in_darkmode" align=middle width=17.85378704999999pt height=22.831056599999986pt/> ile verilen maliyet fonksiyonun <img src="assets/post_resources/math//fd8be73b54f5436a5cd2e73ba9b6bfa9.svg?invert_in_darkmode" align=middle width=9.58908224999999pt height=22.831056599999986pt/> değişkenine göre türevi alınıp sıfıra eşitlenirse <img src="assets/post_resources/math//e9e8f882ec7fcd00bf39e5d61d2c9127.svg?invert_in_darkmode" align=middle width=59.406149549999995pt height=21.839370299999988pt/> bulunur.

Denklem <img src="assets/post_resources/math//1d494a23de25482ba57955537df900a1.svg?invert_in_darkmode" align=middle width=17.85378704999999pt height=22.831056599999986pt/> in <img src="assets/post_resources/math//980fcd4213d7b5d2ffcc82ec78c27ead.svg?invert_in_darkmode" align=middle width=10.502226899999991pt height=14.611878600000017pt/> ye göre türevi alınıp sıfıra eşitlenirse de 

<p align="center"><img src="assets/post_resources/math//fb2e94fae37dde10c3e7e06e1e49b5ed.svg?invert_in_darkmode" align=middle width=309.61637025pt height=37.9216761pt/></p> 

bulunur. Denklem <img src="assets/post_resources/math//3b69fd623c0b3fb77662cff31f7054cb.svg?invert_in_darkmode" align=middle width=17.85378704999999pt height=22.831056599999986pt/> ifadesi [Özdeğer ve Özvektörler]({% post_url 2019-03-26-ozdeger-ve-ozvektorler %}) yazımızı hatırlayanlar için tanıdık bir ifadedir. Denklem <img src="assets/post_resources/math//3b69fd623c0b3fb77662cff31f7054cb.svg?invert_in_darkmode" align=middle width=17.85378704999999pt height=22.831056599999986pt/> şeklinde verilen bir problemin çözümünü sağlayan <img src="assets/post_resources/math//980fcd4213d7b5d2ffcc82ec78c27ead.svg?invert_in_darkmode" align=middle width=10.502226899999991pt height=14.611878600000017pt/> vektörleri <img src="assets/post_resources/math//12d3ebda1a212bd89197298f60cf3ce1.svg?invert_in_darkmode" align=middle width=13.652895299999988pt height=22.55708729999998pt/> matrisinin özvektörleri, <img src="assets/post_resources/math//fd8be73b54f5436a5cd2e73ba9b6bfa9.svg?invert_in_darkmode" align=middle width=9.58908224999999pt height=22.831056599999986pt/> değerleri ise <img src="assets/post_resources/math//12d3ebda1a212bd89197298f60cf3ce1.svg?invert_in_darkmode" align=middle width=13.652895299999988pt height=22.55708729999998pt/> matrisinin özdeğerleri olarak bilinir. Hesaplanabilecek tüm özvektör ve özdeğerler <img src="assets/post_resources/math//feea35d17c2eb623a2e9f88679e83a5a.svg?invert_in_darkmode" align=middle width=148.01065619999997pt height=24.65753399999998pt/> ve <img src="assets/post_resources/math//9377ade3621885e0025ea3148c3276d1.svg?invert_in_darkmode" align=middle width=139.91463255pt height=24.65753399999998pt/>, <img src="assets/post_resources/math//044a6b822e0cbbd3a39df66a0b5c8c70.svg?invert_in_darkmode" align=middle width=81.33714434999999pt height=27.6567522pt/> matrisinin temel bileşenlerini oluşturmaktadır.

İfadede yer alan <img src="assets/post_resources/math//98ed97883ccab4aef95718f3d1b8b7d6.svg?invert_in_darkmode" align=middle width=145.15536089999998pt height=32.256008400000006pt/> matrisinin de sıfır ortalamalı bir <img src="assets/post_resources/math//1afb04d63046c001356585ec7d575f73.svg?invert_in_darkmode" align=middle width=18.24194624999999pt height=14.611878600000017pt/> veri seti için kovaryans (özdeğişinti) matrisi olduğu dikkate alınırsa; **bir veri setinin en küçük karesel ortalama hata ile daha küçük boyutlu bir alt uzaya izdüşümünü sağlayan dönüşüm matrisininin; verinin kovaryans matrisinin özvektörleri olduğu sonucuna ulaşılır.**

### Temel Bileşen Analizi C Kodu
[Özdeğer ve Özvektörler]({% post_url 2019-03-26-ozdeger-ve-ozvektorler %}) yazımızda özdeğer ve özvektörlerin IMLAB içerisinde yer alan `eig` fonksiyonu yardımıyla hesaplanabileceğini görmüştük. Kovaryans hesaplamak için de kütüphanede yer alan `covariance` fonksiyonu kullanılarak Temel Bileşen Analizi aşağıdaki verilen kod parçassı ile hesaplanabilmektedir.

```c
// compute the PCA of the input
void pca(matrix_t *input, matrix_t *eigValues, matrix_t *eigVectors)
{
    // input: DxN features where N is the number of sample and D is the dimension of the data
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
```

Kod parçası girdi olarak verilen sıfır ortalamalı (ortalaması çıkartılmış) <img src="assets/post_resources/math//83097c7fa8f8bc5be054407090465aaf.svg?invert_in_darkmode" align=middle width=79.89425729999999pt height=27.6567522pt/> matrisini kullanarak ilk olarak <img src="assets/post_resources/math//b9128ca833f21b4c35f572408bd62404.svg?invert_in_darkmode" align=middle width=48.22365404999999pt height=22.465723500000017pt/> boyutlu kovaryans matrisini (<img src="assets/post_resources/math//9b325b9e31e85137d1de765f43c0f8bc.svg?invert_in_darkmode" align=middle width=12.92464304999999pt height=22.465723500000017pt/>) hesaplamaktadır. Ardından <img src="assets/post_resources/math//9b325b9e31e85137d1de765f43c0f8bc.svg?invert_in_darkmode" align=middle width=12.92464304999999pt height=22.465723500000017pt/> matrisi üzerinde Jacobi iterasyonu kullanılarak özdeğer ve özvektörler bulunmaktadır. Bulunan özdeğer ve özvektörler girdi matrisi <img src="assets/post_resources/math//cbfb1b2a33b28eab8a3e59464768e810.svg?invert_in_darkmode" align=middle width=14.908688849999992pt height=22.465723500000017pt/> in temel bileşenlerini oluşturmaktadır.

### Temel Bileşen Analizi ile Boyut İndirgeme
Büyük veri işlemede ve veri madenciliğinde verinin görselleştirilebilmesi ve veri hakkında çıkarımların yapılabilmesi için <img src="assets/post_resources/math//78ec2b7008296ce0561cf83393cb746d.svg?invert_in_darkmode" align=middle width=14.06623184999999pt height=22.465723500000017pt/> boyutlu uzayda yer alan bir verinin çeşitliliği korunarak yani en az kayıp ile daha küçük boyutlu <img src="assets/post_resources/math//895bae1825e9c662af062d2ec6d66417.svg?invert_in_darkmode" align=middle width=92.76244394999999pt height=24.65753399999998pt/> bir uzaya taşınması gerekir. Yazımızın konusu olan Temel Bileşen Analizi günümüzde **eğitimcisiz boyut indirgeme** (unsupervised dimensionality reduction) yöntemleri arasında akla gelen ilk yöntemdir.

TBA sonucu bulunan özvektörlere karşı gelen özdeğerler, verinin o özvektör eksenindeki değişinti miktarını göstermektedir. <img src="assets/post_resources/math//78ec2b7008296ce0561cf83393cb746d.svg?invert_in_darkmode" align=middle width=14.06623184999999pt height=22.465723500000017pt/> boyutlu öznitelik uzayında, tüm öznitelikler birbirine dik değilse (çoğu zaman öznitelikler birbiri ile ilintilidir), yapılan TBA sonrasında değişinti miktarları analiz edildiğinde bir grup özvektör ile yapılan izdüşümün değişintinin çok az olduğu görülür. Veri setindeki toplam değişintinin <img src="assets/post_resources/math//f965ba1678ac8e5378daead9ccb5ace7.svg?invert_in_darkmode" align=middle width=51.969107849999986pt height=21.18721440000001pt/> oranında (<img src="assets/post_resources/math//1f3bea003aeef0e99702985c513bce7b.svg?invert_in_darkmode" align=middle width=30.137091599999987pt height=24.65753399999998pt/>) korunarak boyut indirgeme yapılmak istendiğinde şu adımlar izlenmelidir:

* özdeğer ve karşı gelen özvektörleri (<img src="assets/post_resources/math//10b25a8965607b9859b33bd6a26ec73b.svg?invert_in_darkmode" align=middle width=14.239981799999988pt height=22.831056599999986pt/>) büyükten küçüğe sıralanır
* <img src="assets/post_resources/math//d9ebc8ca69c3b7701affa210171b00cc.svg?invert_in_darkmode" align=middle width=84.46715309999999pt height=24.657735299999988pt/> ihtiyaç duyulan toplam değişinti hesaplanır
* <img src="assets/post_resources/math//441c1dd1aecd38de58d888fc14e5b241.svg?invert_in_darkmode" align=middle width=132.95705445pt height=32.256008400000006pt/> şartını sağlayan <img src="assets/post_resources/math//d6328eaebbcd5c358f426dbea4bdbf70.svg?invert_in_darkmode" align=middle width=15.13700594999999pt height=22.465723500000017pt/> değeri bulunur

Bu işlem sonrasında bulunan <img src="assets/post_resources/math//d6328eaebbcd5c358f426dbea4bdbf70.svg?invert_in_darkmode" align=middle width=15.13700594999999pt height=22.465723500000017pt/> değeri, <img src="assets/post_resources/math//96002992c5695d1109a56ec4ff559dc7.svg?invert_in_darkmode" align=middle width=52.460418449999985pt height=27.6567522pt/> uzayından verinin toplam değişintisinin <img src="assets/post_resources/math//0fe1677705e987cac4f589ed600aa6b3.svg?invert_in_darkmode" align=middle width=9.046852649999991pt height=14.15524440000002pt/> oranında korunarak <img src="assets/post_resources/math//06707bf939e3dcbf228526193c4c4fd5.svg?invert_in_darkmode" align=middle width=52.464190349999996pt height=27.6567522pt/> uzayına izdüşüm yapılabileceğini gösterir. Tüm veri seti için boyut indirgeme şu şekilde yapılır: <p align="center"><img src="assets/post_resources/math//6553f4bd4fc9cc484fadf9ac1f6969c7.svg?invert_in_darkmode" align=middle width=242.50325055pt height=17.32880325pt/></p>Temel Bileşen Analizi ile boyut indirgeme örneği için Mor İris Çiçeği (Iris Database) kullanılmıştır. Bu veri seti Ronald Fisher' in iris çiçeğinin üç türünü ayırt etmek için yaptığı <img src="assets/post_resources/math//17e047676dc9923dbadd4ac16623c812.svg?invert_in_darkmode" align=middle width=61.57522799999998pt height=22.465723500000017pt/> uzunluk ölçümünü içermektedir. Ölçümler çiçeğin taç yaprağının (petal) ve çanak yaprağının (sepal) uzunluk ve genişlikleri olmak üzere <img src="assets/post_resources/math//07cb44cb99bc7b64fae3b135df30331e.svg?invert_in_darkmode" align=middle width=44.20307099999999pt height=22.465723500000017pt/> boyutlu bir uzaydadır.

Mor İris Çiçeği veri seti üzerinde TBA yapıldığında özdeğer vektörü <img src="assets/post_resources/math//b88485da1475f6fdcd2e8f89e7771cfa.svg?invert_in_darkmode" align=middle width=179.45221965pt height=24.65753399999998pt/> şeklinde bulunur. Vektör incelendiğinde en yüksek iki özdeğer (<img src="assets/post_resources/math//17e6ac329e3ff60f04b23479353312f0.svg?invert_in_darkmode" align=middle width=40.41105584999999pt height=22.831056599999986pt/>) ve özvektör (<img src="assets/post_resources/math//1c4d1a1553795924ed19214a52cba63e.svg?invert_in_darkmode" align=middle width=44.027212349999985pt height=14.611878600000017pt/>) seçildiğinde veri setindeki çeşitliliğin <img src="assets/post_resources/math//a2a7f64511e921d51c340c1a40a77487.svg?invert_in_darkmode" align=middle width=191.333802pt height=27.77565449999998pt/> inin korunduğu görülür. <img src="assets/post_resources/math//9325f21bb64deb952d509c6ee3bc4fb1.svg?invert_in_darkmode" align=middle width=17.94970814999999pt height=14.611878600000017pt/> ve <img src="assets/post_resources/math//c4b9fc19fb7773d23be2669f13666e8f.svg?invert_in_darkmode" align=middle width=17.94970814999999pt height=14.611878600000017pt/> özvektörleri ile yapılan izdüşüm sonrasında oluşan iki boyutlu  veri aşağıdaki grafikte gösterilmiştir.

![temel bileşen analizi iris veri seti][plotly_iris_plot]

Grafikten de görüldüğü gibi veri setinin değişintisinin çok büyük bir kısmı birinci temel bileşen doğrultusunda gerçekleşmektedir. Böyle bir veri seti için sadece birinci temel bileşen doğrultusundaki izdüşümler (<img src="assets/post_resources/math//deceeaf6940a8c7a5a02373728002b0f.svg?invert_in_darkmode" align=middle width=8.649225749999989pt height=14.15524440000002pt/> ekseni tüm veriler için sıfır olsa dahi) kullanılsa dahi veri setinin neredeyse tamamı doğru sınıflandırılabilmektedir.

### Temel Bileşen Analizi Yönteminin Çalışmadığı Durumlar
Temel Bileşen Analizi her ne kadar eğitimcisiz boyut indirgeme yöntemleri arasında akla gelen ilk yöntem olsa da sınıfların en büyük değişintinin bulunduğu eksen yönünde dağılmadığı durumlarda (çok nadir) boyut indirgeme amacı ile kullanılamamaktadır. Aşağıda oluşturulan kasıtlı örnekte bu durum görselleştirilmiştir. A ve B sınıflarını ayırmak için yapılan iki öznitelikli ölçümler soldaki grafikte verilmiştir.

![temel bileşen analizi][pca_fail_data_example]

Bu ölçümlere ait TBA sonucu ise sağdaki grafikte verilmiştir. Dikkat edilecek olursa A ve B sınıfı birinci temel bileşen doğrultusunda en yüksek değişintiyi göstermesine rağmen bu doğrultuda (<img src="assets/post_resources/math//deceeaf6940a8c7a5a02373728002b0f.svg?invert_in_darkmode" align=middle width=8.649225749999989pt height=14.15524440000002pt/> ekseni sıfır kabul edildiğinde) A ve B sınıflarının ayrıştırılması mümkün değildir. İncelenen veri ikinci temel bileşen doğrultusunda daha az değişinti göstermesine rağmen bu eksenin ayrıştırma gücü daha yüksektir. Örnekte verildiği gibi sınıfların en büyük değişinti eksenleri etrafında dağılmadığı bir sınıflandırma probleminde, boyut indirgeme sonucu elde edilen öznitelikleri sınıflandırma algoritmaları (ne kadar ileri seviye olursa olsun) ayrıştıramayacaktır. Bu gibi durumların önüne geçmek için etiket bilgisinin kullanılabildiği durumlarda toplam değişintinin en büyük olduğu eksen yerine, sınıfların ayrışımını en iyi yapan ekseni bulmaya çalışan Doğrusal Ayrıştırma Analizi (Linear Discriminant Analysis) gibi yöntemler tercih edilebilir.

Yazıda yer alan analizlerin yapıldığı kod parçaları, görseller ve kullanılan veri setlerine [cescript_blog_principal_component_analysis](https://github.com/cescript/cescript_blog_principal_component_analysis) GitHub sayfası üzerinden erişilebilir.

**Referanslar**
* Jolliffe, Ian. Principal component analysis. Springer Berlin Heidelberg, 2011.
* [Iris çiçeği veriseti wikipedia sayfası](https://www.wikiwand.com/en/Iris_flower_data_set)
* [Python scikit kütüphanesinde yer alan eğitimcisiz boyut indirgeme yöntemleri](https://scikit-learn.org/stable/modules/unsupervised_reduction.html)

[RESOURCES]: # (List of the resources used by the blog post)
[pca_proof]: /assets/post_resources/principal_component_analysis/pca_proof.png
[plotly_iris_plot]: /assets/post_resources/principal_component_analysis/plotly_iris_plot.png
[pca_fail_data_example]: /assets/post_resources/principal_component_analysis/pca_fail_data_example.png
