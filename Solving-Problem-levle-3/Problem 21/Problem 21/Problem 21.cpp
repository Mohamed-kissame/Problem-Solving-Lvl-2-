#include <iostream>
#include <string>

using namespace std;

void PrintFibonacciUsingLoop(int Number) {

	int Prev1 = 0, Prev2 = 1 , FebNumber = 0;

	cout << Prev2 << "\t";

	for (int i = 1; i < Number;i++) {

	 FebNumber = Prev1 + Prev2;

		cout << FebNumber << "\t";

		Prev1 = Prev2;
		Prev2 = FebNumber;
	
	}
}

int main() {

	PrintFibonacciUsingLoop(10);

	system("pause>0");
}