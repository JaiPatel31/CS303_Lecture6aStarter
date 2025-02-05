#pragma once
#include <iostream>
#include <stdexcept>

template <typename itemType>
struct DNode {
	// Data Fields

	itemType data;			/** The data */
	DNode* next;			/** The pointer to the next node. */
	DNode* prev;			/** The pointer to the previous node. */

	// Constructor
	DNode(const itemType& data_item, DNode* prev_val = nullptr, DNode* next_val = nullptr) :
		data(data_item), 
		prev(prev_val), 
		next(next_val) {}
};
