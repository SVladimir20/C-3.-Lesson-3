#pragma once
#include <iostream>
#include <cmath>
#include <chrono>
#include <random>
#include <iomanip>
using namespace std;

class Matrix
{
public:
	Matrix(size_t matrixSize);
	~Matrix();
	int32_t getRandomNum(int32_t min, int32_t max);
	double Determinant(double **mtx, size_t mSize);
	void Print() const;
	double **getMatrix() const;
	size_t getSize() const;

private:
	size_t Size{};
	double **matrix{};
};