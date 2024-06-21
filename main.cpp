#include <iostream>
#include <fstream>

using namespace std;

class User {
public:
    string name;
    string login;
    string pass;
};

class Message {
public:
    string text;
    string sender;
    string receiver;
};

void saveData(const string& fileName, const string& data) {
    ofstream file;
    file.open(fileName, ios::out);

    if (file.is_open()) {
        file << data << endl;
        file.close();

        cout << "The data is saved in:: " << fileName << endl;
    }
    else {
        cout << "The file could not be opened." << endl;
    }
}

int main() {
    User user1;
    user1.name = "John Doe";
    user1.login = "john_doe";
    user1.pass = "who123";

    Message msg;
    msg.text = "Hello, how are you?";
    msg.sender = "Alice";
    msg.receiver = "Bob";

    string userData = user1.name + ";" + user1.login + ";" + user1.pass;
    saveData("user_data.txt", userData);

    string messageData = msg.text + ";" + msg.sender + ";" + msg.receiver;
    saveData("message_data.txt", messageData);

    return 0;
}