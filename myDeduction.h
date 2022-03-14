#pragma once
template<typename T, size_t size> class MyArray
{
	T ar[size]{}; //��� ���������� ������������� ��������� �������� ���� �� ��������� �����?
	
public:
	MyArray() = default;
	~MyArray() = default;
	MyArray(const T* a) { for (size_t i = 0; i<size; i++) { ar[i] = a[i]; }; };
	MyArray(const T* a, size_t a_size) { for (size_t i = 0; i < a_size; i++) { ar[i] = a[i]; }; };

};
template<typename T, size_t size> MyArray(const T(&arr)[size])->MyArray<T, size>;
