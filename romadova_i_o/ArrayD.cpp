#include <iostream>

template <typename T>
class ArrayD {
public:
	ArrayD() = default;

	T& operator[](int);

	void resize(int new_size) {
		T* new_start = new T[new_size];
		if (new_start != nullptr) {
			for (int i = 0; i < GetSize(); i += 1) {
				new_start[i] = start_[i];
			}
			delete[] start_;
			start_ = new_start;
			array_size_ = new_size;
		}
	}
	void push_back(const T& el) {
		resize(GetSize() + 1);
		start_[GetSize() - 1] = el;
	}
	void insert(int index,const T& el) {
		push_back(el);
		for (int i = GetSize() - 1; i >= index; i -= 1) {
			if (i - 1 >= 0) {
				std::swap(start_[i], start_[i - 1]);
			}
			else {
				break;
			}
		}
	}
	bool is_empty() {
		return GetSize() == 0;
	}


	int GetSize() const {
		return array_size_;
	}

	~ArrayD() = default;

private:
	int array_size_ = { 0 };
	int buffer_size_ = { 1 };//спросить как реализовать буфер
	T* start_ = { nullptr };
};

template<typename T>
T& ArrayD<T>::operator[](int index)
{
	return *(start_ + index);
}

int main() {
	ArrayD<int> massiv;
	massiv.push_back(1);
	massiv.push_back(3);
	massiv.insert(2, 2);
	std::cout << massiv.GetSize()<<"\n";
	std::cout << massiv[0]<<massiv[1]<<massiv[2];
	return 0;
}