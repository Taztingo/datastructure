#ifndef __MY_QUEUE__
	#define __MY_QUEUE__

	#include "my_node.h"
	#include "my_list.h"

	template <typename T>
	class MyQueue {
		private:
			MyList<T>* queue;
		public:
			MyQueue();
			~MyQueue();
			bool empty();
			int size();
			T* front() const;
			T* back() const;
			void push(T);
			void pop();
	};
/////////////////////////////////
	template <typename T>
	MyQueue<T>::MyQueue() {
		queue = new MyList<T>();
	}
/////////////////////////////////
	template <typename T>
	MyQueue<T>::~MyQueue() {
		delete queue;
		queue = NULL;
	}
/////////////////////////////////
	template <typename T>
	bool MyQueue<T>::empty() {
		return queue->empty();
	}
/////////////////////////////////
	template <typename T>
	int MyQueue<T>::size() {
		return queue->size();
	}
/////////////////////////////////
	template <typename T>
	T* MyQueue<T>::front() const {
		return queue->front();
	}
/////////////////////////////////
	template <typename T>
	T* MyQueue<T>::back() const {
		return queue->back();
	}
/////////////////////////////////
	template <typename T>
	void MyQueue<T>::push(T data) {
		queue->push_back(data);
	}
/////////////////////////////////
	template <typename T>
	void MyQueue<T>::pop() {
		queue->pop_front();
	}
/////////////////////////////////
#endif
