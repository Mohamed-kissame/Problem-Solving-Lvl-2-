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

void PrintMatrix(int arr[3][3], short Row, short Cols) {

	for (short i = 0; i < Row; i++) {

		for (short j = 0; j < Cols; j++) {

			printf("%0*d   ", 2, arr[i][j]);
		}

		cout << "\n";
	}
}

int SumOfMatrix(int Matrix[3][3], short Row, short Cols) {

	int sum = 0;

	for (short i = 0; i < Row; i++) {

		for (short j = 0; j < Cols; j++) {

			sum += Matrix[i][j];
		}
	}

	return sum;
}

int main() {

	srand((unsigned)time(NULL));

	int Matrix[3][3];

	FillMatrixWithRandomNumber(Matrix, 3, 3);
	cout << "Matrix1 :\n";
	PrintMatrix(Matrix, 3, 3);

	cout << "\nSum of Matrix1 is : " << SumOfMatrix(Matrix, 3, 3) << endl;

	system("pause>0");

	return 0;
}