#pragma once
#include <iostream>
#include <stdexcept>
#include "DNode.h"

namespace myIterator {

	template <typename itemType>
	class iterator {

	private:
		DNode<itemType>* current;			// A pointer to the current DNode 


	public:
		iterator(DNode<itemType>* position) :
			current(position) {
			std::cout << "Default constructor\n";
		}

		//used for *iterator = newValue
		itemType& operator*() const {
			std::cout << "myIterator* = newValue\n";
			if (current == nullptr)
				throw std::invalid_argument("Attempt to dereference end()");

			return current->data;
		}

		//used to get current data value:  example iterator->data()
		itemType* operator->() const {
			std::cout << "Using myIterator->\n";
			if (current == nullptr)
				throw std::invalid_argument("Attempt to dereference end()");

			return &(current->data);
		}

		// Equality comparison
		bool operator==(const iterator& other) const {
			return current == other.current;
		}

		iterator& operator++() {
			std::cout << "prefix operator ++\n";
			if (current == nullptr)
				throw std::invalid_argument("Attempt to advance past end()");
			current = current->nextPtr;

			return *this;
		}

		iterator operator++(int) {
			std::cout << "postfix operator ++\n";
			// Make a copy of the current value.
			iterator return_value = *this; //*this returns a dereferenced pointer
			// Advance self forward.
			++(*this);
			// Return old value.
			return return_value;   // Return the value prior to increment
		}

		iterator& operator--() {
			std::cout << "postfix operator --\n";
			if (current->prevPtr == nullptr)   // no prior elements
				throw std::invalid_argument("There are no previous elements");
			else
				current = current->prevPtr;
			return *this;
		}


		iterator  operator--(int) {
			std::cout << "prefix operator --\n";
			// Make a copy of the current value.
			iterator return_value = *this;
			// Move self backward.
			if (current)
				current = current->prevPtr;
			// Return old value.
			return return_value;   // Return the value prior to decrement
		}
	};

	template <typename itemType>
	class constIterator {

	private:
		DNode<itemType>* current;			// A pointer to the current DNode 


	public:
		constIterator(DNode<itemType>* position) :
			current(position) {
			std::cout << "Default constructor\n";
		}

		//used for *iterator = newValue
		const itemType& operator*() const {
			std::cout << "myIterator* = newValue\n";
			if (current == nullptr)
				throw std::invalid_argument("Attempt to dereference end()");

			return current->data;
		}

		//used to get current data value:  example iterator->data()
		const itemType* operator->() const {
			std::cout << "Using myIterator->\n";
			if (current == nullptr)
				throw std::invalid_argument("Attempt to dereference end()");

			return &(current->data);
		}

		// Equality comparison
		bool operator==(const constIterator& other) const {
			return current == other.current;
		}

		constIterator& operator++() {
			std::cout << "prefix operator ++\n";
			if (current == nullptr)
				throw std::invalid_argument("Attempt to advance past end()");
			current = current->nextPtr;

			return *this;
		}

		constIterator operator++(int) {
			std::cout << "postfix operator ++\n";
			// Make a copy of the current value.
			constIterator return_value = *this; //*this returns a dereferenced pointer
			// Advance self forward.
			++(*this);
			// Return old value.
			return return_value;   // Return the value prior to increment
		}

		constIterator& operator--() {
			std::cout << "postfix operator --\n";
			if (current->prevPtr == nullptr)   // no prior elements
				throw std::invalid_argument("There are no previous elements");
			else
				current = current->prevPtr;
			return *this;
		}


		constIterator  operator--(int) {
			std::cout << "prefix operator --\n";
			// Make a copy of the current value.
			constIterator return_value = *this;
			// Move self backward.
			if (current)
				current = current->prevPtr;
			// Return old value.
			return return_value;   // Return the value prior to decrement
		}
	};
};
