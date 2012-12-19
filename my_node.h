#ifndef __MY_NODE__
	#define __MY_NODE__

	#ifndef NULL
		#define NULL 0
	#endif
	template<typename T>
	class MyNode {
		private:
			T data;
			MyNode<T>* previous;
			MyNode<T>* next;
		public:
			MyNode();
			MyNode(T, MyNode<T>*, MyNode<T>*);
			~MyNode();
			T getData();
			MyNode<T>* getNext();
			MyNode<T>* getPrevious();
			void setData(T);
			void setNext(MyNode<T>*);
			void setPrevious(MyNode<T>*);
	};

/////////////////////////////////
	template<typename T>
	MyNode<T>::MyNode() {
		data = NULL;
		next = NULL;
		previous = NULL;
	}
/////////////////////////////////
	template <typename T>
	MyNode<T>::MyNode(T d, MyNode<T>* n, MyNode<T>* p) {
		data = d;
		next = n;
		previous = p;
	}
/////////////////////////////////
	template <typename T>
	MyNode<T>::~MyNode() {
		data = NULL;
		previous = NULL;
		next = NULL;
	}
/////////////////////////////////
	template<typename T>
	T MyNode<T>::getData() {
		return data;
	}
/////////////////////////////////
	template <typename T>
	MyNode<T>* MyNode<T>::getNext() {
		return next;
	}
/////////////////////////////////
	template <typename T>
	MyNode<T>* MyNode<T>::getPrevious() {
		return previous;
	}
/////////////////////////////////
	template <typename T>
	void MyNode<T>::setData(T d) {
		data = d;
	}
/////////////////////////////////
	template <typename T>
	void MyNode<T>::setNext(MyNode<T>* node) {
		next = node;
	}
/////////////////////////////////
	template <typename T>
	void MyNode<T>::setPrevious(MyNode<T>* node) {
		previous = node;
	}
/////////////////////////////////

#endif
