#ifndef __MY_STACK__
	#define __MY_STACK__

	#include "my_list.hpp"

	template <typename T>
	class MyStack {
		private:
			MyList<T>* stack;
		public:
						MyStack();
						~MyStack();
			bool 	empty();
			int 	size();
			T* 		top() const;
			void 	push(T);
			void 	pop();
	};

	/////////////////////////////////
	template <typename T>
	MyStack<T>::MyStack() {
		stack = new MyList<T>();
	}
	/////////////////////////////////
	template <typename T>
	MyStack<T>::~MyStack() {
		delete stack;
		stack = NULL;
	}
	/////////////////////////////////
	
	/////////////////////////////////
	template <typename T>
	bool MyStack<T>::empty() {
		return stack->empty();
	}
	/////////////////////////////////
	
	/////////////////////////////////
	template <typename T>
	int MyStack<T>::size() {
		return stack->size();
	}
	/////////////////////////////////
	
	/////////////////////////////////
	template <typename T>
	T* MyStack<T>::top() const {
		return stack->front();
	}
	/////////////////////////////////
	
	/////////////////////////////////
	template <typename T>
	void MyStack<T>::push(T data) {
		stack->push_front(data);
	}
	/////////////////////////////////

	/////////////////////////////////
	template <typename T>
	void MyStack<T>::pop() {
		stack->pop_front();
	}
	/////////////////////////////////
#endif
