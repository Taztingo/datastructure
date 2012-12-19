#ifndef __MY_LIST__
	#define __MY_LIST__

	#ifndef NULL
		#define NULL 0
	#endif

	#include "my_node.hpp"

	template <typename T>
	class MyList {
		private:
			MyNode<T>* head;
			MyNode<T>* tail;
			
			void traverse();
			void reverse_traverse();
		public:
			MyList();
			~MyList();
			bool empty();
			int size();
			T* front() const;
			T* back() const;
			void push_front(T);
			void pop_front();
			void push_back(T);
			void pop_back();
			void insert(int, int, T);
			void erase(int, int);
			void erase_at(int);
			void swap(MyList<T>*);	
			void clear();
			void remove(T);
			void unique();
			void merge(MyList<T>*);
			//void sort();	//Removed because it uses iterators
			void reverse();
			void operator=(MyList<T>);	//This needs to be fixed
			void set_head(MyNode<T>*);
			void set_tail(MyNode<T>*);
			MyNode<T>* get_head();
			MyNode<T>* get_tail();
	};
/////////////////////////////////
	#include <iostream>
	using namespace std;

	template <typename T>
	void MyList<T>::traverse() {
		MyNode<T>* temp;

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

	template <typename T>
	void MyList<T>::reverse_traverse() {
		MyNode<T>* temp;

		temp = tail;
		while(temp) {
			cout << " " << temp->getData();
			temp = temp->getPrevious();
		}
		cout << "\n";
	}
/////////////////////////////////
	template <typename T>
	MyList<T>::MyList() {
		head = NULL;
		tail = NULL;
	}
/////////////////////////////////
	template <typename T>
	MyList<T>::~MyList() {
		clear();
	}
/////////////////////////////////
	template <typename T>
	bool MyList<T>::empty() {
		bool ret;

		ret = true;
		if(head)
			ret = false;
	
		return ret;
	}
/////////////////////////////////
	template <typename T>
	int MyList<T>::size() {
		int size;
		MyNode<T>* temp;

		size = 0;
		for(temp = head; temp; temp = temp->getNext())
			size++;

		return size;
	}
/////////////////////////////////
	template <typename T>
	T* MyList<T>::front() const {
		if(head)
			return &(head->getData());
		else
			return NULL;
	}
/////////////////////////////////
	template <typename T>
	T* MyList<T>::back() const{
		if(tail)
			return &(tail->getData());
		else
			return NULL;
	}
/////////////////////////////////
	template <typename T>
	void MyList<T>::push_front(T value) {
		MyNode<T>* new_node;

		new_node = new MyNode<T>(value, head, NULL);

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
	template <typename T>
	void MyList<T>::pop_front() {
		MyNode<T>* temp;

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
	template <typename T>
	void MyList<T>::push_back(T val) {
		MyNode<T>* new_node;

		new_node = new MyNode<T>(val, NULL, tail);

		if(!head)
			head = new_node;
		else
			tail->setNext(new_node);

		tail = new_node;
	}
/////////////////////////////////
	template <typename T>
	void MyList<T>::pop_back() {
		MyNode<T>* temp;

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
	template <typename T>
	void MyList<T>::insert(int position, int num_elements, T value) {
		MyNode<T>* current;
		MyNode<T>* previous;
		MyNode<T>* new_node;

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
				new_node = new MyNode<T>(value, current, previous);
				previous->setNext(new_node);
				current->setPrevious(new_node);
				previous = new_node;
				num_elements--;
			}
		}
	}
/////////////////////////////////
	template <typename T>
	void MyList<T>::erase(int start, int end) {
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
	template <typename T>
	void MyList<T>::erase_at(int position) {
		MyNode<T>* current;
		MyNode<T>* previous;

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
	template <typename T>
	void MyList<T>::swap(MyList<T>* other_list) {
		MyNode<T>* this_head = head;
		MyNode<T>* this_tail = tail;
		MyNode<T>* other_head = other_list->get_head();
		MyNode<T>* other_tail = other_list->get_tail();

		set_head(other_head);
		set_tail(other_tail);

		other_list->set_head(this_head);
		other_list->set_tail(this_tail);
	}
/////////////////////////////////
	template <typename T>
	void MyList<T>::clear() {
		MyNode<T>* temp;

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
	template <typename T>
	void MyList<T>::remove(T value) {
		int counter;
		MyNode<T>* temp;

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
	template <typename T>
	void MyList<T>::unique() {
		MyNode<T>* current;
		MyNode<T>* previous;
		MyNode<T>* next;

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
	template <typename T>
	void MyList<T>::merge(MyList<T>* merged_list) {
		MyNode<T>* this_current;
		MyNode<T>* other_current;
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
	template <typename T>
	void MyList<T>::reverse() {
		MyNode<T>* temp_tail;
		MyNode<T>* original_tail;

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
	template <typename T>
	void MyList<T>::operator=(MyList<T> new_list) {
		MyNode<T>* temp;
		clear();
	
		temp = new_list.front();

		while(temp) {
			push_back(temp->getData());
			temp = temp->getNext();
		}
	}
/////////////////////////////////
	template <typename T>
	void MyList<T>::set_head(MyNode<T>* new_head) {
			head = new_head;
	}
/////////////////////////////////
	template <typename T>
	void MyList<T>::set_tail(MyNode<T>* new_tail) {
		tail = new_tail;
	}
/////////////////////////////////
	template <typename T>
		MyNode<T>* MyList<T>::get_head() {
			return head;
		}
/////////////////////////////////
	template <typename T>
		MyNode<T>* MyList<T>::get_tail() {
			return tail;
		}
/////////////////////////////////
#endif
