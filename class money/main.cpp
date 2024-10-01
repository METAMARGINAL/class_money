#include<iostream>
#include "Money.h"

using namespace std;

//������, ������ ���� ���������������� � ������� ������������ �� ���������, �� �������� ����
//�������� * �� ��������� � ������� ����

void PrintMenu() {
    cout << "1 - ��������� ������� ������� ������" << endl;
    cout << "2 - �������� ���� ������" << endl;
    cout << "3 - �������� ������� � ������� ������" << endl;
    cout << "4 - ����� �� ������� ����� �� �����" << endl;
    //cout << "5 - ������� �� ������� ����� �� �����" << endl;
    cout << "5 - �������� ����� ����� �� �����" << endl;
    cout << "6 - ������ ������" << endl;
    cout << "0 - ���������� ���������" << endl;
}

int main() {
    setlocale(LC_ALL, "ru");
    Money cash1;
    Money cash2;
    Money result;

    int del = 1;
    int num = 0;
    int way = 0;

    cout << "������� ���������� ������� ����� (����� � �������)" << endl;
    cin >> cash1;
    cout << "������� ���������� ������� ����� (����� � �������)" << endl;
    cin >> cash2;


    while (way != -1)
    {
        PrintMenu();
        cin >> way;

        switch (way)
        {
        case 1:
            if (cash1 > cash2) {
                cout << "������ ���� ������ �������" << endl;
            }
            else {
                if (cash1 == cash2) {
                    cout << "����� �����" << endl;
                }
                else {
                    cout << "������ ���� ������ �������" << endl;
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

            cout << "������� ����� �� ������� �� ������ ��������� ����\n";
            cin >> del;
            cout << "����� �� ���� ������ �� ������ ��������� �� ��� �����?\n";
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

        //    cout << "������� ����� �� ������� �� ������ ��������� ����\n";
        //    cin >> del;
        //    cout << "����� �� ���� ������ �� ������ ��������� �� ��� �����?\n";
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
            cout << "������� ����� �� ������� �� ������ �������� ����\n";
            cin >> del;
            cout << "����� �� ���� ������ �� ������ �������� �����?\n";
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
            cout << "����� �� ���������" << endl;
            way = -1;
            break;
        default:
            cout << "������ ������������ �����" << endl;
            break;
        }
    }
}
