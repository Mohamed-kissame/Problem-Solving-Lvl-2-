#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>

using namespace std;

int RandomNumber(int From, int To) {

	int Randnumber = rand() % (To - From + 1) + From;

	return Randnumber;
}

void FillMatrixWithRandomNumber(int arr[3][3], short Rows, short Cols) {

	for (int i = 0; i < Rows; i++) {

		for (int j = 0; j < Cols; j++) {

			arr[i][j] = RandomNumber(1, 100);
		}
	}
}

int ColSum(int arr[3][3], short Rows, short ColsNumber) {

	int sum = 0;

	for (short i = 0; i < Rows; i++) {

		sum += arr[i][ColsNumber];

	}

	return sum;
}

void SumMatrixColsInArray(int arr[3][3], int arrSum[3], short Rows, short Cols) {


	for (int i = 0; i < Cols; i++) {

		arrSum[i] = ColSum(arr, Rows, i);
	}

}

void PrintMatrix(int arr[3][3], short Row, short Cols) {

	for (int i = 0; i < Row; i++) {

		for (int j = 0; j < Cols; j++) {

			cout << setw(3) << arr[i][j] << " ";
		}

		cout << endl;
	}
}

void PrintColsSumArray(int arr[3], short Cols) {

	cout << "\nThe following are the sum of each cols in the matrix : \n";

	for (short j = 0; j < Cols; j++) {

		cout << "Cols [ " << j + 1 << " ] Sum = " << arr[j] << endl;
	}
}

int main() {

	srand((unsigned)time(NULL));

	int arr[3][3];
	int arrSum[3];

	FillMatrixWithRandomNumber(arr, 3, 3);
	cout << "The followin is a 3x3 random matrix : \n";
	PrintMatrix(arr, 3, 3);

	SumMatrixColsInArray(arr, arrSum, 3, 3);

	PrintColsSumArray(arrSum, 3);

	system("pause>0");

	return 0;

}