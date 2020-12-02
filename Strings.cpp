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
    cout << "\nТестирование завершено!\n";
}
