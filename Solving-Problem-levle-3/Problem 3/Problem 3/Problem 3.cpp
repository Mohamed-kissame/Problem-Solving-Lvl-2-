#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

int RandomNumber(int From, int To) {

	int Randnum = rand() % (To - From + 1) + From;

	return Randnum;
}

void FillMatrixWithRandomNumber(int arr[3][3], short Row, short cols) {

	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < cols; j++) {

			arr[i][j] = RandomNumber(1, 100);

		}
	}

}

void PrintMatrix(int arr[3][3], short Row, short cols) {

	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < cols; j++) {

			cout << setw(3) << arr[i][j] << " ";

		}

		cout << endl;
	}
}

int RowSum(int arr[3][3], short Rows, short Cols) {

	int sum = 0;

	for (short j = 0; j <= Cols - 1; j++) {

		sum += arr[Rows][j];

	}

	return sum;
}

void SumMatrixRowsInArray(int arr[3][3], int arrSum[3], short Rows, short cols) {

	for (short i = 0; i < Rows; i++) {

		arrSum[i] = RowSum(arr, i, cols);
	}
}

void PrintRowsSumArray(int arr[3], short Rows) {

	cout << "\nThe following are sum of each row in the matrix :\n";

	for (short i = 0; i < Rows; i++) {

		cout << "Row [ " << i + 1 << " ] Sum = " << arr[i] << endl;
	}
}

int main() {

	srand((unsigned)time(NULL));

	int arr[3][3];
	int arrSum[3];

	FillMatrixWithRandomNumber(arr, 3, 3);
	cout << "The Following is a 3x3 random matrix : \n";
	PrintMatrix(arr, 3, 3);

	SumMatrixRowsInArray(arr, arrSum, 3, 3);

	PrintRowsSumArray(arrSum, 3);

	system("pause>0");

	return 0;
}
