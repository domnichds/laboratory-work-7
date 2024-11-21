#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <locale>
#include <Windows.h>

using namespace std;

struct Deposit
{
	string name;
	int summ;
	string currency;
	double percent;
};

struct Node {
	Deposit data;
	Node* next;
	Node* prev;
};

struct DoulbyLinkedList
{
	Node* head = nullptr;
	Node* tail = nullptr;
};

Node* createNode(Deposit data)
{
	Node* newNode = new Node;
	(*newNode).data = data;
	(*newNode).next = nullptr;
	(*newNode).prev = nullptr;
	return newNode;
}

void push_back(DoulbyLinkedList& list, Deposit data)
{
	Node* newNode = createNode(data);
	if (list.tail == nullptr)
	{
		list.head = newNode;
		list.tail = newNode;
	}
	else
	{
		(*list.tail).next = newNode;
		(*newNode).prev = list.tail;
		list.tail = newNode;
	}
}

void swap_node(DoulbyLinkedList& list, Node* node1, Node* node2)
{
	if (node1 == nullptr || node2 == nullptr || node1 == node2)
	{
		return;
	}
	else
	{
		if ((*node1).next == node2)
		{

			Node* prev1 = (*node1).prev;
			Node* next2 = (*node2).next;

			if (prev1 != nullptr) { (*prev1).next = node2; }
			if (next2 != nullptr) { (*next2).prev = node1; }

			(*node2).prev = prev1;
			(*node2).next = node1;
			(*node1).next = next2;
			(*node1).prev = node2;
		}
		else if ((*node2).next == node1)
		{

			Node* prev2 = (*node2).prev;
			Node* next1 = (*node1).next;

			if (prev2 != nullptr) { (*prev2).next = node1; }
			if (next1 != nullptr) { (*next1).prev = node2; }

			(*node1).prev = prev2;
			(*node1).next = node2;
			(*node2).prev = node1;
			(*node2).next = next1;
		}
		else
		{
			Node* prev1 = (*node1).prev;
			Node* next1 = (*node1).next;
			Node* prev2 = (*node2).prev;
			Node* next2 = (*node2).next;

			if (prev1 != nullptr) { (*prev1).next = node2; }
			if (next1 != nullptr) { (*next1).prev = node2; }

			(*node2).prev = prev1;
			(*node2).next = next1;

			if (prev2 != nullptr) { (*prev2).next = node1; }
			if (next2 != nullptr) { (*next2).prev = node1; }

			(*node1).prev = prev2;
			(*node1).next = next2;
 		}

		if (list.head == node1) { list.head = node2; }
		else if (list.head == node2) { list.head = node1; }

		if (list.tail == node1) { list.tail = node2; }
		else if (list.tail == node2) { list.tail = node1; }
	}
}

void print_list(DoulbyLinkedList& list)
{
	Node* current = list.head;
	while (current != nullptr)
	{
		cout << "----------------------------------------" << endl;
		cout << (*current).data.name << endl;
		cout << (*current).data.summ << endl;
		cout << (*current).data.currency << endl;
		cout << (*current).data.percent << endl;
		current = (*current).next;
	}
	cout << endl;
}

void sort_by_name(DoulbyLinkedList& list)
{
	if (list.head == nullptr || (*list.head).next == nullptr)
	{
		return;
	}

	Node* current = (*list.head).next;

	while (current != nullptr)
	{

		Node* nextNode = (*current).next;
		Node* compareNode = (*current).prev;

		while (compareNode != nullptr && (*compareNode).data.name > (*current).data.name)
		{
			swap_node(list, compareNode, current);
			compareNode = (*current).prev;
		}

		current = nextNode;
	}
}

vector<Deposit> read_data(string file_name)
{
	vector<Deposit> result;
	string line;
	ifstream inFile(file_name);
	if (inFile)
	{
		while (getline(inFile, line))
		{
			Deposit currentDeposit;
			string currentLine;
			stringstream ss(line);
			int counter = 0;
			while (getline(ss, currentLine, ';'))
			{
				if (counter == 0) { currentDeposit.name = currentLine; }
				else if (counter == 1) { currentDeposit.summ = stoi(currentLine); }
				else if (counter == 2) { currentDeposit.currency = currentLine; }
				else if (counter == 3) 
				{
					stringstream fl(currentLine);
					double p;
					fl >> p;
					currentDeposit.percent = p; 
				}
				counter++;
			}
			result.push_back(currentDeposit);
		}
		return result;
	}
	else
	{
		return result;
	}
}


int main()
{
	setlocale(LC_ALL, "ru_RU.UTF-8");
	DoulbyLinkedList list;
}

