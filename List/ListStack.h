#pragma once
#include <iostream>
using namespace std;

struct Node {
	int value;
	struct Node* next;
};

class ListStack {
	Node* head;
	Node* tail;
	enum { empty = -1, full = 5 };
	int top = 0;
	Node* stack[full];
public:
	ListStack() {
		head = nullptr;
		tail = nullptr;
	}
	// добавление узла в конец списка
	/*void createNode(int val) {
		Node* temp = new Node;
		temp->value = val;
		temp->next = nullptr;

		if (head == nullptr) {
			head = temp;
			tail = temp;
		}
		else {
			tail->next = temp;
			tail = temp;
		}
	}*/
	// отображение узлов списка
	void printList() {
		Node* current = head;
		if (head == nullptr) {
			std::cout << "!!!!!!";
		}
		while (current != nullptr) {
			cout << current->value << endl;
			current = current->next;
		}
	}
	// вставка в начало списка
	void Push(int val) {
		Node* new_Node = new Node;

		new_Node->value = val;
		new_Node->next = head;

		head = new_Node;
		if (!IsFull()) {
			stack[top++] = new_Node;
		}
		else {
			static_cast<int>(full) + 1;
			stack[top++] = new_Node;
		}
	}
	// вставка узла в орпеделенную позицию
	//void insertNodeAtPosition(int pos, int val) {
	//	Node* pre = nullptr; // предыдущий узел
	//	Node* current = nullptr; // следующий узел
	//	Node* temp = new Node; // новый узел
	//	
	//	current = head;

	//	for (int i = 1; i < pos; i++) {
	//		pre = current;
	//		current = current->next;
	//	}
	//	temp->value = val;
	//	pre->next = temp;
	//	temp->next = current;
	//}


	// удаление первого элемента
	int pop() {
		int retVal = 0;
		Node* next_node = nullptr;

		next_node = head->next;
		retVal = head->value;
		delete head;
		head = next_node;
		top--;
		return retVal;
	}
	bool IsEmpty() { return top = empty; }
	bool IsFull() { return top == full; };
	void Clear() {
		Node* temp = head;
		while (temp != nullptr)
		{
			temp = temp->next;
			delete head;
			head = temp;
		}
	}
};