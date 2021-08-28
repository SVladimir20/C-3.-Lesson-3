#include "2.h"

int32_t Matrix::getRandomNum(int32_t min, int32_t max)
{
	const static auto seed = chrono::system_clock::now().time_since_epoch().count();
	static mt19937_64 generator(seed);
	uniform_int_distribution<int32_t> dis(min, max);
	return dis(generator);
}

Matrix::Matrix(size_t matrixSize) : Size(matrixSize)
{
	if (Size <= 0)
	{
		cout << "Такая матрица не существует" << endl;
		return;
	}
	matrix = new double* [Size];
	for (size_t i = 0; i < Size; i++)
	{
		matrix[i] = new double[Size];
	}
	for (size_t i = 0; i < Size; i++)
	{
		for (size_t j = 0; j < Size; j++)
		{
			matrix[i][j] = getRandomNum(-1000, 1000);
		}
	}
}

double **Matrix::getMatrix() const
{
	return matrix;
}

size_t Matrix::getSize() const
{
	return Size;
}

Matrix::~Matrix()
{
	for (size_t i = 0; i < getSize(); i++)
	{
		delete[] getMatrix()[i];
	}
	delete[] getMatrix();
}

double Matrix::Determinant(double **mtx, size_t mSize)
{
	if (mSize == 1)
	{
		return mtx[0][0];
	}
	else if (mSize == 2)
	{
		return (mtx[0][0] * mtx[1][1]) - (mtx[0][1] * mtx[1][0]);
	}
	else
	{
		double det = 0;
		for (size_t k = 0; k < mSize; k++)
		{
			double **m = new double* [mSize - 1];
			for (int i = 0; i < mSize - 1; i++)
			{
				m[i] = new double[mSize - 1];
			}
			for (size_t i = 1; i < mSize; i++)
			{
				size_t t = 0;
				for (size_t j = 0; j < mSize; j++)
				{
					if (j == k)
					{
						continue;
					}
					m[i - 1][t] = mtx[i][j];
					t++;
				}
			}
			det += pow(-1, k + 2) * mtx[0][k] * Determinant(m, mSize - 1);
		}
		return det;
	}
}

void Matrix::Print() const
{
	cout << setw(11) << "Матрица " << Size << "x" << Size << endl << setw(5);
	for (size_t i = 0; i < Size; i++)
	{
		for (size_t j = 0; j < Size; j++)
		{
			cout << matrix[i][j] << setw(5);
		}
		cout << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Matrix m(4);
	m.Print();
	cout << endl << "Определитель матрицы = " << m.Determinant(m.getMatrix(), m.getSize());
	cout << endl;
	return 0;
}