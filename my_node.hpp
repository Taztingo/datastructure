#ifndef __MY_NODE__
	#define __MY_NODE__

	#ifndef NULL
		#define NULL 0
	#endif

	#include <cstdlib>

	template<typename T>
	class MyNode {
		private:
			T 					data_;
			size_t 			num_children_;
			MyNode<T>** children_;	//0 is left/previous 1 is right/next
		public:
									MyNode(size_t size = 2);
									MyNode(T, MyNode<T>*, MyNode<T>*, size_t size = 2);
									~MyNode();
			T 					getData();
			MyNode<T>* 	getNext();
			MyNode<T>* 	getRight();
			MyNode<T>* 	getPrevious();
			MyNode<T>* 	getLeft();
			MyNode<T>*	getNode(size_t);
			size_t			getChildren();
			void 				setData(T);
			void 				setNext(MyNode<T>*);
			void 				setRight(MyNode<T>*);
			void 				setPrevious(MyNode<T>*);
			void 				setLeft(MyNode<T>*);
			void				setNode(size_t, MyNode<T>*);

	};

	/////////////////////////////////
	#include <iostream>
	using namespace std;
	template<typename T>
	MyNode<T>::MyNode(size_t size) {
		children_ = new MyNode<T>*[size];
		data_ = NULL;
		num_children_ = size;
	}
	/////////////////////////////////
	template <typename T>
	MyNode<T>::MyNode(T d, MyNode<T>* n, MyNode<T>* p, size_t size) {
		children_ = new MyNode<T>*[size];
		data_ = d;
		children_[1] = n;
		children_[0] = p;
		num_children_ = size;
	}
	/////////////////////////////////
	template <typename T>
	MyNode<T>::~MyNode() {
		delete [] children_;
	}
	/////////////////////////////////
	template<typename T>
	T MyNode<T>::getData() {
		return data_;
	}
	/////////////////////////////////
	template <typename T>
	MyNode<T>* MyNode<T>::getNext() {
		return children_[1];
	}
	/////////////////////////////////
	template <typename T>
	MyNode<T>* MyNode<T>::getRight() {
		return children_[1];
	}
	/////////////////////////////////
	template <typename T>
	MyNode<T>* MyNode<T>::getPrevious() {
		return children_[0];
	}
	/////////////////////////////////
	template <typename T>
	MyNode<T>* MyNode<T>::getLeft() {
		return children_[0];
	}
	/////////////////////////////////
	
	/////////////////////////////////
	template <typename T>
	MyNode<T>* MyNode<T>::getNode(size_t index) {
		return children_[index];
	}
	/////////////////////////////////
	
	/////////////////////////////////
	template <typename T>
	size_t MyNode<T>::getChildren() {
		return num_children_;
	}
	/////////////////////////////////
	
	/////////////////////////////////
	template <typename T>
	void MyNode<T>::setData(T d) {
		data_ = d;
	}
	/////////////////////////////////
	template <typename T>
	void MyNode<T>::setNext(MyNode<T>* node) {
		children_[1] = node;
	}
	/////////////////////////////////
	template <typename T>
	void MyNode<T>::setRight(MyNode<T>* node) {
		children_[1] = node;
	}
	/////////////////////////////////
	template <typename T>
	void MyNode<T>::setPrevious(MyNode<T>* node) {
		children_[0] = node;
	}
	/////////////////////////////////
	template <typename T>
	void MyNode<T>::setLeft(MyNode<T>* node) {
		children_[0] = node;
	}
	/////////////////////////////////

	/////////////////////////////////
	template <typename T>
	void MyNode<T>::setNode(size_t index, MyNode<T>* node) {
		children_[index] = node;
	}
	/////////////////////////////////
#endif
