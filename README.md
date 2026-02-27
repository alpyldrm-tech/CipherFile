# CipherFile – XOR Tabanlı Dosya Şifreleme Uygulaması

##  Proje Hakkında

CipherFile, C++ programlama dili kullanılarak geliştirilmiş konsol tabanlı bir dosya şifreleme ve çözme uygulamasıdır.  
Bu proje kapsamında simetrik anahtarlı bir şifreleme yöntemi olan XOR (Exclusive OR) algoritması kullanılmıştır.

Uygulama, hem metin hem de binary dosyaları byte seviyesinde işleyerek güvenli biçimde şifreleyebilmekte ve aynı anahtar kullanılarak tekrar çözebilmektedir.

---

##  Projenin Amacı

- Dosya giriş/çıkış (File I/O) işlemlerini öğrenmek
- Binary veri işleme mantığını kavramak
- XOR şifreleme algoritmasını uygulamak
- C++ dilinde modüler programlama pratiği yapmak
- GitHub üzerinden sürüm kontrol sürecini deneyimlemek

---

##  Kullanılan Teknolojiler

- C++
- <fstream> kütüphanesi
- vector<char> veri yapısı
- XOR (Exclusive OR) algoritması
- Git & GitHub

---

##  XOR Algoritması Nedir?

XOR (Exclusive OR), iki bit karşılaştırıldığında farklı ise 1, aynı ise 0 sonucu üreten mantıksal bir operatördür.

Örnek:

A ⊕ B

0 ⊕ 0 = 0  
0 ⊕ 1 = 1  
1 ⊕ 0 = 1  
1 ⊕ 1 = 0  

XOR işlemi tersinir özelliğe sahiptir:

P ⊕ K ⊕ K = P

Bu nedenle aynı anahtar kullanılarak hem şifreleme hem de çözme işlemi yapılabilir.

---

##  Program Özellikleri

- Dosya şifreleme
- Dosya çözme
- Binary dosya desteği
- Anahtarın döngüsel uygulanması
- Basit ve kullanıcı dostu konsol arayüzü
- Dosya boyutu görüntüleme

---


##  Örnek Kullanım

Şifreleme:

Input Dosya: test.txt  
Anahtar: abc123  
Çıktı Dosya: encrypted.dat  

Çözme:

Input Dosya: encrypted.dat  
Anahtar: abc123  
Çıktı Dosya: decrypted.txt  

---


---

##  Güvenlik Notu

Bu proje eğitim amaçlıdır.  
XOR algoritması modern kriptografik standartlara göre güvenli değildir.  
Gerçek dünya uygulamalarında AES gibi gelişmiş algoritmalar tercih edilmektedir.

---

##  Geliştiriciler

- Hüseyin Emre Yılmaz  
- Kerem Aziz Erdoğan  
- Mehmet Alp Yıldırım  

BIL1203 – Mühendislikte Proje Yönetimi  
2025-2026

---

##  Lisans

Bu proje akademik amaçlı geliştirilmiştir.
