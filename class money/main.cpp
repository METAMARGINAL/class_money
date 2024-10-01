#include<iostream>
#include "Money.h"

using namespace std;

//Вопрос, почему если инициализировать с помощью конструктора по умолчанию, то приходит беда
//Оператор * не работаеот с классом мани

void PrintMenu() {
    cout << "1 - сравнение первого второго счетов" << endl;
    cout << "2 - сложение двух счетов" << endl;
    cout << "3 - разность первого и второго счетов" << endl;
    cout << "4 - целое от деления счета на число" << endl;
    //cout << "5 - остаток от деления счета на число" << endl;
    cout << "5 - умножить сумму счета на число" << endl;
    cout << "6 - Печать счетов" << endl;
    cout << "0 - Завершение программы" << endl;
}

int main() {
    setlocale(LC_ALL, "ru");
    Money cash1;
    Money cash2;
    Money result;

    int del = 1;
    int num = 0;
    int way = 0;

    cout << "Введите содержание первого счета (рубли и копейки)" << endl;
    cin >> cash1;
    cout << "Введите содержание второго счета (рубли и копейки)" << endl;
    cin >> cash2;


    while (way != -1)
    {
        PrintMenu();
        cin >> way;

        switch (way)
        {
        case 1:
            if (cash1 > cash2) {
                cout << "Первый счет больше второго" << endl;
            }
            else {
                if (cash1 == cash2) {
                    cout << "Счета равны" << endl;
                }
                else {
                    cout << "Первый счет меньше второго" << endl;
                }
            }
            break;
        case 2:
            result = cash1 + cash2;
            cout << result << endl;
            break;
        case 3:
            result = cash1 - cash2;
            cout << result << endl;
            break;

        case 4:

            cout << "Введите число на которое вы хотите разделить счет\n";
            cin >> del;
            cout << "Какой из двух счетов вы хотите разделить на это число?\n";
            cin >> num;
            switch (num)
            {
            case 1:
                result = cash1.div(del);
                cout << result << endl;
                break;
            case 2:
                result = cash2.div(del);
                cout << result << endl;
                break;
            default:
                break;
            }
            break;

        //case 5:

        //    cout << "Введите число на которое вы хотите разделить счет\n";
        //    cin >> del;
        //    cout << "Какой из двух счетов вы хотите разделить на это число?\n";
        //    cin >> num;
        //    switch (num)
        //    {
        //    case 1:
        //        result = cash1.mod(num);
        //        cout << result << endl;
        //        break;
        //    case 2:
        //        result = cash1.mod(num);
        //        cout << result << endl;
        //        break;
        //    default:
        //        break;
        //    }
        //    break;

        case 5:
            cout << "Введите число на которое вы хотите умножить счет\n";
            cin >> del;
            cout << "Какой из двух счетов вы хотите умножить число?\n";
            cin >> num;
            switch (num)
            {
            case 1:
                result = cash1.multiplicate(del);
                cout << result << endl;
                break;
            case 2:
                result = cash2.multiplicate(del);
                cout << result << endl;
                break;
            default:
                break;
            }
            break;

        case 6:
            cout << cash1 << endl;
            cout << cash2 << endl;
            break;
        case 0:
            cout << "Выход из программы" << endl;
            way = -1;
            break;
        default:
            cout << "Введен неккоректный ответ" << endl;
            break;
        }
    }
}
