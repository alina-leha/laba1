#pragma once
#include <iostream>

class String
{
private:
	// ������ ������ �� ���������
	const int DEFAULT_BUF_SIZE = 32;
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
	// ����������
	~String();
};

