#include <iostream>
#include <iomanip>

using namespace std;

void FillMatrixWithOrderNumber(int arr[3][3], short Row, short Cols) {

	int counter = 0;

	for (short i = 0; i < Row; i++) {

		for (short j = 0; j < Cols; j++) {

			counter++;

			arr[i][j] = counter;
		}
	}
}

void TransposeMatrix(int arr[3][3], int arrTranspore[3][3], short Row, short Cols) {

	for (short i = 0; i < Row; i++) {

		for (short j = 0; j < Cols; j++) {

			arrTranspore[i][j] = arr[j][i];
		}
	}
}

void PrintMatrix(int arr[3][3], short Row, short Cols) {

	for (short i = 0; i < Row; i++) {

		for (short j = 0; j < Cols; j++) {

			cout << setw(2) << arr[i][j] << "  ";
		}

		cout << "\n";
	}
}

int main() {

	int arr[3][3], arrTransposed[3][3];

	FillMatrixWithOrderNumber(arr, 3, 3);

	cout << "The following is a 3x3 ordered matrix :\n";
	PrintMatrix(arr, 3, 3);

	TransposeMatrix(arr, arrTransposed, 3, 3);

	cout << "\n\nThe following is the transposed matrix:\n";
	PrintMatrix(arrTransposed, 3, 3);

	system("pause>0");

	return 0;
}