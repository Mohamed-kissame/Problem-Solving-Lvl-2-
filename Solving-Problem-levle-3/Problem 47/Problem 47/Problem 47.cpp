#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

const string ClientsFileName = "Clients.txt";

struct stClient {

	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
};

stClient ReadInfoClinet() {

	stClient Client;

	cout << "Adding New Clinet :\n\n";

	cout << "Enter Account Number ? ";
	getline(cin >> ws , Client.AccountNumber);

	cout << "Enter Pin Code ? ";
	getline(cin, Client.PinCode);

	cout << "Enter Name ? ";
	getline(cin, Client.Name);

	cout << "Enter Phone ? ";
	getline(cin, Client.Phone);

	cout << "Enter Account Balance ? ";
	cin >> Client.AccountBalance;

	return Client;
}

string ConvertDtaToLine(stClient Client , string seperatore = "#//#") {

	string stLine = Client.AccountNumber + seperatore
		+= Client.PinCode + seperatore
		+= Client.Name + seperatore
		+= Client.Phone + seperatore
		+= to_string(Client.AccountBalance);

	return stLine;
}

vector <string> SaveLineInVector( stClient Client) {

	vector <string> vFileContent;

	string Line = ConvertDtaToLine(Client, "#//#");
	vFileContent.push_back(Line);

	return vFileContent;
}

void SaveVectorToFile(string FileName, vector <string> & vFileContent) {

	fstream MyFile;

	MyFile.open(FileName, ios::out | ios::app);

	if (MyFile.is_open()) {

		for (string& Line : vFileContent) {

			if (Line != "") {

				MyFile << Line << endl;
			}
		}

		MyFile.close();
	}
}

void AddNewClient() {

	stClient Client;

	vector <string> vFileContent;

	Client = ReadInfoClinet();

	vFileContent = SaveLineInVector(Client);

	SaveVectorToFile(ClientsFileName, vFileContent);

}


void AddClients() {

	char AddMore = 'Y';

	do {

		
		AddNewClient();

		cout << "\nClient Added Successfully, Do you want to add more clients ? Y/N : ";
		cin >> AddMore;
		cin.ignore();


	     system("cls");

		 if (toupper(AddMore) == 'N') {

			 cout << "\nPlease Click ENTER to Exist : ";
			 cin.get();

		 }


	} while (toupper(AddMore) == 'Y');
}

int main() {

	AddClients();

	return 0;
}