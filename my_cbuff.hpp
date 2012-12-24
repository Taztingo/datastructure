#ifndef __MY_CBUFF__
	#define __MY_CBUFF__

	#ifndef size_t
		#define size_t unsigned int
	#endif

	#ifndef ptrdiff_t
		#define ptrdiff_t int
	#endif

	template <typename T>
	class MyCBuff {
		
		typedef T 				value_type;
		typedef T* 				pointer;
		typedef const T*	const_pointer;
		typedef T&				reference;
		typedef const T&	const_reference;
		typedef size_t		size_type;
		typedef ptrdiff_t	difference_type;
		
		public:
			enum { default_size = 100 };
			explicit MyCBuff(size_type size = default_size);
			~MyCBuff();

			size_type					size() const;
			bool 							empty() const;
			value_type				top() const;
			void							pop();
			void							push(value_type);
			reference					operator[](size_type);
			const_reference 	operator[](size_type) const;

		private:
			pointer 			array_;
			size_type			length_;
			size_type 		size_;
			value_type		head_;
			value_type		tail_;
	};
	
	////////////////////////////////////
	template <typename T>
	MyCBuff<T>::MyCBuff(size_type size) {
		array_ = new value_type[size];
		size_ = 0;
		head_ = 0;
		tail_ = 0;
		length_ = size;
	}
	////////////////////////////////////

	////////////////////////////////////
	template <typename T>
	MyCBuff<T>::~MyCBuff() {
		delete[] array_;
		length_ = 0;
		size_ = 0;
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
	bool MyCBuff<T>::empty() const {
		if(!size_)
			return true;
		else
			return false;
	}
	////////////////////////////////////
	
	////////////////////////////////////
	template <typename T>
	typename MyCBuff<T>::value_type MyCBuff<T>::top() const {
		return array_[0];
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
		head_ = array_[0];
		tail_ = array_[size_ - 1];
	}
	////////////////////////////////////

	////////////////////////////////////
	template <typename T>
	void MyCBuff<T>::push(value_type newValue) {
		if(size_ == length_)
			pop();

		array_[size_] = newValue;
		head_ = array_[0];
		tail_ = newValue;
		if(size_ < length_)
			size_++;
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
#endif
