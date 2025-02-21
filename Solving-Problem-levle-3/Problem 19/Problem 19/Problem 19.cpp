#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int RandomNumber(int From, int To) {

	int RandNumber = rand() % (To - From + 1) + From;

	return RandNumber;
}

void FillMatrixWithRandomNumber(int Matrix[3][3], short Row, short Cols) {

	for (short i = 0; i < Row; i++) {

		for (short j = 0; j < Cols; j++) {

			Matrix[i][j] = RandomNumber(1, 100);
		}
	}
}

void PrintMatrix(int Matrix[3][3], short Row, short Cols) {

	for (short i = 0; i < Row; i++) {

		for (short j = 0; j < Cols; j++) {

			cout << setw(3) << Matrix[i][j] << "    ";
		}

		cout << "\n";
	}
}

int MinNumberInMatrix(int Matrix[3][3], short Row, short Cols) {

	int Min = Matrix[0][0];

	for (short i = 0; i < Row; i++) {

		for (short j = 0; j < Cols; j++) {

			if (Matrix[i][j] < Min) {

				Min = Matrix[i][j];
			}
		}
	}

	return Min;
}

int MaxNumberInMatrix(int Matrix[3][3], short Row, short Cols) {

	int Max = Matrix[0][0];

	for (short i = 0; i < Row;i++) {
		for (short j = 0; j < Cols; j++) {

			if (Matrix[i][j] > Max) {

				Max = Matrix[i][j];
			}
		}
	}

	return Max;
}

int main() {

	srand((unsigned)time(NULL));

	int Matrix[3][3];

	FillMatrixWithRandomNumber(Matrix, 3, 3);
	cout << "Matrix1 : \n";
	PrintMatrix(Matrix, 3, 3);

	cout << endl;

	cout << "Min Number in matrix is : " << MinNumberInMatrix(Matrix, 3, 3) << endl;

	cout << "Max Number in matrix is : " << MaxNumberInMatrix(Matrix, 3, 3) << endl;

	system("pause>0");

	return 0;
}