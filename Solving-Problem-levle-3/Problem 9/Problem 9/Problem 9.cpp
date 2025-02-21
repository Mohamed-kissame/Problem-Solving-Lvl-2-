#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int RandomNumber(int From, int To) {

	int RandomNumber = rand() % (To - From + 1) + From;

	return RandomNumber;
}

void FillMatrixWithRandomNumber(int arr[3][3], short Row, short Cols) {

	for (short i = 0; i < Row; i++) {

		for (short j = 0; j < Cols ;j++) {

			arr[i][j] = RandomNumber(1, 10);
		}
	}
}

void PrintMatrix(int arr[3][3], short Row, short Cols) {

	for (short i = 0; i < Row; i++) {

		for (short j = 0; j < Cols; j++) {

			printf(" %0*d   ", 2, arr[i][j]);
		}

		cout << endl;
	}
}

void PrintMiddleRowOfMatrix(int arr[3][3], short Row, short Cols) {

	for (short i = 0; i < Row; i++) {

		for (short j = 0; j < Cols; j++) {

			if (i == 1) {

				printf("%0*d   ", 2, arr[i][j]);

			}

		}
	}
}

void PrintMiddleColsOfMatrix(int arr[3][3], short Row, short Cols) {

	for (short i = 0; i < Row; i++) {

		for (short j = 0; j < Cols; j++) {

			if (j == 1) {

				printf("%0*d   ", 2, arr[i][j]);
			}
		}
	}
}

int main() {

	srand((unsigned)time(NULL));

	int Matrix[3][3];

	FillMatrixWithRandomNumber(Matrix, 3, 3);
	cout << "Matrix :\n";
	PrintMatrix(Matrix, 3, 3);

	cout << "\n\nMiddle Row of Matrix1 is : \n";
	PrintMiddleRowOfMatrix(Matrix, 3, 3);

	cout << "\n\nMiddle Cols of Matrix1 is : \n";
	PrintMiddleColsOfMatrix(Matrix, 3, 3);

	system("pause>0");

	return 0;

}