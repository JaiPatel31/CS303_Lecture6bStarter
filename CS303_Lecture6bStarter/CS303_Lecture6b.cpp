// CS303_Lecture6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "DNode.h"
#include "LinkedList.h"
#include <iostream>
#include <list>

using namespace myIterator;

int main()
{
    // create a doubly linked list
    // setup the initial nodes of Harry & Sam
    LinkedList<int> newList;
    try {
        newList.pushBack(1);
        newList.pushBack(2);
        newList.pushBack(3);
        newList.pushBack(4);
        newList.pushFront(10);
        newList.pushFront(20);
        newList.pushFront(30);
        newList.pushFront(40);

        cout << newList.popFront() << endl;
        cout << newList.popBack() << endl;
        cout << newList.popFront() << endl;
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

    //using an iterator with the doubly linked list
    myIterator::iterator<int> newListIter(newList.begin());

    newList.insert(3, 99);
    cout << "Find 20: " << newList.find(20) << endl;
    cout << "Find 101: " << newList.find(101) << endl;

    if (newList.remove(3)) cout << "Remove is succesful\n";
    if (newList.addBefore(99, 98)) cout << "addBefore is succesful\n";

    newListIter++;
    newListIter++;

    //printList uses constIterator
    cout << newList.printList() << endl;

    //printList uses iterator
    while (!(newListIter == newList.end())) {
        std::cout << *newListIter << "\n";
        newListIter++;
    }
}