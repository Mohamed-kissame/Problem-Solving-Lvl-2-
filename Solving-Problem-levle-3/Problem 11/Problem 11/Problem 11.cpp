#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int RandomNumber(int From, int To) {

	int RandomNumber = rand() % (To - From + 1) + From;

	return RandomNumber;

}

void FillMatrixWithRandomNumber(int arr[3][3], short Row, short Cols) {

	for (short i = 0; i < Row;i++) {
		for (short j = 0; j < Cols;j++) {

			arr[i][j] = RandomNumber(1, 10);
		}
	}
}

int SumOfMatrix(int arr[3][3], short Row, short Cols) {

	int sum = 0;

	for (short i = 0; i < Row; i++) {

		for (short j = 0; j < Cols; j++) {

			sum += arr[i][j];
		}
	}

	return sum;
}

bool MatrixIsEquality(int Matrix1[3][3], int Matrix2[3][3],short Row , short Cols) {

	return ( SumOfMatrix(Matrix1,Row,Cols) == SumOfMatrix(Matrix2,Row,Cols));

}

void PrintMatrix(int arr[3][3], short Row, short Cols) {

	for (short i = 0; i < Row; i++) {

		for (short j = 0; j < Cols; j++) {

			printf("%0*d   ", 2, arr[i][j]);
		}

		cout << "\n";
	}
}

void PrintifequalOrNot(int Matrix1[3][3],int Matrix2[3][3],short Row , short Cols) {

	string Results;

	Results = (MatrixIsEquality(Matrix1,Matrix2,Row,Cols)) ? "Yes : Matrices are Equal." : "No : Matrcies is are NOT Equal";

	cout << "\n" << Results << endl;
}

int main() {

	srand((unsigned)time(NULL));

	int Matrix1[3][3],Matrix2[3][3];

	FillMatrixWithRandomNumber(Matrix1, 3, 3);
	cout << "Matrix1 :\n";
	PrintMatrix(Matrix1, 3, 3);

	FillMatrixWithRandomNumber(Matrix2, 3, 3);
	cout << "\nMatrix2 :\n";
	PrintMatrix(Matrix2, 3, 3);

	

	PrintifequalOrNot(Matrix1,Matrix2,3,3);

	system("pause>0");

	return 0;

}