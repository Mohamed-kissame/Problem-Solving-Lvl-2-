#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

int RandomNumber(int From, int To) {

	int RandNum = rand() % (To - From + 1) + From;

	return RandNum;
}

void Fill2DArrayRandomly(int arr[3][3], short Row, short cols) {

	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < cols; j++) {

			arr[i][j] = RandomNumber(1, 100);

		}
	}
}

void PrintMatrix(int arr[3][3], int Row, int cols) {

	for (int i = 0; i < Row; i++) {

		for (int j = 0; j < cols; j++) {

			cout << setw(3) << arr[i][j] << "  ";
		}

		cout << endl;
	}
}

int RowSum(int arr[3][3], int Row, int cols) {

	int sum = 0;

	for (short j = 0; j <= cols -1; j++) {

		sum += arr[Row][j];
		
	}

	return sum;

}

void PrintEachRowSum(int arr[3][3], int Row, int cols) {

	

	for (short i = 0; i < Row; i++) {

		cout << "Row " << i + 1 << " Sum " << RowSum(arr,i,cols);

		cout << endl;
	}
}

int main() {

	int arr[3][3];

	srand((unsigned)time(NULL));

	Fill2DArrayRandomly(arr, 3, 3);

	cout << "The Following is a 3x3 eandom matrix : \n";
	PrintMatrix(arr, 3, 3);

	cout << "\nThe following are the sum of each row in the matrix : \n";
	PrintEachRowSum(arr, 3, 3);

	return 0;
}