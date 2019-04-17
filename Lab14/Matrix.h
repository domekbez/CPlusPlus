#pragma once

#include <stdexcept>
#include <iostream>
#include <iomanip>

using namespace std;

class MatrixException : public logic_error
{
public:
	MatrixException(string message) : logic_error(message) {}
};

template<class T> class Matrix
{
private:
	T * coefficients;
	int rows, cols, size;
public:
	Matrix(int r, int c)
	{
		rows = r;
		cols = c;
		size = r*c;
		if (r == 0 || c == 0)
		{
			coefficients = nullptr;
		}
		else
		{
			coefficients = new T[size];
			for (int i = 0; i < size; i++)
				coefficients[i] = 0;
		}
	}
	Matrix(int r, int c,T* tab)
	{
		if (!tab)
		{
			rows = 0;
			cols = 0;
			size = 0;
			coefficients = nullptr;
			return;
		}
		rows = r;
		cols = c;
		size = r*c;
		coefficients = new T[size];
		for (int i = 0; i < size; i++)
			coefficients[i] = tab[i];
		
	}
	Matrix(const Matrix<T>& mat)
	{
		if (!mat.coefficients)
		{
			rows = 0;
			cols = 0;
			size = 0;
			coefficients = nullptr;
			return;
		}
		rows = mat.rows;
		cols = mat.cols;
		size = mat.cols*mat.rows;
		coefficients = new T[size];
		for (int i = 0; i < size; i++)
			coefficients[i] = mat.coefficients[i];
		
	}
	~Matrix()
	{
		delete[] coefficients;
	}
	Matrix<T>& operator=(const Matrix<T>& mat)
	{
		if (this == &mat)
			return *this;
		if (mat.rows==rows && mat.cols==cols)
		{
			for (int i = 0; i < size; i++)
				coefficients[i] = mat.coefficients[i];
			return *this;
		}
		rows = mat.rows;
		cols = mat.cols;
		size = mat.cols*mat.rows;
		delete[] coefficients;
		coefficients = new T[size];
		for (int i = 0; i < size; i++)
			coefficients[i] = mat.coefficients[i];
		return *this;

	}
	friend ostream& operator<<(ostream& out, const Matrix<T> mat)
	{
		for (int i = 0; i < mat.rows; i++)
		{
			for (int j = 0; j < mat.cols; j++)
				out << mat.coefficients[i*mat.cols + j] << " ";
			out << endl;
		}
		out << endl;
		return out;

	}
	int GetRows() const
	{
		return rows;
	}
	int GetColumns() const
	{
		return cols;
	}
	T& operator()(int r, int c)
	{
		if (r < 0 || r >= rows || c < 0 || c >= cols)
		{
			throw MatrixException("Indeks poza zasiegiem");
		}
		return coefficients[r*cols + c];
	}
	T operator()(int r, int c) const
	{
		if (r < 0 || r >= rows || c < 0 || c >= cols)
		{
			throw MatrixException("Indeks poza zasiegiem");
		}
		return coefficients[r*cols + c];
	}
	friend Matrix<T> operator-(const Matrix<T> m1, const Matrix<T> m2)
	{
		if (m1.rows != m2.rows || m1.cols != m2.cols)
		{
			throw MatrixException("Wymiary sie nie zgadzaja");
		}
		Matrix<T> m(m1.rows, m1.cols);
		for (int i = 0; i < m.size; i++)
			m.coefficients[i] = m1.coefficients[i] - m2.coefficients[i];
		return m;
	}
	friend bool operator!=(const Matrix<T> m1, const Matrix<T> m2)
	{
		if (m1.rows != m2.rows || m1.cols != m2.cols)
			return true;
		for (int i = 0; i < m1.size; i++)
		{
			if (m1.coefficients[i] != m2.coefficients[i])
				return true;
		}
		return false;
	}
	Matrix<T> operator-() 
	{
		Matrix<T> m(rows, cols);
		for (int i = 0; i < size; i++)
			m.coefficients[i] = -1*coefficients[i];
		return m;
	}
	Matrix<T> operator*(T a)
	{
		Matrix<T> m=*this;
		for (int i = 0; i < size; i++)
			m.coefficients[i] *= a;
		return m;
	}
	friend Matrix<T> operator*(const Matrix<T>& m1, const Matrix<T>& m2)
	{
		if (m1.cols != m2.rows)
		{
			throw MatrixException("Wymiary sie nie zgadzaja");
		}
		Matrix<T> m(m1.rows, m2.cols);

		for(int i=0;i<m.rows;i++)
			for (int j = 0; j < m.cols; j++)
			{
				m(i, j) = 0;
				for (int k = 0; k < m2.rows; k++)
					m(i, j) += m1(i,k)*m2(k,j);

			}
		return m;
	}
	Matrix<T> operator*=(const Matrix<T>& m1)
	{
		*this = (*this)*m1;;
		return *this;
	}
// uzupe³niæ

};