#ifndef __MY_LIST__
	#define __MY_LIST__

	#ifndef NULL
		#define NULL 0
	#endif

	#include "my_node.hpp"

	template <typename G>
	class MyList {
		private:
			MyNode<G>* head;
			MyNode<G>* tail;
			
			void traverse();
			void reverse_traverse();
		public:
			MyList();
			~MyList();
			bool empty();
			int size();
			G* front() const;
			G* back() const;
			void push_front(G);
			void pop_front();
			void push_back(G);
			void pop_back();
			void insert(int, int, G);
			void erase(int, int);
			void erase_at(int);
			void swap(MyList<G>*);	
			void clear();
			void remove(G);
			void unique();
			void merge(MyList<G>*);
			//void sort();	//Removed because it uses iterators
			void reverse();
			void operator=(MyList<G>);	//Ghis needs to be fixed
			void set_head(MyNode<G>*);
			void set_tail(MyNode<G>*);
			MyNode<G>* get_head();
			MyNode<G>* get_tail();
	};
/////////////////////////////////
	#include <iostream>
	using namespace std;

	template <typename G>
	void MyList<G>::traverse() {
		MyNode<G>* temp;

		temp = head;
		while(temp) {
			cout << " " << temp->getData();
			temp = temp->getNext();
		}
		cout << "\n";
	}
	
/////////////////////////////////
	#include <iostream>
	using namespace std;

	template <typename G>
	void MyList<G>::reverse_traverse() {
		MyNode<G>* temp;

		temp = tail;
		while(temp) {
			cout << " " << temp->getData();
			temp = temp->getPrevious();
		}
		cout << "\n";
	}
/////////////////////////////////
	template <typename G>
	MyList<G>::MyList() {
		head = NULL;
		tail = NULL;
	}
/////////////////////////////////
	template <typename G>
	MyList<G>::~MyList() {
		clear();
	}
/////////////////////////////////
	template <typename G>
	bool MyList<G>::empty() {
		bool ret;

		ret = true;
		if(head)
			ret = false;
	
		return ret;
	}
/////////////////////////////////
	template <typename G>
	int MyList<G>::size() {
		int size;
		MyNode<G>* temp;

		size = 0;
		for(temp = head; temp; temp = temp->getNext())
			size++;

		return size;
	}
/////////////////////////////////
	template <typename G>
	G* MyList<G>::front() const {
		if(head)
			return &(head->getData());
		else
			return NULL;
	}
/////////////////////////////////
	template <typename G>
	G* MyList<G>::back() const{
		if(tail)
			return &(tail->getData());
		else
			return NULL;
	}
/////////////////////////////////
	template <typename G>
	void MyList<G>::push_front(G value) {
		MyNode<G>* new_node;

		new_node = new MyNode<G>(value, head, NULL);

		//Set tail since size is 1
		if(!head) {
			tail = new_node;
		}
		//Shift head down 1 and replace
		else
			head->setPrevious(new_node);

		head = new_node;
	}
/////////////////////////////////
	template <typename G>
	void MyList<G>::pop_front() {
		MyNode<G>* temp;

		if(head) {
			temp = head->getNext();
			delete head;
			head = temp;

			//Sets the tail to the head if size is 1
			if(head) {
				if(!head->getNext())
					tail = head;
				head->setPrevious(NULL);
			}
			else
				tail = NULL;
		}

	}
/////////////////////////////////
	template <typename G>
	void MyList<G>::push_back(G val) {
		MyNode<G>* new_node;

		new_node = new MyNode<G>(val, NULL, tail);

		if(!head)
			head = new_node;
		else
			tail->setNext(new_node);

		tail = new_node;
	}
/////////////////////////////////
	template <typename G>
	void MyList<G>::pop_back() {
		MyNode<G>* temp;

		if(tail) {
			temp = tail->getPrevious();
			delete tail;
			tail = temp;

			//Sets the head to the tail if size is 1
			if(tail) {
				if(!tail->getPrevious())
					head = tail;
				tail->setNext(NULL);
			}
			else
				head = NULL;
		}
	}
/////////////////////////////////
	template <typename G>
	void MyList<G>::insert(int position, int num_elements, G value) {
		MyNode<G>* current;
		MyNode<G>* previous;
		MyNode<G>* new_node;

		current = head;
		previous = NULL;
		while(position > 0 && current) {
			previous = current;
			current = current->getNext();
			position--;
		}

		//Insert at head
		if(!previous) {
			for(num_elements; num_elements > 0; num_elements--)
				push_front(value);
		}
		//Insert at end
		else if(!current) {
			for(num_elements; num_elements > 0; num_elements--)
				push_back(value);
		}
		//Insert in middle
		else {
			while(num_elements > 0) {
				new_node = new MyNode<G>(value, current, previous);
				previous->setNext(new_node);
				current->setPrevious(new_node);
				previous = new_node;
				num_elements--;
			}
		}
	}
/////////////////////////////////
	template <typename G>
	void MyList<G>::erase(int start, int end) {
		int distance;

		if(start < 0)
			start = 0;

		distance = end - start;
		while(distance >= 0) {
			erase_at(start);
			distance--;
		}
	}
/////////////////////////////////
	template <typename G>
	void MyList<G>::erase_at(int position) {
		MyNode<G>* current;
		MyNode<G>* previous;

		if(position < 0)
			position = 0;

		current = head;
		previous = NULL;

		while(current && position > 0) {
			previous = current;
			current = current->getNext();
			position--;
		}

		//Remove the head
		if(!previous)
			pop_front();
		//Remove the tail
		else if(!current)
			pop_back();
		//Remove something in the middle
		else {
			previous->setNext(current->getNext());

			if(current->getNext())
				(current->getNext())->setPrevious(previous);

			delete current;
		}
	}
/////////////////////////////////
	template <typename G>
	void MyList<G>::swap(MyList<G>* other_list) {
		MyNode<G>* this_head = head;
		MyNode<G>* this_tail = tail;
		MyNode<G>* other_head = other_list->get_head();
		MyNode<G>* other_tail = other_list->get_tail();

		set_head(other_head);
		set_tail(other_tail);

		other_list->set_head(this_head);
		other_list->set_tail(this_tail);
	}
/////////////////////////////////
	template <typename G>
	void MyList<G>::clear() {
		MyNode<G>* temp;

		while(head)
		{
			temp = head;
			head = head->getNext();
			delete temp;
		}
		head = NULL;
		tail = NULL;
	}
/////////////////////////////////
	template <typename G>
	void MyList<G>::remove(G value) {
		int counter;
		MyNode<G>* temp;

		counter = 0;
		temp = head;
		while(temp) {
			if(value == temp->getData()) {
				erase_at(counter);
				break;
			}
			temp = temp->getNext();
			counter++;
		}
	}
/////////////////////////////////
	template <typename G>
	void MyList<G>::unique() {
		MyNode<G>* current;
		MyNode<G>* previous;
		MyNode<G>* next;

		current = head;
		while(current) {
			next = current->getNext();
			previous = current->getPrevious();
			if(next && next->getData() == current->getData()) {
				if(current != head) { 
					previous->setNext(next);
					next->setPrevious(previous);
					delete current;
				}
				else
					pop_front();
			}
			
			current = next;
		}
	}
/////////////////////////////////
	template <typename G>
	void MyList<G>::merge(MyList<G>* merged_list) {
		MyNode<G>* this_current;
		MyNode<G>* other_current;
		int counter;

		this_current = head;
		other_current = merged_list->get_head();
		counter = 0;

		while(this_current) {
			while(other_current && other_current->getData() < this_current->getData()) {
				insert(counter, 1, other_current->getData());
				counter++;
				other_current = other_current->getNext();
			}
			this_current = this_current->getNext();
			counter++;
		}

		while(other_current) {
			push_back(other_current->getData());
			other_current = other_current->getNext();
		}
	}
/////////////////////////////////
/*#include <algorithm.h>

void MyList::sort() {
	int length;
	int counter;
	MyNode* previous;
	MyNode* current;

	length = MyList.size();
	int array[length];
	counter = 0;
	current = head;
	previous = NULL;

	while(current) {
		array[counter] = current->getData();
		previous = current;
		current = current->getNext();
		counter++;
		delete previous;
	}

	//Sort
	sort(array);

	for(counter = counter - 1; counter >= 0; counter--)
		push_front(array[counter]);

}*/

/////////////////////////////////
	template <typename G>
	void MyList<G>::reverse() {
		MyNode<G>* temp_tail;
		MyNode<G>* original_tail;

		//Pushes everything behind the tail
		temp_tail = tail;
		original_tail = tail;
		while(temp_tail) {
			if(temp_tail != tail) {
				push_back(temp_tail->getData());
			}
			temp_tail = temp_tail->getPrevious();
		}

		//Deletes everything before the tail
		while(head != original_tail)
			pop_front();
	}
/////////////////////////////////
	template <typename G>
	void MyList<G>::operator=(MyList<G> new_list) {
		MyNode<G>* temp;
		clear();
	
		temp = new_list.front();

		while(temp) {
			push_back(temp->getData());
			temp = temp->getNext();
		}
	}
/////////////////////////////////
	template <typename G>
	void MyList<G>::set_head(MyNode<G>* new_head) {
			head = new_head;
	}
/////////////////////////////////
	template <typename G>
	void MyList<G>::set_tail(MyNode<G>* new_tail) {
		tail = new_tail;
	}
/////////////////////////////////
	template <typename G>
		MyNode<G>* MyList<G>::get_head() {
			return head;
		}
/////////////////////////////////
	template <typename G>
		MyNode<G>* MyList<G>::get_tail() {
			return tail;
		}
/////////////////////////////////
#endif
