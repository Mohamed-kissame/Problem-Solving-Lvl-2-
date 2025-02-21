#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int RandomNumber(int From, int To) {

	int Randomnum = rand() % (To - From + 1) + From;

	return Randomnum;
}

void FillMatrixWithRandomNumber(int arr[3][3], short Row, short Cols) {

	for (short i = 0; i < Row; i++) {

		for (short j = 0; j < Cols; j++) {

			arr[i][j] = RandomNumber(1, 10);
		}
	}
}

void PrintMatrix(int arr[3][3], short Row, short Cols) {

	for (short i = 0; i < Row; i++) {

		for (short j = 0; j < Cols; j++) {

			printf("%0*d  ", arr[i][j]);
		}

		cout << "\n";
	}
}

void MultiplyTwoMatrix(int matrix1[3][3], int matrix2[3][3], int Results[3][3], short Row, short Cols) {

	for (short i = 0; i < Row; i++) {

		for (short j = 0; j < Cols; j++) {

			Results[i][j] = matrix1[i][j] * matrix2[i][j];
		}
	}
}

int main() {

	srand((unsigned)time(NULL));

	int matrix1[3][3], matrix2[3][3], MatrixResults[3][3];

	FillMatrixWithRandomNumber(matrix1, 3, 3);
	cout << "Matrix1 : \n\n ";
	PrintMatrix(matrix1, 3, 3);

	FillMatrixWithRandomNumber(matrix2, 3, 3);
	cout << "\n\nMatrix2 : \n";
	PrintMatrix(matrix2, 3, 3);

	MultiplyTwoMatrix(matrix1, matrix2, MatrixResults, 3, 3);

	cout << "\n\nResults : \n";
	PrintMatrix(MatrixResults, 3, 3);

	return 0;
}
