#pragma once

template <typename ItemType>
struct DNode {
	ItemType data;
	DNode* nextPtr;
	DNode* prevPtr;

	DNode() : data(0), nextPtr(nullptr), prevPtr(nullptr) {}


	// Constructor
	DNode(const ItemType& data_item, DNode<ItemType>* prev_val = nullptr, DNode<ItemType>* next_val = nullptr) :
		data(data_item),
		prevPtr(prev_val),
		nextPtr(next_val) {}
};