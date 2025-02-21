#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;


int ReadNumber() {

	int Number = 0;

	cout << "Please Enter the number to look for in matrix ? : ";
	cin >> Number;

	while (cin.fail()) {

		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		cout << "Invalide Input , Please enter a valide number : ";
		cin >> Number;
	}

	return Number;
}

int RandomNumber(int From, int To) {

	int RandmNumber = rand() % (To - From + 1) + From;

	return RandmNumber;
}

void FillMatrixWithRandomNumber(int Matrix1[3][3], short Row, short Cols) {

	for (short i = 0; i < Row; i++) {

		for (short j = 0; j < Cols; j++) {

			Matrix1[i][j] = RandomNumber(1, 100);
		}
	}
}

void Printmatrix(int Matrxi[3][3], short Row, short Cols) {

	for (short i = 0; i < Row; i++) {

		for (short j = 0; j < Cols; j++) {

			cout << setw(3) << Matrxi[i][j] << "    ";
		}

		cout << "\n";
	}
}

bool IsFounde(int Matrix[3][3], int Number,short Row, short Cols) {


	for (short i = 0; i < Row; i++) {

		for (short j = 0; j < Cols; j++) {

			if (Matrix[i][j] == Number) {

				return true;
			}
		}

		
	}

	return false;
}

void PrintIfTheNumberInMatrix(int Matrix[3][3], int Number, short Row, short Cols) {

	string Results = (IsFounde(Matrix, Number, Row, Cols)) ? "Yes it is there." : "Not Founde in matrix.";

	cout << "\n" << Results << endl;
}

int main() {

	srand((unsigned)time(NULL));

	int Matrix[3][3] ;

	FillMatrixWithRandomNumber(Matrix, 3, 3);
	cout << "Mtrix1 :\n";
	Printmatrix(Matrix, 3, 3);

	cout << endl;

	int Number = ReadNumber();

	PrintIfTheNumberInMatrix(Matrix, Number, 3, 3);

	system("pause>0");

	return 0;
}

