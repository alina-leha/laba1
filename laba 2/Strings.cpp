#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include "String.h"
using namespace std;

// Тестирование конструктора по умолчанию String()
String testDefaultConstructor()
{
    String str;
    cout << "\nСтрока создана!\n";
    cout << "Строка: ";
    str.print();
    cout << "\nДлина строки: " << str.getLength();
    return str;
}

// Тестирование String(const String& str)
String testCopyConstructor()
{
    cout << "\nВведите строку. На основании её будет "
        << "создана новая строка, а первая строка будет удалена.\n";
    string temp;
    getline(cin, temp);
    String* str1 = new String(temp.c_str());
    cout << "\nПервая строка создана! Количество строк в данный момент: "
        << String::getStringsNum();
    String str2(*str1);
    cout << "\nВызван конструктор копирования, вторая строка создана! "
        << "Количество строк в данный момент: " << String::getStringsNum();
    delete str1;
    cout << "\nПервая строка удалена! Количество строк в данный момент: "
        << String::getStringsNum();
    cout << "\nВведённая строка: ";
    str2.print();
    cout << "\nДлина строки: " << str2.getLength();
    return str2;
}

// Тестирование String(int bufSize)
String testBufSizeConstructor()
{
    cout << "\nВведите изначальный размер буфера, "
        << "с которым будет создана строка: ";
    string bufSizeStr = "";
    int bufSize = 0;
    bool entered = false;
    bool wasEnter = false;
    do
    {
        if (!wasEnter)
            wasEnter = true;
        else
            cout << "Введите, пожалуйста, целое число больше нуля: ";
        getline(cin, bufSizeStr);
        entered = true;
        for (unsigned int i = 0; i < bufSizeStr.length() && entered; i++)
        {
            if (bufSizeStr[i] < '0' || bufSizeStr[i] > '9')
                entered = false;
        }
        if (entered)
        {
            bufSize = stoi(bufSizeStr);
            if (bufSize <= 0)
                entered = false;
        }
    } while (!entered);
    String str(bufSize);
    cout << "\nСтрока создана!\n";
    cout << "Строка: ";
    str.print();
    cout << "\nДлина строки: " << str.getLength();
    return str;
}

// Тестирование String(const char* str)
String testCharPtrConstructor()
{
    cout << "\nВведите строку. На основании её будет создан объект String.\n";
    string temp;
    getline(cin, temp);
    String str(temp.c_str());
    cout << "\nСтрока создана!\n";
    cout << "Строка: ";
    str.print();
    cout << "\nДлина строки: " << str.getLength();
    return str;
}

// Выводит пользователю сообщение о вводе 
// любой клавиши и дожидается ввода
void pressAnyKey()
{
    cout << "\nНажмите любую клавишу для перехода "
        << "к следующему пункту тестирования...";
    _getch();
}

// Меню выбора тестирования конструктора
String testConstructor()
{
    cout << "1. Тестирование конструктора\n\n";
    cout << "Какой конструктор Вы хотите использовать?\n";
    cout << "1 — Конструктор по умолчанию\n";
    cout << "2 — Конструктор копирования\n";
    cout << "3 — Конструктор с заданием изначального размера буфера\n";
    cout << "4 — Конструктор, создающий объект из const char*\n";
    string option = "";
    bool optionEntered = false;
    do
    {
        if (!optionEntered)
            optionEntered = true;
        else
            cout << "Введите, пожалуйста, цифру от 1 до 4: ";
        getline(cin, option);
    } while (option != "1" && option != "2" 
        && option != "3" && option != "4");
    switch (stoi(option))
    {
    case 1:
        return testDefaultConstructor();
    case 2:
        return testCopyConstructor();
    case 3:
        return testBufSizeConstructor();
    case 4:
        return testCharPtrConstructor();
    }
}

// Тестирование метода добавления подстроки в конец строки
void testAdd(String& str)
{
    system("cls");
    cout << "2. Тестирование метода добавления подстроки в конец строки."
        << "\n\nТекущая строка: ";
    str.print();
    cout << "\nДлина строки: " << str.getLength()
        << "\nВведите любую подстроку. Она будет "
        << "добавлена в конец текщуей строки: ";
    string substr;
    getline(cin, substr);
    str.add(substr.c_str());
    cout << "\n\nПодстрока добавлена!"
        << "\nТекущая строка: ";
    str.print();
    cout << "\nДлина строки: " << str.getLength();
    pressAnyKey();
}

// Тестирование метода замены символа в строке
void testReplace(String& str)
{
    system("cls");
    cout << "3. Тестирование метода замены символа в строке."
        << "\n\nТекущая строка: ";
    str.print();
    cout << "\nДлина строки: " << str.getLength()
        << "\nВведите индекс символа, который должен быть заменён: ";
    int index = -1;
    string indexStr = "";
    bool entered = false;
    bool wasEnter = false;
    do
    {
        if (!wasEnter)
            wasEnter = true;
        else
        {
            cout << "\nВведите целое число от 0 до " 
                << str.getLength() - 1 << ": ";
        }
        getline(cin, indexStr);
        entered = true;
        for (unsigned int i = 0; i < indexStr.length() && entered; i++)
        {
            if (indexStr[i] < '0' || indexStr[i] > '9')
                entered = false;
        }
        if (entered)
        {
            index = stoi(indexStr);
            if (index < 0 && index >= str.getLength())
                entered = false;
        }
    } while (!entered);
    cout << "Введите символ, который Вы "
        << "хотите установить по данному индексу: ";
    string temp = "";
    getline(cin, temp);
    char c;
    if (temp == "")
        c = ' ';
    else
        c = temp[0];
    str.replace(index, c);
    cout << "\n\nСимвол изменён!"
        << "\nТекущая строка: ";
    str.print();
    cout << "\nДлина строки: " << str.getLength();
    pressAnyKey();
}

// Тестирование метода вставки подстроки в строку
void testInsert(String& str)
{
    system("cls");
    cout << "4. Тестирование метода вставки подстроки в строку."
        << "\n\nТекущая строка: ";
    str.print();
    cout << "\nДлина строки: " << str.getLength()
        << "\nВведите индекс начала вставки: ";
    int index = -1;
    string indexStr = "";
    bool entered = false;
    bool wasEnter = false;
    do
    {
        if (!wasEnter)
            wasEnter = true;
        else
        {
            cout << "\nВведите целое число от 0 до "
                << str.getLength() - 1 << ": ";
        }
        getline(cin, indexStr);
        entered = true;
        for (unsigned int i = 0; i < indexStr.length() && entered; i++)
        {
            if (indexStr[i] < '0' || indexStr[i] > '9')
                entered = false;
        }
        if (entered)
        {
            index = stoi(indexStr);
            if (index < 0 && index >= str.getLength())
                entered = false;
        }
    } while (!entered);
    cout << "Введите подстроку, которую "
        << "Вы хотите вставить по заданному индексу: ";
    string substr;
    getline(cin, substr);
    str.insert(index, substr.c_str());
    cout << "\n\nПодстрока вставлена!"
        << "\nТекущая строка: ";
    str.print();
    cout << "\nДлина строки: " << str.getLength();
    pressAnyKey();
}

// Тестирование метода поиска подстроки в строке
void testIndexOf(String& str)
{
    system("cls");
    cout << "5. Тестирование метода поиска подстроки в строке."
        << "\n\nТекущая строка: ";
    str.print();
    cout << "\nДлина строки: " << str.getLength()
        << "\nВведите любую подстроку. "
        << "Если она присутсвтует в текущей строке, то "
        << "Вы узнаете индекс начала первого вхождения.\n";
    string substr;
    getline(cin, substr);
    int index = str.indexOf(substr.c_str());
    if (index != -1)
        cout << "\nИндекс первого вхождения подстроки в строку: " << index << ".\n";
    else
        cout << "\nПодстрока не найдена.\n";
    pressAnyKey();
}

// Тестирование операторов присваивания и сложения
void testAssignAdd(String& str)
{
    system("cls");
    cout << "6. Тестирование операторов \"+\" и \"=\"."
        << "\n\nТекущая строка: ";
    str.print();
    cout << "\nДлина строки: " << str.getLength()
        << "\nВведите ещё одну строку. Она будет объединена с текущей "
        << "при помощи оператора \"+\" и присвоена ей "
        << "при помощи оператора \"=\".\n";
    string str2;
    getline(cin, str2);
    str = str + String(str2.c_str());
    cout << "Строки успешно объединены! \nТекущая строка: ";
    str.print();
    cout << "\nДлина строки: " << str.getLength();
    cout << "\nТеперь введите ещё одну строку. "
        << "Она будет сохранена в char*, к которому будет присоединена "
        << "текущая строка. Результат Вы увидите на экране.\n";
    string str3StdString;
    getline(cin, str3StdString);
    const char* str3 = str3StdString.c_str();
    str3 = str3 + str;
    cout << "\nСтроки успешно объединены! "
        << "Получившаяся строка (хранится в char*):\n" << str3
        << "\nВведите ещё одну строку. На основании неё будет создан "
        << "новый объект String. К нему будет присоединена последняя "
        << "сформированная строка. Результат будет присвоен основной "
        << "строке при помощи оператора присваивания.\n";
    string str4StdString;
    getline(cin, str4StdString);
    String str4(str4StdString.c_str());
    str = str4 + str3;
    cout << "\nОбъединение строк произведено успешно!"
        << "\nТекущая строка: ";
    str.print();
    cout << "\nДлина строки: " << str.getLength();
    pressAnyKey();
}

// Тестирование операторов сравнения
void testComparison()
{
    system("cls");
    cout << "7. Тестирование операторов сравнения.";
    cout << "\n\nВведите строку: \n";
    string str1StdString;
    getline(cin, str1StdString);
    String str1(str1StdString.c_str());
    cout << "\nНовый объект String создан!"
        << "\nДлина Строки1: " << str1.getLength()
        << "\n\nВведите вторую строку. Она будет сравнена с первой "
        << "всеми перегруженными операторами сравнения.\n";
    string str2StdString;
    getline(cin, str2StdString);
    String str2(str2StdString.c_str());
    cout << "\nНовый объект String создан!"
        << "\nДлина Строки2: " << str1.getLength();
    cout << boolalpha;
    cout << "\n\nСтрока1 > Строка2 : " << (str1 > str2)
        << "\nСтрока1 < Строка2 : " << (str1 < str2)
        << "\nСтрока1 == Строка2 : " << (str1 == str2)
        << "\nСтрока1 != Строка2 : " << (str1 != str2)
        << "\nСтрока1 >= Строка2 : " << (str1 >= str2)
        << "\nСтрока1 <= Строка2 : " << (str1 <= str2);
}

int main() 
{
    // Включение русского языка в консоли
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    String str = testConstructor();
    pressAnyKey();
    testAdd(str);
    testReplace(str);
    testInsert(str);
    testIndexOf(str);
    testAssignAdd(str);
    testComparison();
    cout << "\nТестирование завершено!\n";
}
