#pragma once
#include <iostream>
using namespace std;

class List
{
public:
	struct node {
		int id;
		string name;
		node* next;
	}*head, * tail, * ptr;

	List() :head{ nullptr }, tail{ nullptr }, ptr{ nullptr } {}
	~List();

	void displayList(node*); // отображение в консоли всех узлов
	void displayNode(node*); // отображение узла
	void addNode(node*); // добавление узла
	void insertNode(node*); // вставка узла
	void deleteNode(node*); // удаление узла
	void deleteList(node*); // удаление списка

	node* initNode(string, int); // инициализация структуры
	node* searchName(node*, string); // поиск по имени
	node* searchId(node*, int); //поиск по ID

	node* Clone(List& list);
	friend node* operator+(List& list1, List& list2);
};