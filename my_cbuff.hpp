#ifndef __MY_CBUFF__
	#define __MY_CBUFF__

	#ifndef size_t
		#define size_t unsigned int
	#endif

	template <typename T>
	class MyCBuff {
		public:
			enum { default_size = 100 };
			explicit MyCBuff(size_t size = default_size);
			~MyCBuff();

			size_t		size() const;
			bool 			empty() const;
			T					top() const;
			void			pop();
			void			push(T);
			T &				operator[](size_t);
			T const & operator[](size_t) const;

		private:
			T* 			array_;
			size_t	length_;
			size_t 	size_;
			T			 	head_;
			T				tail_;
	};
	
	////////////////////////////////////
	template <typename T>
	MyCBuff<T>::MyCBuff(size_t size) {
		array_ = new T[size];
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
	size_t MyCBuff<T>::size() const {
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
	T MyCBuff<T>::top() const {
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
	void MyCBuff<T>::push(T newValue) {
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
	T & MyCBuff<T>::operator[](size_t index) {
		return array_[index];
	}
	////////////////////////////////////
	
	////////////////////////////////////
	template <typename T>
	const T & MyCBuff<T>::operator[](size_t index) const {
		return array_[index];
	}
	////////////////////////////////////
#endif
