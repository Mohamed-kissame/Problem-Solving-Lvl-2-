#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int RandomNumber(int From, int To) {

	int randnum = rand() % (To - From + 1) + From;

	return randnum;
}

void Fill2DArrayRandomly(int arr[3][3], short Row, short cols) {

	for (int i = 0; i < Row; i++) {

		for (int j = 0; j < cols; j++) {


			arr[i][j] = RandomNumber(1, 100);


		}
	}
}

void PrintMatrix(int arr[3][3], short Row, short cols) {

	for (int i = 0; i < Row;i++) {

		for (int j = 0; j < cols; j++) {

			cout << setw(3) << arr[i][j] << "  ";
		}

		cout << endl;

	}
}

int main() {

	srand((unsigned)time(NULL));

	int arr[3][3];


	Fill2DArrayRandomly(arr, 3, 3);

	cout << "The following is a 3x3 random matrix : \n";

	PrintMatrix(arr, 3, 3);


	return 0;
}

	