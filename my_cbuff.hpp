#ifndef __MY_CBUFF__
	#define __MY_CBUFF__

	#ifndef size_t
		#define size_t unsigned int
	#endif

	#ifndef ptrdiff_t
		#define ptrdiff_t int
	#endif

	#include "my_cbuff_iterator.hpp"

	template <typename T>
	class MyCBuff {
		
		typedef T 					value_type;
		typedef T* 					pointer;
		typedef const T*		const_pointer;
		typedef T&					reference;
		typedef const T&		const_reference;
		typedef size_t			size_type;
		typedef ptrdiff_t		difference_type;
		typedef MyCBuff			self_type;
		typedef MyCBuffIterator<self_type> 	iterator;
		
		public:
			enum { default_size = 100 };
			explicit MyCBuff(size_type size = default_size);
			~MyCBuff();

			value_type				top() const;
			void							pop();
			void							push(value_type);

			//STL Functions
			reference 				front();
			const_reference 	front() const;
			reference 				back();
			const_reference 	back() const;
			void							clear();
			void							pop_front();
			void							push_back(const value_type &item);
			size_type					size() const;
			size_type					capacity() const;
			bool 							empty() const;
			size_type					max_size() const;
			reference					operator[](size_type);
			const_reference 	operator[](size_type) const;
			iterator					begin();
			iterator					end();

		private:
			pointer 		array_;
			size_type		max_size_;
			size_type 	size_;
			size_type		head_;
			size_type		tail_;
	};
	
	////////////////////////////////////
	template <typename T>
	MyCBuff<T>::MyCBuff(size_type size) {
		array_ = new value_type[size];
		size_ = 0;
		head_ = 0;
		tail_ = 0;
		max_size_ = size;
	}
	////////////////////////////////////

	////////////////////////////////////
	template <typename T>
	MyCBuff<T>::~MyCBuff() {
		delete[] array_;
		max_size_ = 0;
		size_ = 0;
	}
	////////////////////////////////////
	
	////////////////////////////////////
	template <typename T>
	typename MyCBuff<T>::value_type MyCBuff<T>::top() const {
		return array_[head_];
	}
	////////////////////////////////////

	////////////////////////////////////
	template <typename T>
	void MyCBuff<T>::pop() {
		if(size_ == 0)
			return;

		for(int i = 0; i < size_ - 1; i++)
			array_[i] = array_[i+1];
		size_--;
		array_[size_] = 0;
		tail_ = size_ - 1;
	}
	////////////////////////////////////

	////////////////////////////////////
	template <typename T>
	void MyCBuff<T>::push(value_type newValue) {
		if(size_ == max_size_)
			pop();

		array_[size_] = newValue;
		tail_ = size_;
		if(size_ < max_size_)
			size_++;
	}
	////////////////////////////////////

	////////////////////////////////////
	template <typename T>
	typename MyCBuff<T>::reference MyCBuff<T>::front() {
		return array_[head_];
	}
	////////////////////////////////////
	
	////////////////////////////////////
	template <typename T>
	typename MyCBuff<T>::const_reference MyCBuff<T>::front() const {
		return array_[head_];
	}
	////////////////////////////////////
	
	////////////////////////////////////
	template <typename T>
	typename MyCBuff<T>::reference MyCBuff<T>::back() {
		return array_[tail_];
	}
	////////////////////////////////////
	
	////////////////////////////////////
	template <typename T>
	typename MyCBuff<T>::const_reference MyCBuff<T>::back() const {
		return array_[tail_];
	}
	////////////////////////////////////

	////////////////////////////////////
	template <typename T>
	void MyCBuff<T>::clear() {
		size_ = 0;
		head_ = 0;
		tail_ = 0;
	}
	////////////////////////////////////

	////////////////////////////////////
	template <typename T>
	void MyCBuff<T>::pop_front() {
		pop();
	}
	////////////////////////////////////

	////////////////////////////////////
	template <typename T>
	void MyCBuff<T>::push_back(const value_type &item) {
		push(item);
	}
	////////////////////////////////////
	
	////////////////////////////////////
	template <typename T>
	typename MyCBuff<T>::size_type MyCBuff<T>::size() const {
		return size_;
	}
	////////////////////////////////////

	////////////////////////////////////
	template <typename T>
	typename MyCBuff<T>::size_type MyCBuff<T>::capacity() const {
		return max_size_;
	}
	////////////////////////////////////
	
	////////////////////////////////////
	template <typename T>
	bool MyCBuff<T>::empty() const {
		if(!size_)
			return true;
		else
			return false;
	}
	////////////////////////////////////

	////////////////////////////////////
	template <typename T>
	typename MyCBuff<T>::size_type MyCBuff<T>::max_size() const {
		return size_type(-1) / sizeof(value_type);
	}
	////////////////////////////////////
	
	////////////////////////////////////
	template <typename T>
	typename MyCBuff<T>::reference MyCBuff<T>::operator[](size_type index) {
		return array_[index];
	}
	////////////////////////////////////
	
	////////////////////////////////////
	template <typename T>
	typename MyCBuff<T>::const_reference MyCBuff<T>::operator[](size_type index) const {
		return array_[index];
	}
	////////////////////////////////////

	////////////////////////////////////
	template <typename T>
	typename MyCBuff<T>::iterator MyCBuff<T>::begin() {
		return iterator(this, 0);
	}
	////////////////////////////////////
	
	////////////////////////////////////
	template <typename T>
	typename MyCBuff<T>::iterator MyCBuff<T>::end() {
		return iterator(this, size());
	}
	////////////////////////////////////
#endif
