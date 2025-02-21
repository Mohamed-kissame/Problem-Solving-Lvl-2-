#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void PrintMatrix(int Matrix[3][3], short Row, short Cols) {

	for (short i = 0; i < Row; i++) {

		for (short j = 0; j < Cols; j++) {

			cout << setw(2) << Matrix[i][j] << "  ";

		}

		cout << "\n";
	}
}

bool MatrixIsIdentity(int Matrix[3][3], short Row, short Cols) {

	for (short i = 0; i < Row; i++) {

		for (short j = 0; j < Cols; j++) {

			if (i == j && Matrix[i][j] != 1) {

				return false;
			}
			else if (i != j && Matrix[i][j] != 0) {

				return false;
			}
		}
	}

	return true;
}

void PrintIfMatrixIsIdentity(int Matrix[3][3], short Row, short Cols) {

	string Results = (MatrixIsIdentity(Matrix, Row, Cols)) ? "Yes : Matrix is identity." : "No : Mtrix is NOT identity.";

	cout << "\n" << Results << endl;
}

int main() {

	int Matrix[3][3] = { {1,0,0},
	                     {0,1,0}, 
		                 {0,0,1} };

	cout << "Matrix1 : \n";
	PrintMatrix(Matrix, 3, 3);

	PrintIfMatrixIsIdentity(Matrix, 3, 3);

	return 0;
}