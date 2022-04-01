#pragma once
#include "Core/Vec2.h"
#include <vector>;

template <typename T>
class Matrix
{
public:
	Matrix(Vec2 size, T nullValue);
	Matrix(int x, int y, T nullValue);
	Matrix(Matrix& matr);
	~Matrix();

	const Vec2 getSize() const;
	void setSize(Vec2 size);
	const T** getMatrix() const;
	T& at(int x, int y);
	T& at(Vec2 item);

	void FillMatrix(T value);
	void Clear();

private:
	void FillMatrix(std::vector<std::vector<T>>, Vec2 size, int value);
	void Resize(Vec2 size);

	T nullValue;
	std::vector<std::vector<T>> matrix;
	Vec2 size;
};

template<typename T>
Matrix<T>::Matrix(Vec2 size, T nullValue)
{
	this->size = size;
	this->nullValue = nullValue;
	Resize(size);
}

template<typename T>
Matrix<T>::Matrix(int x, int y, T nullValue)
{
	this->size = Vec2(x, y);
	this->nullValue = nullValue;
	Resize(size);
}

template<typename T>
Matrix<T>::Matrix(Matrix& matr)
{
	this->size = matr.size;
	this->nullValue = matr.nullValue;
	matrix = matr.matrix;

}

template<typename T>
Matrix<T>::~Matrix()
{
	delete[]this->matrix;
}

template<typename T>
const Vec2 Matrix<T>::getSize() const
{
	return this->size;
}

template<typename T>
void Matrix<T>::setSize(Vec2 size)
{
	Resize(size);
	this->size = size;
}

template<typename T>
const T** Matrix<T>::getMatrix() const
{
	return matrix;
}

template<typename T>
T& Matrix<T>::at(int x, int y)
{
	if ((x < size.x && y < size.y) && (x >= 0 && y >= 0))
		return matrix.at(0).at(0);
}

template<typename T>
T& Matrix<T>::at(Vec2 item)
{
	if ((item.x < size.x && item.y < size.y) && (item.x >= 0 && item.y >= 0))
		return matrix.at(item.x).at(item.y);
}

template<typename T>
void Matrix<T>::FillMatrix(T value)
{
	for (int i = 0; i < size.x; i++)
		for (int j = 0; j < size.y; j++)
			this->matrix.at(i).at(j) = value;
}

 template<typename T>
 void Matrix<T>::FillMatrix(std::vector<std::vector<T>> matr, Vec2 size, int value)
 {

	 for (int i = 0; i < size.y; i++)
		 for (int j = 0; j < size.x; j++)
			 matr.at(i).at(j) = value;
 }

template<typename T>
void Matrix<T>::Clear()
{
	FillMatrix(nullValue);
}

template<typename T>
void Matrix<T>::Resize(Vec2 size)
{
	if (size.x == 0 || size.y == 0) return;

	matrix.resize(size.x);
	for (int i = 0; i < matrix.size(); i++)
		matrix[i].resize(size.y, nullValue);
}
