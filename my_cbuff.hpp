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
			T* 			array;
			size_t 	index;
			size_t	length;
			size_t 	__size;
	};
	
	////////////////////////////////////
	template <typename T>
	MyCBuff<T>::MyCBuff(size_t size) {
		array = new T[size];
		index = 0;
		__size = 0;
		length = size;
	}
	////////////////////////////////////

	////////////////////////////////////
	template <typename T>
	MyCBuff<T>::~MyCBuff() {
		delete array;
		length = 0;
		index = 0;
		__size = 0;
	}
	////////////////////////////////////
	
	////////////////////////////////////
	template <typename T>
	size_t MyCBuff<T>::size() const {
		return __size;
	}
	////////////////////////////////////

	////////////////////////////////////
	template <typename T>
	bool MyCBuff<T>::empty() const {
		if(!__size)
			return true;
		else
			return false;
	}
	////////////////////////////////////
	
	////////////////////////////////////
	template <typename T>
	T MyCBuff<T>::top() const {
		return array[0];
	}
	////////////////////////////////////

	////////////////////////////////////
	template <typename T>
	void MyCBuff<T>::pop() {
		if(__size == 0)
			return;

		for(int i = 0; i < index - 1; i++)
			array[i] = array[i+1];
		index--;
		array[index] = 0;
		__size--;
	}
	////////////////////////////////////

	////////////////////////////////////
	template <typename T>
	void MyCBuff<T>::push(T newValue) {
		if(index == length)
			pop();

		array[index] = newValue;
		index++;
		if(__size < length)
			__size++;
	}
	////////////////////////////////////

	////////////////////////////////////
	template <typename T>
	T & MyCBuff<T>::operator[](size_t index) {
		return array[index];
	}
	////////////////////////////////////
	
	////////////////////////////////////
	template <typename T>
	const T & MyCBuff<T>::operator[](size_t index) const {
		return array[index];
	}
	////////////////////////////////////
#endif
