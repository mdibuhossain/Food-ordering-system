#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <cstring>
#include <conio.h>
using namespace std;

class Users
{
public:
    char username[50];
    char password[80];
    void putUsername()
    {
        cin.ignore();
        cin.getline(username, 50);
    }
    void putPassword()
    {
        // cin.ignore();
        cin.getline(password, 80);
    }
    void display()
    {
        cout << username << endl
             << password << endl;
    }
};
class order
{
public:
    char foodname[50];
    long int price;
    int countity;
    void putFoodname(char fname[])
    {
        strcpy(foodname, fname);
    }
};
class information
{
public:
    char number[15];
    char address[100];
    char delivery[50];
    void putNumber()
    {
        cin.ignore();
        cin.getline(number, 15);
    }
    void putAddress()
    {
        cin.getline(address, 100);
    }
    void putDelivery(char del[])
    {
        strcpy(delivery, del);
    }
};
information person;
order ab[100];

fstream fileSystem;
string filePath = "data";
int t = 0;
long long int sum = 0;
void menu(char[]);
void breakfast(char[]);
void rice(char[]);
void chicken(char[]);
void burger(char[]);
void cake(char[]);
void info(char[]);
void oder_list(char[]);
void orderHistory(char[]);
void registerUser();
void login();

char *usernamePath(char username[])
{
    static char userPath[100];
    strcpy(userPath, "");
    strcat(userPath, "data/");
    strcat(userPath, username);
    strcat(userPath, ".bin");
    return userPath;
}

void orderHistory(char username[])
{
    fileSystem.open(usernamePath(username), ios::in | ios::binary);
    order tmpOrder;
    cout << endl;
    cout << "Food Name                "
         << "Quantity                 "
         << "Price" << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    while (fileSystem.read((char *)&tmpOrder, sizeof(order)))
    {
        int n = strlen(tmpOrder.foodname);
        cout << tmpOrder.foodname;
        for (int j = n; j < 25; j++)
            cout << " ";
        cout << tmpOrder.countity;
        string cnt = to_string(tmpOrder.countity);
        int m = cnt.size();
        for (int j = m; j < 25; j++)
            cout << " ";
        cout << tmpOrder.price;
        cout << endl;
        cout << "----------------------------------------------------------------------------" << endl;
    }
    system("pause");
}

void registerUser()
{
    cout << "    ** Register **" << endl;
    Users userObj;
    printf("%-10s : ", "Username");
    userObj.putUsername();
    printf("%-10s : ", "Password");

    int ch, i = 0;
    while (1)
    {
        ch = getch();
        if (ch == 13)
            break;
        else if (ch == 8)
        {
            i--;
            printf("*");
            continue;
        }
        else
            printf("*");
        userObj.password[i++] = (char)ch;
    }
    userObj.password[i] = '\0';

    fileSystem.open("data/users.bin", ios::app | ios::binary);
    fileSystem.write((char *)&userObj, sizeof(Users));
    fileSystem.close();
    cout << endl
         << endl
         << endl;
    system("echo Registered successfully");
    Sleep(1000);
}

void login()
{
    cout << "    ** Login **" << endl;
    Users inpObj, fileObj;
    printf("%-10s : ", "Username");
    inpObj.putUsername();
    printf("%-10s : ", "Password");

    int ch, i = 0;
    while (1)
    {
        ch = getch();
        if (ch == 13)
            break;
        else if (ch == 8)
        {
            i--;
            printf("*");
            continue;
        }
        else
            printf("*");
        inpObj.password[i++] = (char)ch;
    }
    inpObj.password[i] = '\0';

    fileSystem.open("data/users.bin", ios::in | ios::binary);
    bool flag = true;
    while (fileSystem.read((char *)&fileObj, sizeof(Users)))
    {
        if (!strcmp(fileObj.username, inpObj.username) && !strcmp(fileObj.password, inpObj.password))
        {
            flag = false;
            fileSystem.close();
            menu(inpObj.username);
        }
    }
    if (flag)
    {
        cout << endl
             << endl
             << "Incorrect username or password" << endl
             << "Try again" << endl
             << endl
             << endl
             << endl;
        system("pause");
    }
}

void menu(char username[])
{
    while (true)
    {
    loggedInmenu:
        system("cls");
        cout << "       **Menu**       " << endl;
        cout << "1. Breakfast" << endl;
        cout << "2. Rice Bowl" << endl;
        cout << "3. Chicken" << endl;
        cout << "4. Burger" << endl;
        cout << "5. Cake" << endl;
        cout << "6. Order History" << endl;
        cout << "7. Logout" << endl;
        cout << endl;
        cout << "    Choose Your Option   " << endl;
        int n;
        cin >> n;
        switch (n)
        {
        case 1:
            system("cls");
            breakfast(username);
            break;
        case 2:
            system("cls");
            rice(username);
            break;
        case 3:
            system("cls");
            chicken(username);
            break;
        case 4:
            system("cls");
            burger(username);
            break;
        case 5:
            system("cls");
            cake(username);
            break;
        case 6:
            system("cls");
            orderHistory(username);
            break;
        case 7:
            system("cls");
            return;
        default:
            cout << "Invalid command" << endl;
            Sleep(1000);
            goto loggedInmenu;
            break;
        }
    }
}

void order_list(char username[])
{
    cout << "              **Foodpanda**               " << endl;
    cout << "Name : " << username << "                    "
         << "Phone number : " << person.number << endl;
    cout << "Address : " << person.address << "                 "
         << "Delivery system : " << person.delivery << endl;
    cout << "............................................................................" << endl;
    cout << "Food Name                "
         << "Quantity & Price         "
         << "Total Price" << endl;

    for (int i = 0; i < t; i++)
    {
        int n = strlen(ab[i].foodname);

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
inpConfirm:
    cout << "1. Confirm Order" << endl;
    cout << "2. Cancel" << endl;
    int m;
    cin >> m;
    cout << endl;
    cout << endl;

    if (m == 1)
    {
        fileSystem.open(usernamePath(username), ios::app | ios::binary);
        for (int i = 0; i < t; i++)
        {
            fileSystem.write((char *)&ab[i], sizeof(order));
        }
        fileSystem.close();
        cout
            << "Oder Confirm Successfully. Thank You For Order. Wait only 30 minutes to get it." << endl;
        t = 0;
    }
    else if (m == 2)
    {
        t = 0;
        cout << "Order Successfully Cancel." << endl;
    }
    else
    {
        puts("\nInvalid command\n\n");
        goto inpConfirm;
    }
    t = 0;
    cout << endl;
}
void info(char username[])
{

    cout << "Please give your information : " << endl;
    // cout << "Name : ";
    // cin >> person.name;
    // cout << endl;
    cout << "Phone number : ";
    person.putNumber();
    cout << endl;
    cout << "Address : ";
    person.putAddress();
    cout << endl;
deliveryInp:
    cout << "Delivery system : " << endl;
    cout << "1. Cash on Delivery" << endl;
    int n;
    cin >> n;
    if (n == 1)
        person.putDelivery("Cash on Delivery");
    else
        goto deliveryInp;
    cout << endl;
    cout << endl;
    cout << "         Check your order" << endl;
    cout << endl;
    order_list(username);
}

void breakfast(char username[])
{
breakfastInp:
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
        ab[t].putFoodname("Berries");
        cout << "How many you want?" << endl;
        cin >> ab[t].countity;
        ab[t++].price = 150;
    }
    else if (n == 2)
    {
        ab[t].putFoodname("Cold Cereal");
        cout << "How many you want?" << endl;
        cin >> ab[t].countity;
        ab[t++].price = 125;
    }
    else if (n == 3)
    {
        ab[t].putFoodname("Egg");
        cout << "How many you want?" << endl;
        cin >> ab[t].countity;
        ab[t++].price = 20;
    }
    else if (n == 4)
    {
        ab[t].putFoodname("Peanut Butter");
        cout << "How many you want?" << endl;
        cin >> ab[t].countity;
        ab[t++].price = 50;
    }
    else
    {
        system("echo Invalid command");
        Sleep(1000);
        system("cls");
        goto breakfastInp;
    }
    cout << "Order add successfully" << endl;
moreBreakfastItem:
    cout << "Do you want more items?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. Exit" << endl;
    int m;
    cin >> m;
    if (m == 1)
        goto breakfastInp;
    else if (m == 2)
        info(username);
    else
        goto moreBreakfastItem;
}
void rice(char username[])
{
riceInp:
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
        ab[t].putFoodname("Butter Chicken rice");
        cout << "How many you want?" << endl;
        cin >> ab[t].countity;
        ab[t++].price = 350;
    }
    else if (n == 2)
    {
        ab[t].putFoodname("Chicken Briyani");
        cout << "How many you want?" << endl;
        cin >> ab[t].countity;
        ab[t++].price = 425;
    }
    else if (n == 3)
    {
        ab[t].putFoodname("Rice Bowl");
        cout << "How many you want?" << endl;
        cin >> ab[t].countity;
        ab[t++].price = 220;
    }
    else if (n == 4)
    {
        ab[t].putFoodname("Veg Briyani");
        cout << "How many you want?" << endl;
        cin >> ab[t].countity;
        ab[t++].price = 180;
    }
    else if (n == 5)
    {
        ab[t].putFoodname("Plain Rice");
        cout << "How many you want?" << endl;
        cin >> ab[t].countity;
        ab[t++].price = 50;
    }
    else
    {
        system("echo Invalid command");
        Sleep(1000);
        system("cls");
        goto riceInp;
    }
    cout << "Order add successfully" << endl;
moreRiceItem:
    cout << "Do you want more items?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. Exit" << endl;
    int m;
    cin >> m;
    if (m == 1)
        goto riceInp;
    else if (m == 2)
        info(username);
    else
        goto moreRiceItem;
}
void chicken(char username[])
{
chickenInp:
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
        ab[t].putFoodname("Finger Chicken");
        cout << "How many you want?" << endl;
        cin >> ab[t].countity;
        ab[t++].price = 180;
    }
    else if (n == 2)
    {
        ab[t].putFoodname("Chicken Grilled");
        cout << "How many you want?" << endl;
        cin >> ab[t].countity;
        ab[t++].price = 425;
    }
    else if (n == 3)
    {
        ab[t].putFoodname("Chicken Marsala");
        cout << "How many you want?" << endl;
        cin >> ab[t].countity;
        ab[t++].price = 220;
    }
    else if (n == 4)
    {
        ab[t].putFoodname("Chicken Prame");
        cout << "How many you want?" << endl;
        cin >> ab[t].countity;
        ab[t++].price = 180;
    }
    else if (n == 5)
    {
        ab[t].putFoodname("Chicken Wrap");
        cout << "How many you want?" << endl;
        cin >> ab[t].countity;
        ab[t++].price = 170;
    }
    else
    {
        system("echo Invalid command");
        Sleep(1000);
        system("cls");
        goto chickenInp;
    }
    cout << "Order add successfully" << endl;
moreChickenItem:
    cout << "Do you want more items?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. Exit" << endl;
    int m;
    cin >> m;
    if (m == 1)
        goto chickenInp;
    else if (m == 2)
        info(username);
    else
        goto moreChickenItem;
}
void burger(char username[])
{
burgerInp:
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
        ab[t].putFoodname("Mushroom Burger");
        cout << "How many you want?" << endl;
        cin >> ab[t].countity;
        ab[t++].price = 220;
    }
    else if (n == 2)
    {
        ab[t].putFoodname("Grilled Chicken Burger");
        cout << "How many you want?" << endl;
        cin >> ab[t].countity;
        ab[t++].price = 160;
    }
    else if (n == 3)
    {
        ab[t].putFoodname("Spicy Blast Burger");
        cout << "How many you want?" << endl;
        cin >> ab[t].countity;
        ab[t++].price = 200;
    }
    else if (n == 4)
    {
        ab[t].putFoodname("Crispy Chicken Burger");
        cout << "How many you want?" << endl;
        cin >> ab[t].countity;
        ab[t++].price = 150;
    }
    else if (n == 5)
    {
        ab[t].putFoodname("Smoked B.B.Q. Burger");
        cout << "How many you want?" << endl;
        cin >> ab[t].countity;
        ab[t++].price = 180;
    }
    else
    {
        system("echo Invalid command");
        Sleep(1000);
        system("cls");
        goto burgerInp;
    }
    cout << "Order add successfully" << endl;
moreBurgerItem:
    cout << "Do you want more items?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. Exit" << endl;
    int m;
    cin >> m;
    if (m == 1)
        goto burgerInp;
    else if (m == 2)
        info(username);
    else
        goto moreBurgerItem;
}
void cake(char username[])
{
cakeInp:
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
        ab[t].putFoodname("Black Forest Galeau");
        cout << "How many you want?" << endl;
        cin >> ab[t].countity;
        ab[t++].price = 50;
    }
    else if (n == 2)
    {
        ab[t].putFoodname("Eggless Truffle");
        cout << "How many you want?" << endl;
        cin >> ab[t].countity;
        ab[t++].price = 25;
    }
    else if (n == 3)
    {
        ab[t].putFoodname("Coffee Cake");
        cout << "How many you want?" << endl;
        cin >> ab[t].countity;
        ab[t++].price = 80;
    }
    else if (n == 4)
    {
        ab[t].putFoodname("Fudgy Chocolate");
        cout << "How many you want?" << endl;
        cin >> ab[t].countity;
        ab[t++].price = 30;
    }
    else
    {
        system("echo Invalid command");
        Sleep(1000);
        system("cls");
        goto cakeInp;
    }
    cout << "Order add successfully" << endl;
moreCakeItem:
    cout << "Do you want more items?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. Exit" << endl;
    int m;
    cin >> m;
    if (m == 1)
        goto cakeInp;
    else if (m == 2)
        info(username);
    else
        goto moreCakeItem;
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
            system("cls");
            login();
            break;
        case 2:
            system("cls");
            registerUser();
            cout << "bal" << endl;
            break;
        case 3:
            system("cls");
            exit(0);
        default:
            cout << "Invalid command" << endl;
            Sleep(1000);
            break;
        }
    }
    return 0;
}
