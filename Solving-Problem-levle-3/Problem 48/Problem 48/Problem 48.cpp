#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

const string NameClientFile = "Clients.txt";

struct stClient {

	string NameAccount;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
};

vector <string> SplitString(string s1, string Delim ) {

	vector <string> vFileContent;

	short pos = 0;

	string sWord;

	while ((pos = s1.find(Delim)) != std::string::npos) {

		sWord = s1.substr(0, pos);

		if (sWord != "") {

			vFileContent.push_back(sWord);
		}

		s1.erase(0, pos + Delim.length());
	}

	if (s1 != "") {
		vFileContent.push_back(s1);
	}

	return vFileContent;
}

stClient ConvertLineToRecord(string s1) {

	vector <string> vFileContent = SplitString(s1, "#//#");
	stClient Client;

	Client.NameAccount = vFileContent.at(0);
	Client.PinCode = vFileContent.at(1);
	Client.Name = vFileContent.at(2);
	Client.Phone = vFileContent.at(3);
	Client.AccountBalance = stod(vFileContent.at(4));

	return Client;
}

vector <stClient> LoadDataFromFileToVector(string FileName) {

	vector <stClient> VClient;

	fstream MyFile;

	MyFile.open(FileName, ios::in);

	if (MyFile.is_open()) {

		string Line;
		stClient Client;

		while (getline(MyFile, Line)) {

			Client = ConvertLineToRecord(Line);

			VClient.push_back(Client);
		}

		MyFile.close();
	}

	return VClient;
}

void PrintClientRecord(stClient Client) {

	cout << "|" << setw(15) << left << Client.NameAccount;
	cout << "|" << setw(10) << left << Client.PinCode;
	cout << "|" << setw(40) << left << Client.Name;
	cout << "|" << setw(12) << left << Client.Phone;
	cout << "|" << setw(12) << left << Client.AccountBalance;
}

void PrintAllClientData(vector <stClient> vClient) {

	cout << "\n\t\t\t\tClient List (" << vClient.size() << ") Client(s).";
	cout << "\n__________________________________________________________";
	cout << "__________________________________________________________\n" << endl;

	cout << "|" << left << setw(15) << "Account Number";
	cout << "|" << left << setw(10) << "Pin Code ";
	cout << "|" << left << setw(40) << "Client Name";
	cout << "|" << left << setw(12) << "Phone";
	cout << "|" << left << setw(12) << "Balance";

	cout << "\n__________________________________________________________";
	cout << "__________________________________________________________\n" << endl;

	for (stClient& Client : vClient) {

		PrintClientRecord(Client);

		cout << endl;
	}

	cout << "\n__________________________________________________________";
	cout << "__________________________________________________________\n";
}

int main() {

	vector <stClient> vClient = LoadDataFromFileToVector(NameClientFile);

	PrintAllClientData(vClient);

	system("pause>0");

	return 0;
}