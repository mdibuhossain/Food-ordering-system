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

int main()
{
    common obj;
    fstream myfile;
    string nm, ad;
    int ag;
    myfile.open("myText.bin", ios::out | ios::binary);

    // for (int i = 0; i < 3; i++)
    // {
    obj.getInp();
    myfile.write((char *)&obj, sizeof(common));
    // }
    myfile.close();
    myfile.open("myText.bin", ios::in | ios::binary);
    while (myfile.read((char *)&obj, sizeof(common)))
    {
        obj.display();
    }
    myfile.close();
    return 0;
}