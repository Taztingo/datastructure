#ifndef __MY_QUEUE__
	#define __MY_QUEUE__

	#include "my_list.hpp"

	template <typename Q>
	class MyQueue {
		private:
			MyList<Q>* queue;
		public:
						MyQueue();
						~MyQueue();
			bool 	empty();
			int 	size();
			Q* 		front() const;
			Q* 		back() const;
			void 	push(Q);
			void 	pop();
	};

	/////////////////////////////////
	template <typename Q>
	MyQueue<Q>::MyQueue() {
		queue = new MyList<Q>();
	}
	/////////////////////////////////
	template <typename Q>
	MyQueue<Q>::~MyQueue() {
		delete queue;
		queue = NULL;
	}
	/////////////////////////////////
	
	/////////////////////////////////
	template <typename Q>
	bool MyQueue<Q>::empty() {
		return queue->empty();
	}
	/////////////////////////////////
	
	/////////////////////////////////
	template <typename Q>
	int MyQueue<Q>::size() {
		return queue->size();
	}
	/////////////////////////////////
	
	/////////////////////////////////
	template <typename Q>
	Q* MyQueue<Q>::front() const {
		return queue->front();
	}
	/////////////////////////////////
	
	/////////////////////////////////
	template <typename Q>
	Q* MyQueue<Q>::back() const {
		return queue->back();
	}
	/////////////////////////////////
	
	/////////////////////////////////
	template <typename Q>
	void MyQueue<Q>::push(Q data) {
		queue->push_back(data);
	}
	/////////////////////////////////

	/////////////////////////////////
	template <typename Q>
	void MyQueue<Q>::pop() {
		queue->pop_front();
	}
	/////////////////////////////////
#endif
