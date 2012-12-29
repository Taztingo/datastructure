#ifndef __MY_CBUFF_ITERATOR__
	#define __MY_CBUFF_ITERATOR__

	#ifndef size_t
		#define size_t unsigned int
	#endif

	#ifndef ptrdiff_t
		#define ptrdiff_t int
	#endif

	template <typename T>
	class MyCBuffIterator {
		public:
			typedef T           			value_type;
			typedef T*          			pointer;
			typedef const T*   				const_pointer;
			typedef T&          			reference;
			typedef const T&    			const_reference;
			typedef size_t      			size_type;
			typedef ptrdiff_t   			difference_type;
			//typedef iterator_category	bidirectional_iterator_tag;

			MyCBuffIterator(pointer, size_type);
	
		private:
			pointer			buffer_;
			size_type		index_;
		
	};

	///////////////////////////////////
	template <typename T>
	MyCBuffIterator<T>::MyCBuffIterator(pointer b, size_type start_pos) {
		buffer_ = b;
		index_ = start_pos;
	}
	///////////////////////////////////
#endif
