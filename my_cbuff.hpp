#ifndef __MY_CBUFF__
	#define __MY_CBUFF__

	#ifndef size_t
		#define size_t unsigned int
	#endif

	class MyCBuff {
		public:
			enum { default_size = 100 };
			explicit MyCBuff(size_t size = default_size);
			~MyCBuff();

			size_t			size() const;
			bool 				empty() const;
			int					top() const;
			void				pop();
			void				push(int);
			int &				operator[](size_t);
			int const & operator[](size_t) const;

		private:
			int* 		array;
			int 		index;
			size_t	length;
			size_t 	__size;
	};
	
	////////////////////////////////////
	MyCBuff::MyCBuff(size_t size) {
		array = new int[size];
		index = 0;
		__size = 0;
		array[0] = 0;
		length = size;
	}
	////////////////////////////////////

	////////////////////////////////////
	MyCBuff::~MyCBuff() {
		delete array;
		length = 0;
		index = 0;
		__size = 0;
	}
	////////////////////////////////////
	
	////////////////////////////////////
	size_t MyCBuff::size() const {
		return __size;
	}
	////////////////////////////////////

	////////////////////////////////////
	bool MyCBuff::empty() const {
		if(!__size)
			return true;
		else
			return false;
	}
	////////////////////////////////////
	
	////////////////////////////////////
	int MyCBuff::top() const {
		return array[0];
	}
	////////////////////////////////////

	////////////////////////////////////
	void MyCBuff::pop() {
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
	void MyCBuff::push(int newValue) {
		if(index == length)
			pop();

		array[index] = newValue;
		index++;
		if(__size < length)
			__size++;
	}
	////////////////////////////////////

	////////////////////////////////////
	int & MyCBuff::operator[](size_t index) {
		return array[index];
	}
	////////////////////////////////////
	
	////////////////////////////////////
	const int & MyCBuff::operator[](size_t index) const {
		return array[index];
	}
	////////////////////////////////////
#endif
