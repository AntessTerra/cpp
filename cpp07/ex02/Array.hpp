#ifndef __ARRAY__
#define __ARRAY__

#include <iostream>
#include <typeinfo>

template <typename T>
class Array {
	private:
		T*	_array;
		int	_size;
	public:
		Array(){
			_array = NULL;
			_size = 0;
		}

		Array(unsigned int n){
			_array = new T[n];
			_size = n;
		}

		Array(const Array& original)
		{
			_array = new T[original._size];
			_size = original._size;
			for (int i = 0; i < original._size; i++)
				_array[i] = original._array[i];
		}

		Array& operator=(const Array& src)
		{
			if (this != &src)
			{
				delete[] _array;
				_array = new T[src._size];
				_size = src._size;
				for (unsigned int i = 0; i < src._size; i++)
					_array[i] = src._array[i];
			}
			return (*this);
		}

		~Array() {delete[] _array;}

		T& operator[](int index) const
		{
			if (index < 0 || index >= this->_size)
				throw std::length_error("\e[31mIndex out of range\e[0m");
			return (this->_array[index]);
		}

		int size() const {return _size;}
};

template <typename T>
void printArray(Array<T> arr){
	if (arr.size() == 0)
		return std::cout << "\e[31mEmpty array\e[0m" << std::endl, (void)0;
	std::cout << "PRINTING ARRAY OF " << typeid(arr[0]).name() << std::endl;
	for (int i = 0; i < arr.size(); i++)
		std::cout << i << ": " << arr[i] << std::endl;
}

#endif
