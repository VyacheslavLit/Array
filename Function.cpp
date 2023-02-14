#include "IntArray.h"
#include "Function.h"

void menu() {
	cout << "Выберите раздел:\n\n";
	cout << "1. Скопировать контейнер. \n";
	cout << "2. Получить доступ к любому элементу контейнера по индексу. \n";
	cout << "3. Вставка в начало и в конец контейнера\n";
	cout << "4. Вставить элемент в контейнер произвольно.\n";
	cout << "5. Удалить элемент из контейнера.\n";
	cout << "6. Печать контейнера.\n";
	cout << "0. Выход.\n";
}
int creatingIndex() {
	int index;
	while (true) {
		system("cls");
		cout << "\nОпределите размер контейнера (до 1000): ";
		cin >> index;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Выбор не определен, повторите попытку.\n";
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
		cout << "Введите индекс массива";
		if (a == 2)	cout << ", для посмотра значения ";
		if (a == 4) cout << ", куда желаете сделать вставку ";
		if (a == 5)cout << ", для удаления ";
		cout <<"(от 1 до " << length << ") : ";
		cin >> index;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Выбор не определен, повторите попытку.\n";
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
		cout << "Введите значение для вставки";
		if (a == 1) cout << " в начало контейнера";
		if (a == 2) cout << " в конец контейнера";
		cout << ": ";
		cin >> mean;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Выбор не определен, повторите попытку.\n";
			system("pause");
			continue;
		}
		return mean;
	}
}