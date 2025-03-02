#pragma once
#include "DNode.h"

namespace myIterator {
	template <typename itemType>

	class iterator {
	private:
		DNode<itemType>* current;			/** A pointer to a DNode named current */

	public:
		iterator(DNode<itemType>* position) :
			current(position) {
			std::cout << "Default constructor\n";
		}


		// PRE: current is left side, rhs is the right hand side of equality
		// POST: returns true or false
		bool operator==(const iterator& rhs) const {
			return current == rhs.current;
		}


		bool operator!=(const iterator& rhs) const {
			return current != rhs.current;
		}
		//PRE:  None
		//POST: Verifies that the current pointer is valid. 
		//      Returns a reference to the data field in the node that it points to
		//		used for *iterator = newValue
		itemType& operator*() const {
			std::cout << "myIterator* = newValue\n";
			if (current == nullptr)
				throw std::invalid_argument("Attempt to dereference end()");

			return current->data;
		}

		//PRE:  None
		//POST: Verifies that the current pointer is valid. 
		//      Returns a pointer to the data field in the current node.
		//		used to get current data value:  example iterator->data()
		itemType* operator->() const {
			std::cout << "Using myIterator->\n";
			if (current == nullptr)
				throw std::invalid_argument("Attempt to dereference end()");

			return &(current->data);
		}

		//PRE:  None
		//POST: Verifies that the current pointer is valid. 
		//      Advances the pointer
		//      Returns current value of the updated iterator
		iterator& operator++() {
			std::cout << "prefix operator ++\n";
			if (current == nullptr)
				throw std::invalid_argument("Attempt to advance past end()");
			current = current->next;

			return *this;
		}

		//PRE:  None
		//POST: Verifies that the current pointer is valid. 
		//      Advances the pointer
		//      Returns current value of the updated iterator
		iterator operator++(int) {
			std::cout << "postfix operator ++\n";
			// Make a copy of the current value.
			iterator return_value = *this; //*this returns a dereferenced pointer
			// Advance self forward using prefix operator
			++(*this);
			// Return old value.
			return return_value;   // Return the value prior to increment
		}

		//TASK 1
		//PRE:  None
		//POST: Verifies that the current pointer is valid. 
		//      Advances the pointer
		//      Returns current value of the updated iterator
		iterator& operator--() {
			std::cout << "prefix operator --\n";
			//if (current->prev == nullptr)   // no prior elements
			if (current->prev == nullptr || current == nullptr) {
				throw std::invalid_argument("Attempt to go back past head()");
			}
			current = current->prev;
			//else
 
			return *this;
		}

		//TASK 1
		//PRE:  None
		//POST: Saves current pointer value 
		//      decrements the pointer
		//      Returns saved value of the iterator

		iterator  operator--(int) {
			std::cout << "postfix operator --\n";
			// Make a copy of the current value.
			iterator return_value = *this; 
			// Move self backward.
			--(*this);
			// Return old value.
			return return_value;			  // Return the value prior to decrement
		}

	};

	template <typename itemType>

	class const_iterator {
	private:
		DNode<itemType>* current;			/** A pointer to a DNode named current */

	public:
		const_iterator(DNode<itemType>* position) :
			current(position) {
			std::cout << "Default constructor\n";
		}


		// PRE: current is left side, rhs is the right hand side of equality
		// POST: returns true or false
		bool operator==(const const_iterator& rhs) const {
			return current == rhs.current;
		}

		//PRE:  None
		//POST: Verifies that the current pointer is valid. 
		//      Returns a reference to the data field in the node that it points to
		itemType& operator*() const {
			std::cout << "myIterator*\n";
			if (current == nullptr)
				throw std::invalid_argument("Attempt to dereference end()");

			return current->data;
		}

		//PRE:  None
		//POST: Verifies that the current pointer is valid. 
		//      Returns a pointer to the data field in the current node.
		//		used to get current data value:  example iterator->data()
		itemType* operator->() const {
			std::cout << "Using myIterator->\n";
			if (current == nullptr)
				throw std::invalid_argument("Attempt to dereference end()");

			return &(current->data);
		}

		//PRE:  None
		//POST: Verifies that the current pointer is valid. 
		//      Advances the pointer
		//      Returns current value of the updated iterator
		const_iterator& operator++() {
			std::cout << "prefix operator ++\n";
			if (current == nullptr)
				throw std::invalid_argument("Attempt to advance past end()");
			current = current->next;

			return *this;
		}

		//PRE:  None
		//POST: Verifies that the current pointer is valid. 
		//      Advances the pointer
		//      Returns current value of the updated iterator
		const_iterator operator++(int) {
			std::cout << "postfix operator ++\n";
			// Make a copy of the current value.
			const_iterator return_value = *this; //*this returns a dereferenced pointer
			// Advance self forward using prefix operator
			++(*this);
			// Return old value.
			return return_value;   // Return the value prior to increment
		}

		//TASK 2
		//PRE:  None
		//POST: Verifies that the current pointer is valid. 
		//      Advances the pointer
		//      Returns current value of the updated iterator
		const_iterator& operator--() {
			std::cout << "prefix operator --\n";
			//if (current->prev == nullptr)   // no prior elements
			if (current->prev == nullptr) {
				throw std::invalid_argument("Attempt to go back too far");
			}
			//else
			current = current->prev;
			return *this;
		}

		//TASK 2
		//PRE:  None
		//POST: Saves current pointer value 
		//      decrements the pointer
		//      Returns saved value of the iterator

		const_iterator  operator--(int) {
			std::cout << "postfix operator --\n";
			// Make a copy of the current value.
			const_iterator returnValue = *this;
			// Move self backward.
			--(*this);
			// Return old value.
			return returnValue;			  // Return the value prior to decrement
		}

	};
};

