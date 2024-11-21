#include <iostream>
#include <string>
#include "FileFunctions.h"
#include "DoublyLinkedList.h"
#include "Deposit.h"

using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "ru_RU.UTF-8");
	string file_name = argv[1];
	DoublyLinkedList list;
	vector<Deposit> data = read_data(file_name);
	for (int i = 0; i < data.size(); i++)
	{
		push_back(list, data[i]);
	}
	cout << "Исходный список:" << endl;
	print_list(list);
	sort_by_name(list);
	cout << "Отсортированный список:" << endl;
	print_list(list);
}

