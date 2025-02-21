#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

int RandomNumber(int From, int To) {

	int Randnum = rand() % (To - From + 1) + From;

	return Randnum;
}

void FillMatrixWithRandomNuber(int arr[3][3], short Row, short cols) {

	for (int i = 0; i < Row; i++) {

		for (int j = 0; j < cols; j++) {

			arr[i][j] = RandomNumber(1, 100);
		}
	}
}

int ColsSum(int arr[3][3], short Row, short cols) {

	int sum = 0;

	for (short i = 0; i < Row ; i++) {

		sum += arr[i][cols];

	}

	return sum;
}

void PrintMatrix(int arr[3][3], short Row, short Cols) {

	for (int i = 0; i < Row; i++) {

		for (int j = 0; j < Cols; j++) {

			cout << setw(3) << arr[i][j] << " ";
		}

		cout << endl;
	}
}

void PrintSumCols(int arr[3][3], short Rows, short Cols) {

	cout << "\nThe following are the sum of each col in the matrix : \n";

	for (short j = 0; j < Cols; j++) {

		cout << "Cols [ " << j + 1 << " ] Sum = " << ColsSum(arr, Rows, j) << endl;
	}
}

int main() {

	srand((unsigned)time(NULL));

	int arr[3][3];

	FillMatrixWithRandomNuber(arr, 3, 3);
	cout << "The following is a 3x3 random matrix :\n";
	PrintMatrix(arr, 3, 3);

	PrintSumCols(arr, 3, 3);

	return 0;
}