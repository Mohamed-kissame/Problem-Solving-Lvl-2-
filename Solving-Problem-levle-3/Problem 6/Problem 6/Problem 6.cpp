#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void FillMatrixWithOrderNumber(int arr[3][3], short Row, short Cols) {

	short counter = 0;


	for (int i = 0; i < Row; i++) {

		for (int j = 0; j < Cols; j++) {

			counter++;

			arr[i][j] = counter;

		}

		
	}
}

void PrintMatrix(int arr[3][3], short Row, short Cols) {

	for (int i = 0; i < Row; i++) {

		for (int j = 0; j < Cols; j++) {

			cout << setw(3) << arr[i][j] << "    ";
		}

		cout << endl;
	}
}

int main() {

	int arr[3][3];

	FillMatrixWithOrderNumber(arr, 3, 3);
	cout << "The following is a 3x3 ordered matrix:\n";

	PrintMatrix(arr, 3, 3);

	return 0;
}