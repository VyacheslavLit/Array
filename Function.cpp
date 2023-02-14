#include "IntArray.h"
#include "Function.h"

void menu() {
	cout << "�������� ������:\n\n";
	cout << "1. ����������� ���������. \n";
	cout << "2. �������� ������ � ������ �������� ���������� �� �������. \n";
	cout << "3. ������� � ������ � � ����� ����������\n";
	cout << "4. �������� ������� � ��������� �����������.\n";
	cout << "5. ������� ������� �� ����������.\n";
	cout << "6. ������ ����������.\n";
	cout << "0. �����.\n";
}
int creatingIndex() {
	int index;
	while (true) {
		system("cls");
		cout << "\n���������� ������ ���������� (�� 1000): ";
		cin >> index;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "����� �� ���������, ��������� �������.\n";
			system("pause");
			continue;
		}
		
		if (index <= 0 || index > 1000) {
			throw Bad_Length();
		}
		return index;
	}
}
int insertIndex(int length, short a) 
{ 
	int index;
	while (true)
	{
		system("cls");
		cout << "������� ������ �������";
		if (a == 2)	cout << ", ��� �������� �������� ";
		if (a == 4) cout << ", ���� ������� ������� ������� ";
		if (a == 5)cout << ", ��� �������� ";
		cout <<"(�� 1 �� " << length << ") : ";
		cin >> index;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "����� �� ���������, ��������� �������.\n";
			system("pause");
			continue;
		}
		if (index < 1 || index > length) {
			throw Bad_Range();
		}
		return index-1;
	}
}
int insertMean(short a) 
{
	int mean;
	while (true)
	{
		system("cls");
		cout << "������� �������� ��� �������";
		if (a == 1) cout << " � ������ ����������";
		if (a == 2) cout << " � ����� ����������";
		cout << ": ";
		cin >> mean;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "����� �� ���������, ��������� �������.\n";
			system("pause");
			continue;
		}
		return mean;
	}
}