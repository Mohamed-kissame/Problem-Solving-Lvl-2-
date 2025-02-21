#include <iostream>
#include <iomanip>

using namespace std;

int ReadNumber() {

	int Number = 0;

	cout << "Enter The Number to count in matrix : ";
	cin >> Number;

	while (cin.fail()) {

		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		cout << "Invalid Input , Please enete a valide number : ";
		cin >> Number;
	}

	return Number;
}

void PrintMatrix(int Matrix[3][3], short Row, short Cols) {

	for (short i = 0; i < Row; i++) {

		for (short j = 0; j < Cols; j++) {

			cout << setw(2) << Matrix[i][j] << "  ";
		}

		cout << "\n";
	}
}

short CountNumberInMatrix(int Matrix[3][3], int Number, short Row, short Cols) {

	short Counter = 0;

	for (short i = 0; i < Row; i++) {

		for (short j = 0; j < Cols; j++) {

			if (Matrix[i][j] == Number) {

				Counter++;
			}
		}

	}

	return Counter;
}

int main() {

	int Matrix[3][3] = { {9,1,12},{0,9,1},{0,9,9} };

	cout << "Matrix1 : \n";
	PrintMatrix(Matrix, 3, 3);

	cout << "\n";

	int Number = ReadNumber();

	cout << "\nNumber " << Number << " count in matrix is " << CountNumberInMatrix(Matrix, Number, 3, 3);

	system("pause>0");

	return 0;
}