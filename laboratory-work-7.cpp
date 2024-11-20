#include <iostream>
#include <string>

using namespace std;

struct Node
{
	string data;
	Node* next;
	Node* prev;
};
struct DoulbyLinkedList
{
	Node* head = nullptr;
	Node* tail = nullptr;
};

Node* createNode(string value)
{
	Node* newNode = new Node;
	(*newNode).data = value;
	(*newNode).next = nullptr;
	(*newNode).prev = nullptr;
	return newNode;
}

void push_back(DoulbyLinkedList& list, string value)
{
	Node* newNode = createNode(value);
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


int main()
{
	DoulbyLinkedList list;
}


