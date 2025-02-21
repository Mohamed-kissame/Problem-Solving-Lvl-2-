#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

const string ClientFilename = "Clients.txt";

struct stClient {

	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
	bool MarkDelete = false;
};

vector <string> SplitString(string s1, string Delim) {

	vector <string> vString;

	short pos = 0;

	string sWord;

	while ((pos = s1.find(Delim)) != std::string::npos) {

		sWord = s1.substr(0, pos);

		if (sWord != "") {

			vString.push_back(sWord);
		}

		s1.erase(0, pos + Delim.length());
	}

	if (s1 != "") {

		vString.push_back(s1);
	}

	return vString;
}

stClient ConvertLineToRecord(string s1, string seperator = "#//#") {

	vector <string> vString = SplitString(s1, seperator);

	stClient Client;

	Client.AccountNumber = vString.at(0);
	Client.PinCode = vString.at(1);
	Client.Name = vString.at(2);
	Client.Phone = vString.at(3);
	Client.AccountBalance = stod(vString.at(4));

	return Client;
}

string ConvertRecordToLine(stClient Client, string seperator = "#//#") {

	string s2 = "";

	s2 = Client.AccountNumber + seperator
		+= Client.PinCode + seperator
		+= Client.Name + seperator
		+= Client.Phone + seperator
		+= to_string(Client.AccountBalance);

	return s2;
}

vector <stClient> LoadClientDataFromFile(string FileName) {

	vector <stClient> vClient;

	fstream MyFile;

	MyFile.open(FileName, ios::in);

	if (MyFile.is_open()) {

		string Line;
		stClient Client;

		while (getline(MyFile, Line)) {

			Client = ConvertLineToRecord(Line);
			vClient.push_back(Client);
		}

		MyFile.close();
	}

	return vClient;
}

void PrintClientCard(stClient Client) {

	cout << "\nThe following are the client details:\n\n";

	cout << "Account Number  :" << Client.AccountNumber << endl;
	cout << "Pin Code        :" << Client.PinCode << endl;
	cout << "Client Name     :" << Client.Name << endl;
	cout << "Phone           :" << Client.Phone << endl;
	cout << "Account Balanece :" << Client.AccountBalance << endl;

}

bool FindClientByAccountNumber(string AccountNumber, vector <stClient> vClient, stClient& Client) {

	for (stClient C : vClient) {

		if (C.AccountNumber == AccountNumber) {

			Client = C;
			return true;
		}
	}

	return false;
}

stClient ChangeClientRecord(string AccountNumber) {

	stClient Client;

	Client.AccountNumber =  AccountNumber;

	cout << "\n\nEnter PinCode ? ";
	getline(cin >> ws, Client.PinCode);

	cout << "Enter Name ? ";
	getline(cin, Client.Name);

	cout << "Enter Phone ? ";
	getline(cin, Client.Phone);

	cout << "Enter AccountBalance ? ";
	cin >> Client.AccountBalance;

	return Client;
}

vector <stClient> SaveClientDataToFile(string Filename, vector <stClient> vClient) {

	fstream MyFile;
	MyFile.open(Filename, ios::out);

	if (MyFile.is_open()) {

		string DatLine;

		for (stClient C : vClient) {

			if (C.MarkDelete == false) {

				DatLine = ConvertRecordToLine(C);
				MyFile << DatLine << endl;
			}
		}

		MyFile.close();
	}

	return vClient;
}

bool UpdateClientByAccountNumber(string AccountNumber, vector <stClient>& vClients) {

	stClient Client;
	char answer = 'n';

	if (FindClientByAccountNumber(AccountNumber, vClients, Client)) {

		PrintClientCard(Client);

		cout << "\n\nAre you sure you want update this client? y/n ?";
		cin >> answer;

		if (answer == 'Y' || answer == 'y') {

			for (stClient& c : vClients) {

				if (c.AccountNumber == AccountNumber) {

					c = ChangeClientRecord(AccountNumber);
					break;
				}

			}

		 SaveClientDataToFile(ClientFilename ,vClients);

		 cout << "\nClient Update Successfully!\n";

		 return true;

		}

	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
	}

	return false;

}

string ReadAccountNumber() {

	string AccountNumber;

	cout << "Please enter AccountNumber ? ";
	cin >> AccountNumber;

	return AccountNumber;
}

int main() {

	vector <stClient> vClient = LoadClientDataFromFile(ClientFilename);

	string AccountNumber = ReadAccountNumber();

	UpdateClientByAccountNumber(AccountNumber, vClient);

	system("pause>0");

	return 0;
}
