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
		cout << (*current).data << " ";
		current = (*current).next;
	}
	cout << endl;
}

int main()
{
	DoulbyLinkedList list;
}


