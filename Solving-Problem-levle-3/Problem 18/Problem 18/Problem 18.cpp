#include <iostream>
#include <iomanip>

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

		for (short j = 0; j < Cols;j++) {

			cout << setw(3) << Matrix[i][j] << "     ";
		}

		cout << "\n";
	}
}

bool IsNumberInMatrix(int Matrix[3][3], int Number, short Row, short Cols) {

	for (short i = 0; i < Row; i++) {

		for (short j = 0; j < Cols; j++) {

			if (Matrix[i][j] == Number) {

				return true;
			}
		}
	}

	return false;
}

void PrintIntersectedNumbers(int Matrix1[3][3], int Matrix2[3][3], short Row, short Cols) {

	int Number = 0;

	for (short i = 0; i < Row; i++) {

		for (short j = 0; j < Cols; j++) {

			Number = Matrix1[i][j];

			if (IsNumberInMatrix(Matrix2, Number, Row, Cols)) {

				cout << setw(3) << Number << "     ";
			}
		}
	}

}

int main() {

	srand((unsigned)time(NULL));

	int Matrix1[3][3], Matrix2[3][3];

	FillMatrixWithRandomNumber(Matrix1, 3, 3);
	cout << "Matrix1 : \n";
	PrintMatrix(Matrix1, 3, 3);

	FillMatrixWithRandomNumber(Matrix2, 3, 3);
	cout << "\nMatrix2 :\n";
	PrintMatrix(Matrix2, 3, 3);

	cout << "\nIntersected Numbers are :\n\n";
	PrintIntersectedNumbers(Matrix1, Matrix2, 3, 3);

	system("pause>0");
}