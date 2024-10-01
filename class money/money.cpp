#include "Money.h"
#include<istream>
#include<ostream>

int Money::turnInKopecks(int rubles, int kopecks) {
    int res = rubles * 100 + kopecks;
    return res;
}

void validate(int& rubles, int& kopecks) {
    if (rubles < 0 || kopecks < 0) {
        rubles = 0;
        kopecks = 0;
    }
    if (kopecks >= 100) {
        rubles += (kopecks / 100);
        kopecks %= 100;
    }
}

int Money::getRubles() const
{
    return *rubles;
}

int Money::getKopecks() const
{
    return *kopecks;
}

Money::Money() {
    rubles = new int(0);
    kopecks = new int(0);
}

Money::Money(int r, int k) {
    validate(r, k);
    rubles = new int(r);    
    kopecks = new int(k);   
}

Money::Money(const Money& other) {
    if (other.rubles) {
        rubles = new int(*other.rubles);  
    }
    else {
        rubles = nullptr;
    }

    if (other.kopecks) {
        kopecks = new int(*other.kopecks); 
    }
    else {
        kopecks = nullptr;
    }
}

Money::~Money() {
    delete kopecks;
    delete rubles;
}

Money Money::operator+(const Money& other)  {
    Money result;  // ����������� �� ���������, ���������������� ���������

    int r = *this->rubles + *other.rubles;
    int k = *this->kopecks + *other.kopecks;

    validate(r, k);  // ������������ ���������

    // ����������� ��������� ����� result
    *result.rubles = r;
    *result.kopecks = k;

    return result;
}

Money Money::operator-(const Money& other) {
    Money result;  // ����������� �� ���������, ���������������� ���������

    int r = *this->rubles - *other.rubles;
    int k = *this->kopecks - *other.kopecks;

    validate(r, k);  // ������������ ���������

    // ����������� ��������� ����� result
    *result.rubles = r;
    *result.kopecks = k;

    return result;
}

Money Money::multiplicate(int mul) {
   Money result;

   int kop = turnInKopecks(*rubles, *kopecks);
   kop *= mul;
   int rubl = 0;
   validate(rubl, kop);

    *result.rubles = rubl;
    *result.kopecks = kop;

    return result;
}

Money Money::div(int del) {
    if (del == 0) {
        throw std::invalid_argument("Division by zero"); // ��������� ������� �� ����
    }

    int kop = turnInKopecks(*rubles, *kopecks);
    int resultKopecks = kop / del; // ����� ����� �� �������
    return Money(resultKopecks / 100, resultKopecks % 100); // ���������� ����� � �������
}

//Money Money::mod(int del) {
//    if (del == 0) {
//        throw std::invalid_argument("Modulo by zero"); // ��������� ������� �� ����
//    }
//
//    int kop = turnInKopecks(*rubles, *kopecks);
//    int resultKopecks = kop % del; // ������� �� �������
//    return Money(resultKopecks / 100, resultKopecks % 100); // ���������� ����� � �������
//}

bool Money::operator>(const Money& newCash) {
    return (turnInKopecks(*rubles, *kopecks)) > (turnInKopecks(*newCash.rubles, *newCash.kopecks));
}

bool Money::operator<(const Money& newCash) {
    return (turnInKopecks(*rubles, *kopecks)) < (turnInKopecks(*newCash.rubles, *newCash.kopecks));
}

bool Money::operator==(const Money& newCash) {
    return (turnInKopecks(*rubles, *kopecks)) == (turnInKopecks(*newCash.rubles, *newCash.kopecks));
}

bool Money::operator!= (const Money& newCash) { //return !operator==
    return (!operator==(newCash));
}

Money& Money::operator=(const Money& other) {
    if (this == &other) {
        return *this;  // ������ �� ����������������
    }

    // ����������� ������� ������
    delete rubles;
    delete kopecks;

    // �������� ����� ������
    rubles = new int(*other.rubles);
    kopecks = new int(*other.kopecks);

    std::cout << "�������� ������������\n";
    return *this;
}

 std::ostream& operator<<(std::ostream& os, const Money& money) {
    os << *money.rubles << " ���. " << *money.kopecks << " ���.";
    return os;
}

 std::istream& operator>>(std::istream& is, Money& money) {
    int r, k;
    is >> r >> k;
    *money.rubles = r;
    *money.kopecks = k;
    validate(*money.rubles, *money.kopecks);
    return is;
}