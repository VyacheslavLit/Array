#include "IntArray.h"
#include "Function.h"
#include <iomanip>

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	short choice;
	int  insert_index;
	int lenPrint;
	int index = 0;
	while (true) {
		try {
			index = creatingIndex();
		}
		catch (exception& e) {
			cout << e.what() << endl;
			system("pause");
			continue;
		}
		break;
	}
	IntArray arr(index);
	IntArray copyArr(1);
	for (int i = 0; i < index; i++)
		arr[i] = i + 1;
	while (true) {
		system("cls");
		menu();
		cin >> choice;
		if (cin.fail() || choice < 0 || choice>6) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Выбор не определен, повторите попытку.\n";
			system("pause");
			continue;
		}
		if (choice == 1) {
			copyArr.resize(arr.getLength());
			for (int i = 0; i < copyArr.getLength(); i++) copyArr[i] = arr[i];
			cout << "Копия создана" << endl;
		}
		if (choice == 3)
		{
			arr.insertAtBeginning(insertMean(1));
			arr.insertAtEnd(insertMean(2));
		}
		try {
			if (choice == 2)
			{
				insert_index = insertIndex(arr.getLength(), 2);
				cout << "\nВ ячейке с индексом: " << insert_index + 1 << " число: " << arr[insert_index] << endl;
			}
			if (choice == 4) arr.insertBefore(insertMean(0), insertIndex(arr.getLength()+1, 4));
			if (choice == 5) arr.remove(insertIndex(arr.getLength(), 5));
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
		if (choice == 6) {
			if (copyArr.getLength() > arr.getLength()) {
				lenPrint = copyArr.getLength();
			} else lenPrint = arr.getLength();

			cout << setw(12) << "Порядковый" << setw(12) << "Основной" << setw(12) << "Контейнер\n" << setw(12) << "номер" << setw(12) << "контейнер" << setw(12) << "копия\n";
			for (int i = 0; i < lenPrint; i++) {
				cout << setw(12) << i+1;
				if (i < arr.getLength())
				{
					cout << setw(12) << arr[i];
				} else cout << setw(12) << ' ';
				if (i < copyArr.getLength())
				{
					cout << setw(12) << copyArr[i]<<endl;
				} else cout << endl;
			}
		}
		if (choice == 0) return 0;
		system("pause");
	}
	return 0;
}