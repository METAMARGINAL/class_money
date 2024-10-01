#pragma once
#include <iostream>

void validate(int& rubles, int& kopecks);

class Money {
    int* rubles;
    int* kopecks;
    int turnInKopecks(int rubles, int kopecks);

public:
    Money();//����������� �� ���������
    Money(int _rubles, int _kopecks);//����������� � ��������� ����������
    Money(const Money& newCash);//����������� �����������
    ~Money();//����������

    int getRubles() const;//������
    int getKopecks() const;

    Money operator+ (const Money& other);//���������� �������������� ��������
    Money operator- (const Money& newCash);
    Money multiplicate(int mul);
    Money div(int del);
    //Money mod(int del);

    bool operator> (const Money& newCash);//���������� ���������� ���������
    bool operator< (const Money& newCash);
    bool operator== (const Money& newCash);
    bool operator!= (const Money& newCash);
    Money& operator=(const Money& cash);

    friend std::ostream& operator<<(std::ostream& os, const Money& money);//���������� ���������� << � >>
    friend std::istream& operator>>(std::istream& is, Money& money);
};


