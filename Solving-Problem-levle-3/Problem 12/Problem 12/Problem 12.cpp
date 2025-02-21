#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int RandomNumber(int From, int To) {

	int RandNumber = rand() % (To - From + 1) + From;

	return RandNumber;
}

void FillMatrixWithRandomNumber(int arr[3][3], short Row, short Cols) {

	for (short i = 0; i < Row; i++) {

		for (short j = 0; j < Cols; j++) {

			arr[i][j] = RandomNumber(1, 10);
		}
	}
}

bool CheckMatricesAreTypical(int Matrix1[3][3], int Matrix2[3][3], short Row, short Cols) {


	for (short i = 0; i < Row; i++) {

		for (short j = 0; j < Cols; j++) {

			if (Matrix1[i][j] != Matrix2[i][j]) {

				return false;
			}
		}
	}

	return true;
}

void PrintIfMatricesAreTypical(int Matrix1[3][3],int Matrix2[3][3],short Row , short Cols){


	string Results = (CheckMatricesAreTypical(Matrix1,Matrix2,Row,Cols)) ? "Yes : Matrices are Equal." : "No : Matrices are NOT Equal.";

	cout << "\n" << Results << endl;

}

void PrintMatrix(int Matrix[3][3], short Row, short Cols) {

	for (short i = 0; i < Row; i++) {

		for (short j = 0; j < Cols; j++) {

			printf("%0*d  ", 2, Matrix[i][j]);
		}

		cout << "\n";
	}
}

int main() {

	srand((unsigned)time(NULL));

	int Matrix1[3][3], Matrix2[3][3];

	FillMatrixWithRandomNumber(Matrix1, 3, 3);
	cout << "Matrix1 : \n";
	PrintMatrix(Matrix1, 3, 3);

	FillMatrixWithRandomNumber(Matrix2, 3, 3);
	cout << "\nMatrix2 : \n";
	PrintMatrix(Matrix2, 3, 3);

	
	PrintIfMatricesAreTypical(Matrix1, Matrix2, 3, 3);

	system("pause>0");

	return 0;

}