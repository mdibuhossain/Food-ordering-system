#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class common
{
public:
    char name[50];
    char address[100];
    int age;
    void getInp()
    {
        cout << "::::input::::" << endl;
        cin.getline(name, 50);
        cin.getline(address, 100);
        cin >> age;
        cin.ignore();
    }
    void display()
    {
        cout << name << " " << address << " " << age << endl;
    }
};

string filePath = "data";

// char *usernamePath(char username[])
// {
//     string userPath = "/data/" + username + ".bin";
//     char *final = new char[userPath.size() + 1];
//     strcpy(final, userPath.c_str());
//     return final;
// }

char *intoUserData(char username[])
{
    static char fileName[100];
    strcpy(fileName, "");
    strcat(fileName, "data/");
    strcat(fileName, username);
    strcat(fileName, ".bin");
    return fileName;
}

int main()
{
    fstream file;
    char username[] = "Ibrahim";
    // cout << usernamePath(username) << endl;
    file.open(intoUserData(username), ios::app);
    file.close();
    return 0;
}