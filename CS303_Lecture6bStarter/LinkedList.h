#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "Iterator.h"
#include "DNode.h"

using namespace std;

namespace myList {
	template <typename ItemType>
	
	class LinkedList {
	private:
		DNode<ItemType>* head;
		DNode<ItemType>* tail;
		int numItems;

	public:
		LinkedList();
		DNode<ItemType>* getHeadPtr() { return head; }
		myIterator::iterator<ItemType> begin() { return head; }
		myIterator::iterator<ItemType> end() { return tail; }
		size_t getNumItems() { return numItems; }
		bool empty() { return numItems == 0; }

		//TASK 1:
		void pushBack(const ItemType& d);
		void pushFront(const ItemType& d);
		ItemType back() const;
		ItemType front();
		ItemType popBack();
		ItemType popFront();
		string printList() const;

		bool find(const ItemType& d);
		bool remove(const ItemType& d);

		void insert(const size_t pos, const ItemType& newValue);
		bool addBefore(const ItemType& item, const ItemType& newValue);

		//myIterator::iterator<ItemType> erase(myIterator::iterator<ItemType> pos);
		//myIterator::iterator<ItemType> insert(myIterator::iterator<ItemType>, const ItemType& newValue);
		LinkedList(const LinkedList<ItemType>& other);
		LinkedList<ItemType>& operator= (const LinkedList<ItemType>& other);
		~LinkedList();

		ItemType operator[] (size_t n) {
			ItemType temp = 0;
			if (n > numItems - 1)
				throw exception("Accessing out of range\n");
			else if (numItems == 0)
				throw exception("No Elements in the list\n");
			size_t i = 0;
			DNode<ItemType>* tempPtr;
			tempPtr = head;

			while (tempPtr != nullptr) {
				if (i == n) {
					temp = tempPtr->data;
					return temp;
				}
				tempPtr = tempPtr->nextPtr;
				++i;
			}
			cout << endl;
			return temp;
		}
	};

	//default constructor
	//PRE: none
	//POST: set head, tail to null, set numItems to 0
	template <typename ItemType>
	LinkedList<ItemType>::LinkedList() {
		cout << "default constructor\n";
		head = nullptr;
		tail = nullptr;
		numItems = 0;
	}

	//TASK 1:
	//PRE: accepts a value of ItemType
	//POST: if headPtr is nullptr, it pushes item to the front 
	//      else it creates a newnode with the data
	//      sets next to null, prev to tail & tail->next & tail to new node
	//      increments numItems
	template <typename ItemType>
	void LinkedList<ItemType> ::pushBack(const ItemType& d) {
		cout << "pushback\n";

		
	}

	//PRE: accepts a value of ItemType
	//POST: it creates a newnode with the data & pointers to null 
	//      adjusts pointers
	//      increments numItems
	template <typename ItemType>
	void LinkedList<ItemType>::pushFront(const ItemType& d) {
		cout << "pushfront\n";
		DNode<ItemType>* newItem = new DNode<ItemType>;
		newItem->data = d;
		newItem->nextPtr = nullptr;
		newItem->prevPtr = nullptr;

		if (head == nullptr) {
			head = newItem;
			tail = newItem;
		}
		else {
			newItem->nextPtr = head;
			head->prevPtr = newItem;
			head = newItem;
		}
		++numItems;
	}
	//PRE:  none
	//POST: verifies that the list is not empty 
	//      returns the value at tail 
	template <typename ItemType>
	ItemType LinkedList<ItemType>::back() const {
		//list is empty
		if (tail == nullptr) {
			throw runtime_error("No items in list");
		}
		ItemType popItem = tail->data;
		return popItem;
	}
	//PRE:  none
	//POST: verifies that the list is not empty 
	//      returns the value at head 
	template <typename ItemType>
	ItemType LinkedList<ItemType>::front() {
		//list is empty
		if (head == nullptr) {
			throw runtime_error("No items in list");
		}
		ItemType popItem = head->data;
		return popItem;
	}

	//TASK 2
	//PRE:  none
	//POST: verifies that the list is not empty 
	//      saves value at tail, sets delete pointer
	//      adjusts remaining pointers
	//      decrements numItems
	//      return saved value
	template <typename ItemType>
	ItemType LinkedList<ItemType>::popBack() {
		cout << "popback:  ";
		ItemType popItem = tail->data;
		return popItem;

	}

	//PRE:  none
	//POST: verifies that the list is not empty 
	//      saves value at head, sets delete pointer
	//      adjusts remaining pointers
	//      decrements numItems
	//      return saved value

	template <typename ItemType>
	ItemType LinkedList<ItemType>::popFront() {
		cout << "popfront:  ";
		if (head == nullptr) {
			throw runtime_error("No items in list");
		}

		ItemType popItem = head->data;
		DNode<ItemType>* delPtr = head;
		head->nextPtr->prevPtr = nullptr;
		head = head->nextPtr;
		if (head == nullptr)
			tail = nullptr;
		delete delPtr;
		delPtr = nullptr;
		--numItems;

		return popItem;
	}


	//PRE:  provides the value to locate
	//POST: verifies that the list is not empty 
	//      loops through list to find value
	//      if found, return true, else false

	template <typename ItemType>
	bool LinkedList<ItemType>::find(const ItemType& d) {

		if (numItems == 0) {
			return false;
		}

		DNode<ItemType>* tempPtr;
		tempPtr = head;

		while (tempPtr != nullptr && tempPtr->data != d) {
			tempPtr = tempPtr->nextPtr;
		}

		if (tempPtr == nullptr || tempPtr->data != d)
			return false;
		else
			return true;
	}


	template <typename ItemType>
	string LinkedList<ItemType>::printList() const {
		//list is empty
		if (head == nullptr) {
			throw runtime_error("No items in list");
		}
		string out = "";
		myIterator::constIterator<ItemType> cIt = head;

		out += "printList   " + to_string(numItems) + ": { ";
		while (!(cIt == nullptr)) {
			out += to_string(*cIt) + ", ";
			++cIt;
		}
		out += " }";
		return out;
	}

	//PRE:  sends an item value from the list
	//POST: search the list for the first value in the list matching 'd'
	//      special case 1: the list is empty
	//		special case 2: delete head of list
	//		regular case: advance through list to find matching data or end of list
	//      if found, delete item reduce numItems, return true
	template <typename ItemType>
	bool LinkedList<ItemType>::remove(const ItemType& d) {

		//special case 1: the list is empty
		if (numItems == 0)
			return false;

		DNode<ItemType>* tempPtr;
		tempPtr = head;

		//special case 2: delete head of list
		if (tempPtr != nullptr && tempPtr->data == d) {
			head = head->nextPtr;
			head->prevPtr = nullptr;
			delete tempPtr;
			tempPtr = nullptr;
			--numItems;
			return true;
		}

		//regular case: advance through list to find matching data or end of list
		while (tempPtr != nullptr
			&& tempPtr->data != d) {
			tempPtr = tempPtr->nextPtr;
		}

		if (tempPtr != nullptr
			&& tempPtr->data == d) {   //delete the next node

			tempPtr->prevPtr->nextPtr = tempPtr->nextPtr;
			if (tempPtr->nextPtr == nullptr) {
				tail = tempPtr->prevPtr;
			}
			else {
				tempPtr->nextPtr->prevPtr = tempPtr->prevPtr;
				tempPtr->nextPtr = tempPtr->nextPtr->nextPtr;
			}
			delete tempPtr;
			--numItems;
			return true;
		}
		return false;
	}

	//TASK 3
	//NEED TO FINISH
	//PRE:
	//POST: 
	template <typename ItemType>
	void LinkedList<ItemType>::insert(const size_t pos, const ItemType& newValue) {

	}


	//TASK 4
	//NEED TO FINISH
	//PRE:  passing in value 'd' (item that will follow value) & value
	//POST: case 1: 'd' is at the front of the list or is the head
	//      case 2: 'd' is not in the list, then add value to the end of the list
	//      case 3: find 'd' and insert value before 'd'
	template <typename ItemType>
	bool LinkedList<ItemType>::addBefore(const ItemType& d, const ItemType& value) {


		return false;


	}
	//copy constructor
	template <typename ItemType>
	LinkedList<ItemType>::LinkedList (const LinkedList<ItemType>& other) :
	    head(nullptr), 
		tail(nullptr),
		numItems(0) {
		std::cout << "Copy Constructor called\n";

		//create a node for currPtr
		DNode<ItemType>* currPtr = other.head;
		while (!(currPtr == nullptr)) {
			pushBack(currPtr->data);
			currPtr = currPtr->nextPtr;
		}
	}

	//copy assignment operator
	template <typename ItemType>
	LinkedList<ItemType>& LinkedList<ItemType>::operator= 
		(const LinkedList<ItemType>& other) {
		std::cout << "Copy Assignment Operator called\n";
		if (this == &other)
			return *this;

		//create a node for currPtr
		DNode<ItemType>* currPtr = other.head;
		while (!(currPtr == nullptr)) {
			pushBack(currPtr->data);
			currPtr = currPtr->nextPtr;
		}

		return *this;
	}

	//destructor
	template <typename ItemType>
	LinkedList<ItemType>::~LinkedList<ItemType>() {
		std::cout << "Destructor called\n";
		
		DNode<ItemType>* currPtr = head;
		while (!(currPtr == nullptr)) {
			DNode<ItemType>* temp = currPtr;
			currPtr = currPtr->nextPtr;
			delete temp;
		}
		head = nullptr;
		tail = nullptr;
		numItems = 0;
	}


}
