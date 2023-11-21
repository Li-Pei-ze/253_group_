#include <ctime>  
#include "templateMatrix.h"

int main()
{
	srand(time(NULL));
	int n = rand() % 9 + 1;
	int m = rand() % 9 + 1;
	int r = rand() % 9 + 1;
	int c = rand() % 9 + 1;
	int i = rand() % n, j = rand() % n;

	r = m;  // ��� ������������ ������

	Matrix<double> A(n, m), B(r, c), C(n, n), D;
	vector<double> b(m), d;
	for (auto& x : b)
	{
		x = rand() % 10;
		// std::cout << x << "\t";
	}

	Matrix<double> L, U;
	std::cout << "Matrix A: " << n << " x " << m << std::endl;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			A(i, j) = rand() % 10;
	std::cout << A << std::endl;


	std::cout << "Matrix B: " << rand() % 9 + 1 << " x " << c << std::endl;
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			B(i, j) = rand() % 10;
	std::cout << B << std::endl;

	std::cout << "Matrix A*B: " << std::endl;
	D = A * B;
	std::cout << D << std::endl << std::endl;

	std::cout << "Block-diagonal matrix from A and B: " << std::endl;
	D = A ^ B;
	std::cout << D << std::endl << std::endl;

	std::cout << "A | B (extended matrix): " << std::endl;
	D = A | B;
	std::cout << D << std::endl << std::endl;



	std::cout << "Change the rows " << i << " and " << j << " of matrix A: " << std::endl;
	D = A.RowChange(i, j);
	std::cout << D << std::endl << std::endl;

	std::cout << "Transposed matrix of A: " << std::endl;
	D = A.Trans();
	std::cout << D << std::endl << std::endl;

	std::cout << "Matrix A&B: " << std::endl;
	D = A & B;
	std::cout << D << std::endl << std::endl;

	std::cout << "Matrix A*b, b - vector: " << std::endl << std::endl;
	d = A * b;
	for (auto x : d)
		std::cout << x << "\t";
	std::cout << std::endl << std::endl << std::endl;

	std::cout << "Matrix C: " << n << " x " << n << std::endl;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			C(i, j) = rand() % 10;
	std::cout << C << std::endl << std::endl << std::endl;

	std::cout << "Norm of matrix C: " << C.MatrixNorm() << std::endl << std::endl;

	C.luDecomposition(L, U);

	return EXIT_SUCCESS;
}
