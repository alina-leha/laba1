#pragma once
#include <iostream>

class String
{
private:
	// ������ ������ �� ���������
	static const int DEFAULT_BUF_SIZE = 32;
	// ������, � ������� �������� ������
	char* string;
	// ������� �������� � ������ ������ 
	// ����� ��������� ������
	int bufSize;
	// ����� ������
	int length;
	// ���������� ����� �� ������ ������
	static int stringsNum;
	// ��������� src � dst, ������� � index.
	// ��������������, ��� � dst �������� ���������� �����
	void insertTo(char* dst, int dstLen, 
		const char* src, int srcLen, int index);
	// �������, ������� ����� ����� �������� ��� �������� 
	// ������ ��������� �����
	int countBufSize(int charsToAddCount);
public:
	// ����������� �� ���������
	String();
	// ����������� �����������
	String(const String& str);
	// �����������. bufSize - ����������� ������ ������
	String(int bufSize);
	// �����������, ��������� ������ �� ��������� const char*
	String(const char* str);
	// ���� ������������ ��������� ������ � ������, 
	// �� ���������� ������ �������� ���������. 
	// ����� ���������� -1
	int indexOf(const char* str);
	// ��������� � ������ ���������
	void add(const char* str);
	// �������� ������ � �������� �������� ����� ��������.
	// ���������� false, ���� ������ � ����� �������� �����������
	bool replace(int index, char c);
	// ��������� ��������� �� ���������� �������.
	// ���������� false, ���� ������ ����������� � ������� ������
	bool insert(int index, const char* str);
	// ������� ������ �� �����
	void print();
	// ���������� ������� ����� ������
	int getLength();
	// ���������� ���������� ������������ 
	// �� ������ ������ ����� � ���������
	static int getStringsNum();
	// �������� ������������
	String& operator=(const String& str);
	// ����������
	~String();
	// �������� String + String
	friend String operator+(const String& str1, const String& str2);
	// �������� const char* + String
	friend const char* operator+(const char* str1, const String& str2);
	// �������� String + const char*
	friend String operator+(const String& str1, const char* str2);
	// �������� String > String
	friend bool operator>(const String& str1, const String& str2);
	// �������� String < String
	friend bool operator<(const String& str1, const String& str2);
	// �������� String >= String
	friend bool operator>=(const String& str1, const String& str2);
	// �������� String <= String
	friend bool operator<=(const String& str1, const String& str2);
	// �������� String == String
	friend bool operator==(const String& str1, const String& str2);
	// �������� String != String
	friend bool operator!=(const String& str1, const String& str2);
};

