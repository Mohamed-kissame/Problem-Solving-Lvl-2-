#include <iostream>
#include <iomanip>

using namespace std;

void PrintMatrix(int Matrix[3][3], short Row, short Cols) {

	for (short i = 0; i < Row; i++) {

		for (short j = 0; j < Cols; j++) {

			cout << setw(2) << Matrix[i][j] << "    ";
		}

		cout << "\n";
	}
}

short CountTheZerosInMatrix(int Matrix[3][3], short Row, short Cols) {

	short ZerosCount = 0; 

	for (short i = 0; i < Row; i++) {

		for (short j = 0; j < Cols; j++) {

			if (Matrix[i][j] == 0) {

				ZerosCount++;
			}
		}
	}

	return ZerosCount;
}

bool IsSparse(int Matrix[3][3], short Row, short Cols) {

	return (CountTheZerosInMatrix(Matrix, Row, Cols) >= (Row * Cols) / 2);
}

void PrintIfSparseOrNot(int Matrix[3][3], short Row, short Cols) {

	string Results = (IsSparse(Matrix, Row, Cols)) ? "Yes : is Sparse." : "No : matrix NOT Sparse.";

	cout << "\n" << Results << endl;
}

int main() {

	int Matrix1[3][3] = { {9,0,9},{0,0,7},{0,0,12} };

	cout << "Mtrix1 :\n";
	PrintMatrix(Matrix1, 3, 3);

	PrintIfSparseOrNot(Matrix1, 3, 3);

	system("pause>0");

	return 0;
}