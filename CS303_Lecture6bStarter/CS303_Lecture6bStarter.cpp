// CS303_Lecture6bStarter.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "DNode.h"
#include "LinkedList.h"
#include <iostream>
#include <list>

using namespace myIterator;

void myFunction(myList::LinkedList<int> newList2) {
    //updating newList2 (copy constructor)
    std::cout << "MyFunction\n";
    newList2.pushFront(101);
    cout << "pushFront complete\n";

}

int main()
{
    // create a doubly linked list
    // setup the initial nodes of Harry & Sam
    myList::LinkedList<int> newList;
    try {
        newList.pushBack(1);    //TASK 1
        newList.pushBack(2);    //TASK 1
        newList.pushBack(3);    //TASK 1
        newList.pushBack(4);    //TASK 1
        newList.pushFront(10);
        newList.pushFront(20);
        newList.pushFront(30);
        newList.pushFront(40);

        cout << newList.popFront() << endl;
        cout << newList.popBack() << endl;  //TASK 2
        cout << newList.popFront() << endl;
    
        myFunction(newList);
        //printList uses constIterator
        cout << "LIST:  " << newList.printList() << endl << endl;

        myList::LinkedList<int> newList3 = newList;
        cout << "LIST3: " << newList3.printList() << endl << endl;

        newList3.pushFront(101);
        cout << "LIST3: " << newList3.printList() << endl << endl;
        cout << "LIST:  " << newList.printList() << endl << endl;

        //using an iterator with the doubly linked list
        myIterator::iterator<int> newListIter(newList.begin());

        newList.insert(1, 99);    //TASK 3
        cout << "Find 20: " << newList.find(20) << endl;
        cout << "Find 101: " << newList.find(101) << endl;

        if (newList.remove(3)) cout << "Remove is successful\n";
        if (newList.addBefore(10, 98)) cout << "addBefore is successful\n";   //TASK 4

        //printList uses constIterator
        cout << newList.printList() << endl;

        //printList uses iterator
        while (!(newListIter == newList.end())) {
            std::cout << *newListIter << "\n";
            newListIter++;
        }
    }
    catch (invalid_argument& err) {
        cout << "error caught " << err.what() << endl;
    }
    catch (runtime_error& err) {
        cout << "error caught " << err.what() << endl;
    }
    catch (...) {
        cout << "some other error caught\n";
    }

}
