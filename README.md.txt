#include <iostream>
#include <new>
#include <cstring>
#include <cstdlib>
#include <string>
#include <iostream>
#pragma warning(disable: 4996)


using namespace std;

class Strings
{
private:
	int amount;//���������� ����� ������
	static int length;//����� �����

	int x;  //��� ������ ������������� �������� �������� searchStr()

	int varNumber;//����� ������, ������� ������������ ������� ������� �� �����
	bool varConcat;//����� ������������ (���������� ������ ��� ���)

	//��������� �� ������ �����, ������� ����� ����������� �������������
	char* str1;
	char* str2;
	char* str3;
	char* strSearch;//��� ������ �������� ������
	char* strConcat;//��� ������ ���� ��������� ����� � ���� ������

public:
	Strings()//���������� ����� � ������������ ����� �����
	{
		amount = 3;//����������
		
	}


	int searchStr()//�����, ������� ���������� ������� � ������ ����� �������� ������
	{
		//������ strSearch � ��� ��������� ����� ������ � ������ setString()
		//��� �� � ����� ������ ������ ����� searchStr()
		if (strcmp(strSearch, str1) == 0) return 1;// ������� strcmp ������� ��� ������ � ������ 0, ���� ��� ���������
		else if (strcmp(strSearch, str2) == 0) return 2;
		else if (strcmp(strSearch, str3) == 0) return 3;
		else return -1;
	}

	void setString()// ������� ������, � �������� �������;
	{
		str1 = new char[length];//�������� ������ ��� ����� �� 30-�� �������� � ���� ������ ��� '\0'
		str2 = new char[length];
		str3 = new char[length];
		strSearch = new char[length];
		strConcat = new char[length * amount];//�������� ������ ��� ������, � ������� ����� �������� ��� ��������� ������������� ������

		for (int i = 0; i < length; i++)//�������� ��� ������ ��������� \0, ����� �������� ������ �� �������� �������� � �������
		{
			str1[i] = '\0';
			str2[i] = '\0';
			str3[i] = '\0';
			strSearch[i] = '\0';
		}

		for (int i = 0; i < length * amount; i++)//�������� ������ ��������� \0
		{
			strConcat[i] = '\0';
		}

		cout << "������� ��� ������ (���������)." << endl;
		for (int i = 0; i < amount; i++)
		{
			cout << "������� ������ �" << i + 1 << " (�� ����� 30-�� ��������): ";
			if (i == 0)cin.getline(str1, length);
			if (i == 1)cin.getline(str2, length);
			if (i == 2)  cin.getline(str3, length);
		}

		cout << "������� ������, ����� ������� ������ ����� (�� ����� 30-�� ��������): ";
		cin.getline(strSearch, length);

		x = searchStr();//�������� ���������� � ��������, ������� ������ ������� searchStr()
		if (x == 1) cout << "\n����� ��������� ���� ������ � ������ ����� = 1" << endl;
		else if (x == 2) cout << "\n����� ��������� ���� ������ � ������ ����� = 2" << endl;
		else if (x == 3) cout << "\n����� ��������� ���� ������ � ������ ����� = 3" << endl;
		else cout << "\n������ �� �������!!!\n\n";
	}

	void getString()//����� ����� �� �����
	{
		cout << "\n\n";
		cout << "���� �� ������ ���������� ��� ������ - ������� 0.";
		cout << "\n���� �� ������ ������� �� ����� ���������� ������, ������� �� ����� (1, 2 ��� 3): ";
		cin >> varNumber;

		cout << "\n\n";
		if (varNumber == 1) cout << "������ 1:   " << str1 << endl << endl;
		else if (varNumber == 2) cout << "������ 2:   " << str2 << endl << endl;
		else if (varNumber == 3) cout << "������ 3:   " << str3 << endl << endl;
		else//� ������ ������ ���� ������������ ���� 0
		{
			cout << "������ 1:   " << str1 << endl << endl;
			cout << "������ 2:   " << str2 << endl << endl;
			cout << "������ 3:   " << str3 << endl << endl;
		}

	}

	void searchString()
	{		
		string sub;
		cout << "\n\n";
		cout << "\n������� ����� ������ � ���������: ";
		cin >> varNumber;
		cin >> sub;
        size_t n = 0, from = 0;
		cout << "\n\n";
		string n1 = str1;
		string n2 = str2;
		string n3 = str3;

		if (varNumber == 1) {
			while ((n = n1.find(sub, from)) != string::npos) {
				cout << n << " ";
				from = n + sub.size();
			}
			cout << "������ 1:   " << str1 << endl << endl;
		}
		else if (varNumber == 2) {
			while ((n = n2.find(sub, from)) != string::npos) {
				cout << n << " ";
				from = n + sub.size();
			}
			cout << "������ 2:   " << str2 << endl << endl;
		}
		else if (varNumber == 3) {
			while ((n = n3.find(sub, from)) != string::npos) {
				cout << n << " ";
				from = n + sub.size();
			} cout << "������ 3:   " << str3 << endl << endl;
		}
				
	}

	

	void concat()//����� ����������� �����;
	{
		cout << "\n���� �� ������ ���������� ��� ������, ������� - 1. ���� ���, ������� - 0: ";
		cin >> varConcat;
		if (!varConcat) cout << "������ �� ����� ����������!" << endl;//���� varConcat = 0(����)
		else //���� varConcat = 1
		{
			strcat(strConcat, str1);
			strcat(strConcat, str2);
			strcat(strConcat, str3);
			cout << "������������ ������:   " << strConcat << endl << endl;//���� ������������ ����� ��������� ������, ������� �� ����� �������
		}
	}

	void change()//��������� ����� 
	{
		
		int n;
		char m;
		cout << "\n\n";		
		cout << "\n������� ����� ������, ����� ������, ������� ������ ��������, � ������ (1, 2 ��� 3): ";
		cin >> varNumber;
		cin >> n >> m;

		cout << "\n\n";
		if (varNumber == 1) {
			str1[n-1] = m;
			cout << "������ 1:   " << str1 << endl << endl; }
		else if (varNumber == 2) {
			str2[n-1] = m;
			cout << "������ 2:   " << str2 << endl << endl;
		}
		else if (varNumber == 3) {
			str3[n-1] = m; cout << "������ 3:   " << str3 << endl << endl;
		}
		else//� ������ ������ ���� ������������ ���� 0
		{
			cout << "������ 1:   " << str1 << endl << endl;
			cout << "������ 2:   " << str2 << endl << endl;
			cout << "������ 3:   " << str3 << endl << endl;
		}

	}
	

	void del()//����� ������� ������ �� ���������� ������ ���������
	{
		delete strConcat;
		delete strSearch;
		delete str3;
		delete str2;
		delete str1;
	}
};

int Strings::length = 31;//������������ �����

int main()
{
	setlocale(LC_ALL, "rus");

	Strings strings;//������� ������

	strings.setString();//�������� ����� ������� ����� � ������� ����� ���������� ����� ��������� �����

	strings.getString();// ����� ����� �� �����

	strings.concat();// ����� ������������ (������������ �������� ���������� ������ ��� ���)

	strings.change();//��������� ����� 

	strings.searchString();//����� ���������

	strings.del();//������ ������

	return 0;
}