#include <iostream>
#include <iomanip>


using namespace std;

void PrintMatrix(int Matrix[3][3], short Row, short Cols) {

	for (short i = 0; i < Row; i++) {

		for (short j = 0; j < Cols; j++) {

			cout << setw(2) << Matrix[i][j] << "  ";
		}

		cout << "\n";
	}
}

bool IsScalarMatrix(int Matrix[3][3], short Row, short Cols) {

	int ScarlValue = Matrix[0][0];

	for (short i = 0; i < Row; i++) {

		for (short j = 0; j < Cols; j++) {

			if (i == j && Matrix[i][j]!= ScarlValue) {

				return false;
			}
			else if (i != j && Matrix[i][j]!=0) {

				return false;
			}
		}
	}

	return true;
}

void PrintIsScarlOrNot(int Matrix[3][3], short Row, short Cols) {

	string Results = (IsScalarMatrix(Matrix, Row, Cols)) ? "Yes : is Scarl Matrix." : "No : is Not Scarl Matrix.";

	cout << "\n" << Results << endl;
}

int main() {

	int Matrix[3][3] = { {9,0,0},
	                 	{0,9,0},
		                {0,0,9} };


	cout << "Matrix1 : \n";
	PrintMatrix(Matrix, 3, 3);

	PrintIsScarlOrNot(Matrix, 3, 3);

	system("pause>0");

	return 0;
}