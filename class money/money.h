#pragma once
#include <iostream>

void validate(int& rubles, int& kopecks);

class Money {
    int* rubles;
    int* kopecks;
    int turnInKopecks(int rubles, int kopecks);

public:
    Money();//конструктор по умолчанию
    Money(int _rubles, int _kopecks);//конструктор с заданными значениями
    Money(const Money& newCash);//конструктор копирования
    ~Money();//деструктор

    int getRubles() const;//гетеры
    int getKopecks() const;

    Money operator+ (const Money& other);//перегрузка арифметических операций
    Money operator- (const Money& newCash);
    Money multiplicate(int mul);
    Money div(int del);
    //Money mod(int del);

    bool operator> (const Money& newCash);//перегрузка операторов сравнения
    bool operator< (const Money& newCash);
    bool operator== (const Money& newCash);
    bool operator!= (const Money& newCash);
    Money& operator=(const Money& cash);

    friend std::ostream& operator<<(std::ostream& os, const Money& money);//перегрузка операторов << и >>
    friend std::istream& operator>>(std::istream& is, Money& money);
};


