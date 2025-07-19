# C++ Module 07 - C++ Templates

## 📋 İçindekiler
- [Genel Bakış](#genel-bakış)
- [Genel Kurallar](#genel-kurallar)
- [Egzersizler](#egzersizler)
- [Kurulum ve Çalıştırma](#kurulum-ve-çalıştırma)
- [Önemli Notlar](#önemli-notlar)

## 🎯 Genel Bakış

Bu modül, C++ programlama dilinin **template** (şablon) özelliklerini öğretmeyi amaçlamaktadır. Templates, C++'ın en güçlü özelliklerinden biridir ve generic programming (genel programlama) için kullanılır.

### Template Nedir?
Template'ler, farklı veri tipleriyle çalışabilen genel kod yazmanızı sağlar. Aynı algoritma veya veri yapısını int, double, string veya kendi oluşturduğunuz sınıflarla kullanabilirsiniz.

## 📜 Genel Kurallar

### Derleme Kuralları
- Kodunuzu `c++` ile `-Wall -Wextra -Werror` flag'leriyle derleyin
- Kodunuz `-std=c++98` flag'i ile de derlenebilir olmalı

### Format ve İsimlendirme Kuralları
- Egzersiz dizinleri: `ex00`, `ex01`, ..., `exn` şeklinde adlandırılmalı
- Sınıf isimleri **UpperCamelCase** formatında olmalı
- Dosya isimleri sınıf isimlerine göre olmalı:
  - `ClassName.hpp` / `ClassName.h`
  - `ClassName.cpp`

### İzin Verilen/Yasak Olan
**İzin Verilen:**
- Standart kütüphane kullanımı
- C++ versiyonlarını tercih edin (C fonksiyonları yerine)

**Yasak Olan:**
- `*printf()`, `*alloc()`, `free()` fonksiyonları
- `using namespace <ns_name>` (açıkça belirtilmediği sürece)
- `friend` anahtar kelimesi (açıkça belirtilmediği sürece)
- STL (Module 08 ve 09'a kadar)
- Harici kütüphaneler

### Tasarım Gereksinimleri
- Memory leak'lerden kaçının
- Orthodox Canonical Form kullanın (Module 02-09)
- Header dosyalarında fonksiyon implementasyonu yapmayın (template fonksiyonlar hariç)
- Include guard'ları ekleyin
- Her header dosyası bağımsız olarak kullanılabilir olmalı

## 🏋️ Egzersizler

### Exercise 00: Start with a few functions

**Dosyalar:** `Makefile`, `main.cpp`, `whatever.{h, hpp}`

**Görev:** Aşağıdaki fonksiyon template'lerini implement edin:

1. **swap:** İki parametrenin değerlerini değiştirir, hiçbir şey döndürmez
2. **min:** İki değeri karşılaştırır ve küçük olanı döndürür (eşitse ikincisini)
3. **max:** İki değeri karşılaştırır ve büyük olanı döndürür (eşitse ikincisini)

**Gereksinimler:**
- Template'ler header dosyalarında tanımlanmalı
- Herhangi bir tip ile çalışabilmeli
- İki argüman aynı tipte olmalı
- Karşılaştırma operatörlerini desteklemeli

**Test Çıktısı:**
```
a = 3, b = 2
min(a, b) = 2
max(a, b) = 3
c = chaine2, d = chaine1
min(c, d) = chaine1
max(c, d) = chaine2
```

### Exercise 01: Iter

**Dosyalar:** `Makefile`, `main.cpp`, `iter.{h, hpp}`

**Görev:** 3 parametre alan ve hiçbir şey döndürmeyen bir `iter` fonksiyon template'i implement edin:

1. **İlk parametre:** Dizinin adresi
2. **İkinci parametre:** Dizinin uzunluğu
3. **Üçüncü parametre:** Dizinin her elemanı üzerinde çağrılacak fonksiyon

**Gereksinimler:**
- Herhangi bir tip dizi ile çalışabilmeli
- Üçüncü parametre instantiated function template olabilmeli
- Fonksiyon const veya non-const reference alabilmeli
- Test dosyası içermeli

### Exercise 02: Array

**Dosyalar:** `Makefile`, `main.cpp`, `Array.{h, hpp}`, `Array.tpp` (opsiyonel)

**Görev:** T tipinde elemanlar içeren bir `Array` sınıf template'i geliştirin.

**Gereksinimler:**

**Constructor'lar:**
- Parametresiz constructor: Boş dizi oluşturur
- `unsigned int n` parametreli constructor: n elemanlı varsayılan değerlerle başlatılmış dizi

**Kopyalama:**
- Copy constructor ve assignment operator
- Kopyalama sonrası orijinal ve kopya birbirini etkilememeli

**Bellek Yönetimi:**
- `operator new[]` kullanılmalı
- Preventive allocation yasak
- Non-allocated memory'ye erişim olmamalı

**Erişim:**
- `[]` operatörü ile eleman erişimi
- Index out of bounds durumunda `std::exception` fırlatılmalı
- `size()` member function: Eleman sayısını döndürür

## 🚀 Kurulum ve Çalıştırma

### Gereksinimler
- C++98 uyumlu derleyici
- Make

### Derleme
```bash
# Her egzersiz için
cd ex00  # veya ex01, ex02
make
```

### Çalıştırma
```bash
./program_name
```

## ⚠️ Önemli Notlar

### Memory Management
- `new` ile allocate edilen memory'yi `delete` ile free edin
- Memory leak'lerden kaçının
- Array'ler için `new[]` ve `delete[]` kullanın

### Template Kullanımı
- Template'ler header dosyalarında tanımlanmalı
- Template instantiation compile time'da gerçekleşir
- Type deduction kullanabilirsiniz

### Exception Handling
- Array bounds checking için exception kullanın
- `std::exception` sınıfını inherit edebilirsiniz

### Best Practices
- Kodunuzu temiz ve okunabilir tutun
- Peer evaluator'ların anlayabileceği şekilde yazın
- Her header dosyasını bağımsız olarak test edin
- Include guard'ları unutmayın

## 🔍 Test Stratejisi

Her egzersiz için:
1. Temel fonksiyonaliteyi test edin
2. Edge case'leri kontrol edin
3. Farklı veri tipleriyle test edin
4. Memory leak'leri kontrol edin
5. Exception handling'i test edin

## 📚 Öğrenme Hedefleri

Bu modülü tamamladıktan sonra:
- Template syntax'ını anlayacaksınız
- Generic programming kavramını öğreneceksiniz
- Type-safe generic kod yazabileceksiniz
- Template specialization kavramını anlayacaksınız
- STL'in nasıl çalıştığını anlayacaksınız

## 🎓 Değerlendirme

- Kod kalitesi ve okunabilirlik
- Template doğru kullanımı
- Memory management
- Exception handling
- Test coverage
- Kod organizasyonu

---

**Not:** Bu modül, C++'ın template sisteminin temellerini öğretir. Template'ler modern C++'ın en güçlü özelliklerinden biridir ve STL'in temelini oluşturur. 