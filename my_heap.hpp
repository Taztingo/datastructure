#ifndef __MY_HEAP__
	#define __MY_HEAP__

	#ifndef NULL
		#define NULL 0
	#endif
	
	#include "my_node.hpp"

	template <typename T>
	class MyHeap {
		private:
			MyNode<T>*	root_;
			void clear();

		public:
			MyHeap();
			~MyHeap();
			void heapify(T**);
			void peek();
			void pop();
			void push(T*);
			void reverse();
	}
	
	/////////////////////////////////
	template <typename T>
	void MyHeap<T>::clear(MyNode<T>* node) {
		if(!node)
			return;

		clear(node->getLeft());
		clear(node->getRight());
		
		delete node;
	  }
	/////////////////////////////////

	/////////////////////////////////
	template <typename T>
	MyHeap<T>::MyHeap() {
		root_ = NULL;
	}
	/////////////////////////////////

	/////////////////////////////////
	template <typename T>
	MyHeap<T>::~MyHeap() {
		clear(root_);
	}
	/////////////////////////////////

#endif
