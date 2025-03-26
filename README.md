## Sistem Pembayaran
## Buat sistem pembayaran digital dengan:

**○ Payment sebagai parent class (id, amount, date, status)**

**○ Child classes:**

  **1 CreditCardPayment: cardNumber, expiryDate,cvv**

  **2 BankTransfer: accountNumber, bankName,transferCode**

  **3 DigitalWallet: walletId, provider,phoneNumber**'

**○ Implement method processPayment(),validatePayment(), refundPayment()**




# Sistem Pembayaran Digital

## Deskripsi
Sistem ini merupakan implementasi pembayaran digital dengan konsep Object-Oriented Programming (OOP) dalam bahasa C++. Sistem mendukung tiga metode pembayaran:
1. **Kartu Kredit (Credit Card Payment)**
2. **Transfer Bank (Bank Transfer)**
3. **Dompet Digital (Digital Wallet)**

Setiap metode pembayaran memiliki cara validasi, pemrosesan, dan pengembalian dana masing-masing.

## Struktur Kelas
### **1. Kelas `Payment` (Parent Class)**
Kelas dasar yang digunakan untuk menyimpan informasi umum tentang pembayaran:
```cpp
class Payment {
protected:
    int id;
    double amount;
    string date;
    string status;

public:
    Payment(int id, double amount, string date, string status)
        : id(id), amount(amount), date(date), status(status) {}
    virtual void processPayment() = 0;
    virtual bool validatePayment() = 0;
    virtual void refundPayment() = 0;
    virtual ~Payment() {}
};
```
- `id` → ID unik pembayaran
- `amount` → Jumlah uang yang harus dibayarkan
- `date` → Tanggal transaksi
- `status` → Status transaksi (Pending, Processed, Refunded)

Metode dalam `Payment` bersifat **virtual** agar dapat diimplementasikan ulang di kelas turunan:
- `processPayment()` → Memproses pembayaran
- `validatePayment()` → Memeriksa validitas data pembayaran
- `refundPayment()` → Mengembalikan dana pembayaran

### **2. Kelas `CreditCardPayment` (Turunan dari `Payment`)**
Merepresentasikan pembayaran dengan kartu kredit.
```cpp
class CreditCardPayment : public Payment {
private:
    string cardNumber;
    string expiryDate;
    int cvv;

public:
    CreditCardPayment(int id, double amount, string date, string status, string cardNumber, string expiryDate, int cvv)
        : Payment(id, amount, date, status), cardNumber(cardNumber), expiryDate(expiryDate), cvv(cvv) {}

    void processPayment() override {
        if (validatePayment()) {
            status = "Processed";
            cout << "Credit card payment processed successfully.\n";
        } else {
            cout << "Invalid credit card details.\n";
        }
    }

    bool validatePayment() override {
        return !cardNumber.empty() && !expiryDate.empty() && cvv > 99;
    }

    void refundPayment() override {
        status = "Refunded";
        cout << "Credit card payment refunded.\n";
    }
};
```
- Atribut tambahan:
  - `cardNumber` → Nomor kartu kredit
  - `expiryDate` → Tanggal kedaluwarsa
  - `cvv` → Kode keamanan
- Implementasi metode:
  - `validatePayment()` → Memeriksa validitas nomor kartu, tanggal kedaluwarsa, dan CVV.
  - `processPayment()` → Jika valid, status menjadi "Processed".
  - `refundPayment()` → Status berubah menjadi "Refunded".

### **3. Kelas `BankTransfer` (Turunan dari `Payment`)**
Merepresentasikan pembayaran melalui transfer bank.
```cpp
class BankTransfer : public Payment {
private:
    string accountNumber;
    string bankName;
    string transferCode;

public:
    BankTransfer(int id, double amount, string date, string status, string accountNumber, string bankName, string transferCode)
        : Payment(id, amount, date, status), accountNumber(accountNumber), bankName(bankName), transferCode(transferCode) {}

    void processPayment() override {
        if (validatePayment()) {
            status = "Processed";
            cout << "Bank transfer processed successfully.\n";
        } else {
            cout << "Invalid bank transfer details.\n";
        }
    }

    bool validatePayment() override {
        return !accountNumber.empty() && !bankName.empty() && !transferCode.empty();
    }

    void refundPayment() override {
        status = "Refunded";
        cout << "Bank transfer payment refunded.\n";
    }
};
```
- Atribut tambahan:
  - `accountNumber` → Nomor rekening
  - `bankName` → Nama bank
  - `transferCode` → Kode transaksi
- Implementasi metode:
  - `validatePayment()` → Memeriksa apakah semua data tidak kosong.
  - `processPayment()` → Jika valid, status menjadi "Processed".
  - `refundPayment()` → Status berubah menjadi "Refunded".

### **4. Kelas `DigitalWallet` (Turunan dari `Payment`)**
Merepresentasikan pembayaran dengan dompet digital.
```cpp
class DigitalWallet : public Payment {
private:
    string walletId;
    string provider;
    string phoneNumber;

public:
    DigitalWallet(int id, double amount, string date, string status, string walletId, string provider, string phoneNumber)
        : Payment(id, amount, date, status), walletId(walletId), provider(provider), phoneNumber(phoneNumber) {}

    void processPayment() override {
        if (validatePayment()) {
            status = "Processed";
            cout << "Digital wallet payment processed successfully.\n";
        } else {
            cout << "Invalid digital wallet details.\n";
        }
    }

    bool validatePayment() override {
        return !walletId.empty() && !provider.empty() && phoneNumber.length() == 10;
    }

    void refundPayment() override {
        status = "Refunded";
        cout << "Digital wallet payment refunded.\n";
    }
};
```
- Atribut tambahan:
  - `walletId` → ID dompet digital
  - `provider` → Penyedia layanan (GoPay, OVO, Dana, dll.)
  - `phoneNumber` → Nomor HP terkait
- Implementasi metode:
  - `validatePayment()` → Memeriksa apakah ID dompet, provider, dan nomor HP (10 digit) valid.
  - `processPayment()` → Jika valid, status menjadi "Processed".
  - `refundPayment()` → Status berubah menjadi "Refunded".

## Cara Menjalankan Program
```cpp
int main() {
    CreditCardPayment ccPayment(1, 150.75, "2025-03-26", "Pending", "1234567812345678", "12/26", 123);
    BankTransfer btPayment(2, 500.00, "2025-03-26", "Pending", "987654321", "Bank XYZ", "TRX123");
    DigitalWallet dwPayment(3, 200.50, "2025-03-26", "Pending", "WALLET123", "PayFast", "0812345678");
    
    ccPayment.processPayment();
    ccPayment.refundPayment();

    btPayment.processPayment();
    btPayment.refundPayment();

    dwPayment.processPayment();
    dwPayment.refundPayment();

    return 0;
}
```



