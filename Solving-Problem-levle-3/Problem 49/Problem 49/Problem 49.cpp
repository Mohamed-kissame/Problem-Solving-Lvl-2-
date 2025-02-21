#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const string ClientFileName = "Clients.txt";

struct stClient {

	string AccountName;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalnace;
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

stClient ConvertLineToRecord(string s1 , string seperator = "#//#") {

	stClient Client;
	vector <string> vClient;
	
	vClient = SplitString(s1, seperator);

   	Client.AccountName = vClient.at(0);
	Client.PinCode = vClient.at(1);
	Client.Name = vClient.at(2);
	Client.Phone = vClient.at(3);
	Client.AccountBalnace = stod(vClient.at(4));
	
	return Client;

}

vector <stClient> LoadDataFromFileToVector(string FileName) {

	vector  <stClient> vClients;

	fstream MyFile;

	MyFile.open(FileName, ios::in);

	if (MyFile.is_open()) {

		string Line;
		stClient Client;

		while (getline(MyFile, Line)) {

			Client = ConvertLineToRecord(Line);

			vClients.push_back(Client);
		}

		MyFile.close();
	}

	return vClients;
}

string ReadAccountNumber() {

	string AccountNaumber;

	cout << "Please Enter AccountNumber ? ";
	getline(cin, AccountNaumber);

	return AccountNaumber;
}

void PrintInfoClients(stClient Client) {

	

	cout << "\n\nThe following are the client details:\n\n";

	cout << "Account Number: " << Client.AccountBalnace << endl;
	cout << "Pin Code      : " << Client.PinCode << endl;
	cout << "Name          : " << Client.Name << endl;
	cout << "Phone         : " << Client.Phone << endl;
	cout << "Account Balance: " << Client.AccountBalnace << endl;
}

bool FindClient(string AccountName, stClient & Client ) {

	vector <stClient> vClient = LoadDataFromFileToVector(ClientFileName);

	for (stClient c : vClient) {

		if (c.AccountName == AccountName) {

			Client = c;

			return true;
		}
	}

	return false;
}

int main() {

	stClient Client;

	string AccountNumber = ReadAccountNumber();

	if (FindClient(AccountNumber, Client)) {

		PrintInfoClients(Client);

	}
	else {

		cout << "\nClient with Account (" << AccountNumber << ") is Not Found !";
	}

	system("pause>0");

	return 0;

}
