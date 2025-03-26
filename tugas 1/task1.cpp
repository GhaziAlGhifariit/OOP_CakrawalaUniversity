#include <iostream>
#include <string>
using namespace std;

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
