#ifndef __MY_NODE__
	#define __MY_NODE__

	#ifndef NULL
		#define NULL 0
	#endif

	#include <cstdlib>

	template<typename N>
	class MyNode {
		private:
			N 					data_;
			size_t 			num_children_;
			MyNode<N>* 	parent_;
			MyNode<N>** children_;	//0 is left/previous 1 is right/next
		public:
									MyNode(size_t size = 2);
									MyNode(N, MyNode<N>*, MyNode<N>*, size_t size = 2);
									~MyNode();
			N 					getData();
			MyNode<N>* 	getNext();
			MyNode<N>* 	getRight();
			MyNode<N>* 	getPrevious();
			MyNode<N>* 	getLeft();
			MyNode<N>*	getNode(size_t);
			MyNode<N>*	getParent();
			size_t			getChildren();
			void 				setData(N);
			void 				setNext(MyNode<N>*);
			void 				setRight(MyNode<N>*);
			void 				setPrevious(MyNode<N>*);
			void 				setLeft(MyNode<N>*);
			void				setNode(size_t, MyNode<N>*);
			void				setParent(MyNode<N>*);

	};

	/////////////////////////////////
	#include <iostream>
	using namespace std;
	template<typename N>
	MyNode<N>::MyNode(size_t size) {
		children_ = new MyNode<N>*[size];
		data_ = NULL;
		parent_ = NULL;
		num_children_ = size;
	}
	/////////////////////////////////
	template <typename N>
	MyNode<N>::MyNode(N d, MyNode<N>* n, MyNode<N>* p, size_t size) {
		children_ = new MyNode<N>*[size];
		data_ = d;
		parent_ = NULL;
		children_[1] = n;
		children_[0] = p;
		num_children_ = size;
	}
	/////////////////////////////////
	template <typename N>
	MyNode<N>::~MyNode() {
		delete [] children_;
	}
	/////////////////////////////////
	template<typename N>
	N MyNode<N>::getData() {
		return data_;
	}
	/////////////////////////////////
	template <typename N>
	MyNode<N>* MyNode<N>::getNext() {
		return children_[1];
	}
	/////////////////////////////////
	template <typename N>
	MyNode<N>* MyNode<N>::getRight() {
		return children_[1];
	}
	/////////////////////////////////
	template <typename N>
	MyNode<N>* MyNode<N>::getPrevious() {
		return children_[0];
	}
	/////////////////////////////////
	template <typename N>
	MyNode<N>* MyNode<N>::getLeft() {
		return children_[0];
	}
	/////////////////////////////////
	
	/////////////////////////////////
	template <typename N>
	MyNode<N>* MyNode<N>::getNode(size_t index) {
		return children_[index];
	}
	/////////////////////////////////
	
	/////////////////////////////////
	template <typename N>
	MyNode<N>* MyNode<N>::getParent() {
		return parent_;
	}
	/////////////////////////////////
	
	/////////////////////////////////
	template <typename N>
	size_t MyNode<N>::getChildren() {
		return num_children_;
	}
	/////////////////////////////////
	
	/////////////////////////////////
	template <typename N>
	void MyNode<N>::setData(N d) {
		data_ = d;
	}
	/////////////////////////////////
	template <typename N>
	void MyNode<N>::setNext(MyNode<N>* node) {
		children_[1] = node;
	}
	/////////////////////////////////
	template <typename N>
	void MyNode<N>::setRight(MyNode<N>* node) {
		children_[1] = node;
	}
	/////////////////////////////////
	template <typename N>
	void MyNode<N>::setPrevious(MyNode<N>* node) {
		children_[0] = node;
	}
	/////////////////////////////////
	template <typename N>
	void MyNode<N>::setLeft(MyNode<N>* node) {
		children_[0] = node;
	}
	/////////////////////////////////

	/////////////////////////////////
	template <typename N>
	void MyNode<N>::setNode(size_t index, MyNode<N>* node) {
		children_[index] = node;
	}
	/////////////////////////////////
	
	/////////////////////////////////
	template <typename N>
	void MyNode<N>::setParent(MyNode<N>* new_parent) {
		parent_ = new_parent;
	}
	/////////////////////////////////
#endif
