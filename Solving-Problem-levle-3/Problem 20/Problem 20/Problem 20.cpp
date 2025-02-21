#include <iostream>
#include <iomanip>

using namespace std;

void PrintMatrix(int Matrix[3][3], short Row, short Cols) {

	for (short i = 0; i < Row; i++) {

		for (short j = 0; j < Cols; j++) {

			cout << setw(2) << Matrix[i][j] << "   ";
		}

		cout << "\n";
	}

}


bool iSpalindromMatrix(int Matrix[3][3], short Row, short Cols) {

	

	for (short i = 0; i < Row; i++) {

		for (short j = 0; j < Cols / 2; j++) {

			if (Matrix[i][j] != Matrix[i][Cols - 1 - j]) {

				return false;
			}

		}
	}

	return true;
}

void PrintIfPlindromOrNot(int Matrix[3][3], short Row, short Cols) {

	string Results = (iSpalindromMatrix(Matrix, Row, Cols)) ? "Yes : Matrix is Palindrome." : "No : Matrix is NOT Palindrome.";

	cout << "\n" << Results << endl;
}

int main() {

	int Matrix[3][3] = { {1,2,1},{5,5,5},{7,3,7} };

	cout << "Matrix1 : \n";
	PrintMatrix(Matrix, 3, 3);

	cout << "\n";

	PrintIfPlindromOrNot(Matrix, 3, 3);

	system("pause>0");

	return 0;
}