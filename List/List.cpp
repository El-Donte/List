#include "list.h"

List::~List() {
	node* temp = head;
	while (temp != nullptr)
	{
		temp = temp->next;
		delete head;
		head = temp;
	}
}

List::node* List::initNode(string name, int id) {
	node* ptr = new node;
	if (ptr == nullptr) return nullptr;

	ptr->name = name;
	ptr->id = id;
	ptr->next = nullptr;
	return ptr;
}
List::node* List::searchName(node* ptr, string name) {
	while (name != ptr->name)
	{
		ptr = ptr->next;
		if (ptr == nullptr) break;
	}
	return ptr;
}
List::node* List::searchId(node* ptr, int id) {
	while (id != ptr->id)
	{
		ptr = ptr->next;
		if (ptr == nullptr) break;
	}
	return ptr;
}


void List::addNode(node* newNode) {
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
		tail->next = nullptr;
	}
	else {
		tail->next = newNode;
		newNode->next = nullptr;
		tail = newNode;
	}
}
void List::insertNode(node* newNode) {
	node* temp, * prev;
	if (head == nullptr) {
		addNode(newNode);
		return;
	}

	temp = head;
	while (temp->id < newNode->id) {
		temp = temp->next;
		if (temp == nullptr) break;
	}

	if (temp == head) {
		newNode->next = head;
		head = newNode;
	}
	else {
		prev = head;
		while (prev->next != temp) {
			prev = prev->next;
		}
		prev->next = newNode;
		newNode->next = temp;

		if (tail == prev)
			tail = newNode;
	}
}
void List::deleteNode(node* ptr) {
	node* temp, * prev;
	temp = ptr;
	prev = head;

	if (temp == prev) {
		head = head->next;
		if (tail == temp)
			tail = tail->next;
	}
	else {
		while (temp != prev->next) {
			prev = prev->next;				
		}
		prev->next = temp->next;
		if (tail == temp) tail = prev;
	}
	delete temp;
}
void List::deleteList(node* ptr) {
	node* temp;

	if (head == nullptr) return; // если список пуст, прекращаем выполнение метода

	if (ptr == head) {
		head = nullptr;
		tail = nullptr;
	}
	else {
		temp = head;
		while (temp->next != ptr) {
			temp = temp->next;
		}
		tail = temp;
	}

	while (ptr != nullptr)
	{
		temp = ptr->next;
		delete ptr;
		ptr = temp;
	}
}

void List::displayList(node* p) {
	if (!p) cout << "Nothing to display\n";
	while (p) {
		cout << p->id << " " << p->name << endl;
		p = p->next;
	}
}
void List::displayNode(node* p) {
	cout << p->id << ": " << p->name << endl;
}

List::node* List::Clone(node* p) {
	while (p->next != nullptr) {
		this->addNode(p);
		p = p->next;
	}
	return this->head;
}
