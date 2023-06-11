#include <iostream>
#include "ListStack.h"
#include "list2.h"


int main()
{

    //LinkedList list;
    //list.Push(43);
    //list.Push(315);
    //list.Push(5654);
    //list.Push(532);
    //list.Push(52123);
    //list.Push(876);
    //list.printList();
    //list.pop();

    //std::cout << std::endl;
    ////ist.Clear();

    //list.printList();

    List myList;
    List myList2;
    List::node* ptr;

    ptr = myList.initNode("string 1", 1);
    myList.addNode(ptr);
    ptr = myList.initNode("string 6", 6);
    myList.addNode(ptr);
    ptr = myList.initNode("string 4", 4);
    myList.addNode(ptr);
    ptr = myList.initNode("string 2", 2);
    myList.addNode(ptr);

    //ptr = myList2.initNode("string 123", 10);
    //myList2.addNode(ptr);
    //ptr = myList2.initNode("string 235", 8);
    //myList2.addNode(ptr);
    //ptr = myList2.initNode("string 654", 5);
    //myList2.addNode(ptr);
    //ptr = myList2.initNode("string 423", 3);
    //myList2.addNode(ptr);

    //myList.displayList(myList.head);
    //std::cout << std::endl;
    //myList2.displayList(myList2.head);
    //std::cout << std::endl;

    //myList + myList2;

    //myList.displayList(myList.head);
    //std::cout << std::endl;
    
    myList.displayList(myList.head);
    std::cout << std::endl;


    myList2.Clone(myList);

    myList2.displayList(myList2.head);
    std::cout << std::endl;
    
    
}
