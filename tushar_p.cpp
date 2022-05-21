#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

class Users
{
public:
    char username[50];
    char password[80];
};
class order
{
public:
    string foodname;
    long int price;
    int countity;
};
class information
{
public:
    string name;
    long long int number;
    string address;
    string del;
};
information person;
order ab[100];

fstream fileSystem;
string filePath = "data";
int t = 0;
long long int sum = 0;
void breakfast();
void rice();
void chicken();
void burger();
void cake();
void registerUser();

void registerUser()
{
    cout << "    ** Register **" << endl;
    Users userObj;
    fileSystem.open("data/bal", ios::app | ios::binary);
    system("pause");
}

void menu()
{
    cout << "       **Menu**       " << endl;
    cout << "1. Breakfast" << endl;
    cout << "2. Rice Bowl" << endl;
    cout << "3. Chicken" << endl;
    cout << "4. Burger" << endl;
    cout << "5. Cake" << endl;
    cout << "6. Logout" << endl;
    cout << endl;
    cout << "    Choose Your Option   " << endl;
    int n;
    cin >> n;
    switch (n)
    {
    case 1:
        breakfast();
        break;
    case 2:
        rice();
        break;
    case 3:
        chicken();
        break;
    case 4:
        burger();
        break;
    case 5:
        cake();
        break;
    case 6:
        return;
    default:
        cout << "Invalid command" << endl;
        Sleep(1000);
        break;
    }
}

void order_list()
{
    cout << "              **Foodpanda**               " << endl;
    cout << "Name : " << person.name << "                    "
         << "Phone number : 0" << person.number << endl;
    cout << "Address : " << person.address << "                 "
         << "Delivery system : " << person.del << endl;
    cout << "............................................................................" << endl;
    cout << "Food Name                "
         << "Quantity & Price         "
         << "Total Price" << endl;

    for (int i = 0; i < t; i++)
    {
        int n = ab[i].foodname.size();

        cout << i + 1 << ". " << ab[i].foodname;
        for (int j = n; j <= 25; j++)
            cout << " ";
        cout << ab[i].countity << " X " << ab[i].price << "                 " << ab[i].countity * ab[i].price;
        sum += (ab[i].countity * ab[i].price);
        cout << endl;
    }
    cout << "............................................................................" << endl;
    cout << "                                             Total Bill = " << sum << endl;
    cout << endl;
    cout << "1. Confirm Order" << endl;
    cout << "2. Cancel" << endl;
    int m;
    cin >> m;
    cout << endl;
    cout << endl;

    if (m == 1)
        cout << "Oder Confirm Successfully. Thank You For Order. Wait only 30 minutes to get it." << endl;
    else
        cout << "Order Successfully Cancel." << endl;
    cout << endl;
}
void info()
{

    cout << "Please give your information : " << endl;
    cout << "Name : ";
    cin >> person.name;
    cout << endl;
    cout << "Phone number : ";
    cin >> person.number;
    cout << endl;
    cout << "Address : ";
    cin >> person.address;
    cout << endl;
    cout << "Delivery system : " << endl;
    cout << "1. Cash on Delivery" << endl;
    int n;
    cin >> n;
    if (n == 1)
        person.del = "Cash on Delivery";
    cout << endl;
    cout << endl;
    cout << "         Check your order" << endl;
    cout << endl;
    order_list();
}

void breakfast()
{
    cout << "-->Breakfast        --->Price" << endl;
    cout << "1. Berries              150/-" << endl;
    cout << "2. Cold Cereal          125/-" << endl;
    cout << "3. Egg                   20/-" << endl;
    cout << "4. Peanut Butter         50/-" << endl;
    cout << endl;
    cout << "     Choose Your Option   " << endl;
    int n;
    cin >> n;
    if (n == 1)
    {
        ab[t].foodname = "Berries";
        cout << "How many you want?" << endl;
        cin >> ab[t].countity;
        ab[t++].price = 150;
    }
    else if (n == 2)
    {
        ab[t].foodname = "Cold Cereal";
        cout << "How many you want?" << endl;
        cin >> ab[t].countity;
        ab[t++].price = 125;
    }
    else if (n == 3)
    {
        ab[t].foodname = "Egg";
        cout << "How many you want?" << endl;
        cin >> ab[t].countity;
        ab[t++].price = 20;
    }
    else if (n == 4)
    {
        ab[t].foodname = "Peanut Butter";
        cout << "How many you want?" << endl;
        cin >> ab[t].countity;
        ab[t++].price = 50;
    }
    cout << "Order add successfully" << endl;
    cout << "Do you want more items?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. Exit" << endl;
    int m;
    cin >> m;
    if (m == 1)
        menu();
    else
        info();
}
void rice()
{
    cout << "-->Rice Bowl              --->Price" << endl;
    cout << "1. Butter Chicken rice         350/-" << endl;
    cout << "2. Chicken Briyani             425/-" << endl;
    cout << "3. Rice Bowl                   220/-" << endl;
    cout << "4. Veg Briyani                 180/-" << endl;
    cout << "5. Plain Rice                   50/-" << endl;
    cout << endl;
    cout << "     Choose Your Option   " << endl;
    int n;
    cin >> n;
    if (n == 1)
    {
        ab[t].foodname = "Butter Chicken rice";
        cout << "How many you want?" << endl;
        cin >> ab[t].countity;
        ab[t++].price = 350;
    }
    else if (n == 2)
    {
        ab[t].foodname = "Chicken Briyani";
        cout << "How many you want?" << endl;
        cin >> ab[t].countity;
        ab[t++].price = 425;
    }
    else if (n == 3)
    {
        ab[t].foodname = "Rice Bowl";
        cout << "How many you want?" << endl;
        cin >> ab[t].countity;
        ab[t++].price = 220;
    }
    else if (n == 4)
    {
        ab[t].foodname = "Veg Briyani";
        cout << "How many you want?" << endl;
        cin >> ab[t].countity;
        ab[t++].price = 180;
    }
    else
    {
        ab[t].foodname = "Plain Rice";
        cout << "How many you want?" << endl;
        cin >> ab[t].countity;
        ab[t++].price = 50;
    }
    cout << "Order add successfully" << endl;
    cout << "Do you want more items?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. Exit" << endl;
    int m;
    cin >> m;
    if (m == 1)
        menu();
    else
        info();
}
void chicken()
{
    cout << "-->Chicken              --->Price" << endl;
    cout << "1. Finger Chicken            180/-" << endl;
    cout << "2. Chicken Grilled            425/-" << endl;
    cout << "3. Chicken Marsala           220/-" << endl;
    cout << "4. Chicken Prame             180/-" << endl;
    cout << "5. Chicken Wrap              170/-" << endl;
    cout << endl;
    cout << "     Choose Your Option   " << endl;
    int n;
    cin >> n;
    if (n == 1)
    {
        ab[t].foodname = "Finger Chicken";
        cout << "How many you want?" << endl;
        cin >> ab[t].countity;
        ab[t++].price = 180;
    }
    else if (n == 2)
    {
        ab[t].foodname = "Chicken Grilled";
        cout << "How many you want?" << endl;
        cin >> ab[t].countity;
        ab[t++].price = 425;
    }
    else if (n == 3)
    {
        ab[t].foodname = "Chicken Marsala";
        cout << "How many you want?" << endl;
        cin >> ab[t].countity;
        ab[t++].price = 220;
    }
    else if (n == 4)
    {
        ab[t].foodname = "Chicken Prame";
        cout << "How many you want?" << endl;
        cin >> ab[t].countity;
        ab[t++].price = 180;
    }
    else
    {
        ab[t].foodname = "Chicken Wrap";
        cout << "How many you want?" << endl;
        cin >> ab[t].countity;
        ab[t++].price = 170;
    }
    cout << "Order add successfully" << endl;
    cout << "Do you want more items?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. Exit" << endl;
    int m;
    cin >> m;
    if (m == 1)
        menu();
    else
        info();
}
void burger()
{
    cout << "-->Burger                 --->Price" << endl;
    cout << "1. Mushroom Burger            200/-" << endl;
    cout << "2. Grilled Chicken Burger     160/-" << endl;
    cout << "3. Spicy Blast Burger         200/-" << endl;
    cout << "4. Crispy Chicken Burger      150/-" << endl;
    cout << "5. Smoked B.B.Q. Burger       180/-" << endl;
    cout << endl;
    cout << "     Choose Your Option   " << endl;
    int n;
    cin >> n;
    if (n == 1)
    {
        ab[t].foodname = "Mushroom Burger";
        cout << "How many you want?" << endl;
        cin >> ab[t].countity;
        ab[t++].price = 220;
    }
    else if (n == 2)
    {
        ab[t].foodname = "Grilled Chicken Burger";
        cout << "How many you want?" << endl;
        cin >> ab[t].countity;
        ab[t++].price = 160;
    }
    else if (n == 3)
    {
        ab[t].foodname = "Spicy Blast Burger";
        cout << "How many you want?" << endl;
        cin >> ab[t].countity;
        ab[t++].price = 200;
    }
    else if (n == 4)
    {
        ab[t].foodname = "Crispy Chicken Burger";
        cout << "How many you want?" << endl;
        cin >> ab[t].countity;
        ab[t++].price = 150;
    }
    else
    {
        ab[t].foodname = "Smoked B.B.Q. Burger";
        cout << "How many you want?" << endl;
        cin >> ab[t].countity;
        ab[t++].price = 180;
    }
    cout << "Order add successfully" << endl;
    cout << "Do you want more items?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. Exit" << endl;
    int m;
    cin >> m;
    if (m == 1)
        menu();
    else
        info();
}
void cake()
{
    cout << "--->Cake                   --->Price" << endl;
    cout << "1. Black Forest Galeau         50/-" << endl;
    cout << "2. Eggless Truffle             25/-" << endl;
    cout << "3. Coffee Cake                 80/-" << endl;
    cout << "4. Fudgy Chocolate             30/-" << endl;
    cout << endl;
    cout << "     Choose Your Option   " << endl;
    int n;
    cin >> n;
    if (n == 1)
    {
        ab[t].foodname = "Black Forest Galeau";
        cout << "How many you want?" << endl;
        cin >> ab[t].countity;
        ab[t++].price = 50;
    }
    else if (n == 2)
    {
        ab[t].foodname = "Eggless Truffle";
        cout << "How many you want?" << endl;
        cin >> ab[t].countity;
        ab[t++].price = 25;
    }
    else if (n == 3)
    {
        ab[t].foodname = "Coffee Cake";
        cout << "How many you want?" << endl;
        cin >> ab[t].countity;
        ab[t++].price = 80;
    }
    else if (n == 4)
    {
        ab[t].foodname = "Fudgy Chocolate";
        cout << "How many you want?" << endl;
        cin >> ab[t].countity;
        ab[t++].price = 30;
    }

    cout << "Order add successfully" << endl;
    cout << "Do you want more items?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. Exit" << endl;
    int m;
    cin >> m;
    if (m == 1)
        menu();
    else
        info();
}

int main()
{
    while (true)
    {
        string path = "md " + filePath;
        char *pathChar = &path[0];
        system(pathChar);
        system("cls");
        cout << "    **Foodpanda**     " << endl;
        cout << "    **Homepage**     " << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Exit" << endl;
        cout << endl;
        cout << "    Choose Your Option   " << endl;
        int inp;
        cin >> inp;
        switch (inp)
        {
        case 1:

            cout << "bal" << endl;
            break;
        case 2:
            registerUser();
            cout << "bal" << endl;
            break;
        case 3:
            exit(0);
        default:
            cout << "Invalid command" << endl;
            Sleep(1000);
            break;
        }
    }
    return 0;
}
