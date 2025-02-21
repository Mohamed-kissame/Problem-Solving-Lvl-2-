
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

const string Clientfilesname = "Clients.txt";

struct stClient {

	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
	bool MarkForDelete = false;
};

vector <string> SplitString(string s1, string Delim = "#//#") {

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

stClient ConvertLineToRecord(string Line, string sepertaor = "#//#") {

	stClient Client;

	vector <string> vClientData = SplitString(Line, sepertaor);

	Client.AccountNumber = vClientData.at(0);
	Client.PinCode = vClientData.at(1);
	Client.Name = vClientData.at(2);
	Client.Phone = vClientData.at(3);
	Client.AccountBalance = stod(vClientData.at(4));

	return Client;
}

string ConvertRecordToLine(stClient client, string seperetor = "#//#") {

	string s2 = "";

	s2 = client.AccountNumber + seperetor
		+= client.PinCode + seperetor
		+= client.Name + seperetor
		+= client.Phone + seperetor
		+= to_string(client.AccountBalance);

	return s2;
}

vector <stClient> LoadDataFromFileToVector(string NameFile) {

	vector <stClient> vClient;

	fstream MyFile;

	MyFile.open(NameFile, ios::in);

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

void PrintClient(stClient Client) {

	cout << "\nThe following are the client details:\n";

	cout << "\nAccount Number: " << Client.AccountNumber << endl;
	cout << "Pin Code      : " << Client.PinCode << endl;
	cout << "Client Name   : " << Client.Name << endl;
	cout << "Phone         : " << Client.Phone << endl;
	cout << "Account Balance : " << Client.AccountBalance << endl;

}

bool FindClientByAccountNumber(string AccountNumber, vector <stClient> vClient, stClient& Client) {

	for (stClient c : vClient) {

		if (c.AccountNumber == AccountNumber) {

			 Client = c;
			return true;
		}
	}

	return false;
}

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector <stClient>& vClient) {

	for (stClient& c : vClient) {

		if (c.AccountNumber == AccountNumber) {

			c.MarkForDelete = true;
			return true;
		}
	}

	return false;
}

void SaveVectorToFile(vector <stClient> vClients, string FileName) {

	fstream MyFile;

	MyFile.open(FileName, ios::out);

	string DataLine;

	if (MyFile.is_open()) {

		for (stClient client : vClients) {

			if (client.MarkForDelete == false) {

				DataLine = ConvertRecordToLine(client);
				MyFile << DataLine << endl;
			}

		}

		MyFile.close();
	}

}

bool DeleteClientByAccountNumber(string AccountNumber, vector <stClient>& vCLinet) {

	stClient Client;
	char Answer = 'n';

	if (FindClientByAccountNumber(AccountNumber, vCLinet, Client)) {

		PrintClient(Client);

		cout << "\n\nAre you sure you want delete this client? y/n ? ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y') {

			MarkClientForDeleteByAccountNumber(AccountNumber, vCLinet);

			SaveVectorToFile(vCLinet, Clientfilesname);

			vCLinet = LoadDataFromFileToVector(Clientfilesname);

			cout << "\n\nClient Delete Successfully.";
			return true;
		}
	}

	else {

		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
		return false;
	}
}

string ReadAccountNumberFromUser() {

	string AccountNumber;

	cout << "Please enter AccountNumber ? ";
	getline(cin, AccountNumber);

	return AccountNumber;
}

int main() {

	vector <stClient> vClients = LoadDataFromFileToVector(Clientfilesname);

	string AccountNumber = ReadAccountNumberFromUser();

	DeleteClientByAccountNumber(AccountNumber, vClients);

	system("pause>0");

	return 0;
}




