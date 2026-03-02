# CipherFile – Çoklu Algoritma Tabanlı Dosya Şifreleme Uygulaması

## Proje Hakkında

CipherFile, C++ programlama dili kullanılarak geliştirilmiş konsol tabanlı bir dosya şifreleme ve çözme uygulamasıdır. 
Bu proje kapsamında simetrik anahtarlı şifreleme yöntemleri olan Sezar, Vigenère ve XOR (Exclusive OR) algoritmaları kullanılmıştır. 
Uygulama, hem metin hem de binary (.jpg, .pdf, .exe vb.) dosyaları byte seviyesinde işleyerek güvenli biçimde şifreleyebilmekte ve ilgili algoritma/anahtar kullanılarak tekrar çözebilmektedir.

## Projenin Amacı

* Dosya giriş/çıkış (File I/O) işlemlerini ve `ios::binary` mantığını öğrenmek
* Binary veri işleme ve byte seviyesinde şifreleme mantığını kavramak
* Sezar, Vigenère ve XOR şifreleme algoritmalarını uygulamak
* C++ dilinde modüler programlama ve güvenli arayüz (girdi doğrulama) pratiği yapmak
* GitHub üzerinden sürüm kontrol sürecini (Branch, Pull Request) ve takım çalışmasını deneyimlemek

## Kullanılan Teknolojiler

* C++ (Standart Kütüphaneler: `<iostream>`, `<fstream>`, `<vector>`, `<chrono>`)
* Sezar, Vigenère ve XOR Algoritmaları
* Git & GitHub

## Şifreleme Algoritmaları Nedir?

Uygulama üç farklı şifreleme altyapısı sunar:
* **Sezar Algoritması:** Dosyadaki her bir byte değerini, kullanıcının girdiği sayısal anahtar kadar ileri veya geri kaydırır.
* **Vigenère Algoritması:** Kullanıcının girdiği metin tabanlı anahtarın harflerini döngüsel olarak kullanarak ardışık byte kaydırma işlemi yapar.
* **XOR (Exclusive OR) Algoritması:** İki bit karşılaştırıldığında farklı ise 1, aynı ise 0 sonucu üreten mantıksal bir operatördür. İşlem tersinir özelliğe sahip olduğu için aynı anahtar kullanılarak hem şifreleme hem de çözme işlemi yapılabilir.
  * Örnek (XOR):
    A ⊕ B
    0 ⊕ 0 = 0
    0 ⊕ 1 = 1
    1 ⊕ 0 = 1
    1 ⊕ 1 = 0

## Program Özellikleri

* 3 farklı algoritma ile dosya şifreleme ve çözme
* Karakter dönüşümü bozulmalarına karşı tam binary dosya desteği
* Sonsuz döngü (Input Buffer Crash) korumalı kullanıcı dostu konsol arayüzü
* İşlem süresinin milisaniye (ms) cinsinden ölçülmesi
* Dosya boyutu görüntüleme

## Örnek Kullanım

**Şifreleme:**
Algoritma Seçimi: 2 (Vigenère)
Input Dosya: test.txt
Anahtar: gizli123
Çıktı Dosya: encrypted.dat

**Çözme:**
Algoritma Seçimi: 2 (Vigenère)
Input Dosya: encrypted.dat
Anahtar: gizli123
Çıktı Dosya: decrypted.txt

## Güvenlik Notu

Bu proje eğitim amaçlıdır.
Kullanılan algoritmalar modern kriptografik standartlara göre güvenli değildir.
Gerçek dünya uygulamalarında AES gibi gelişmiş algoritmalar tercih edilmektedir.

## Geliştiriciler

* Hüseyin Emre Yılmaz
* Kerem Aziz Erdoğan
* Mehmet Alp Yıldırım

BIL1203 – Mühendislikte Proje Yönetimi
2025-2026

## Lisans

Bu proje akademik amaçlı geliştirilmiştir.
