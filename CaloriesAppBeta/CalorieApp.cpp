#include <iostream>
#include "Functions.h"
#include <mysql.h>
#include <cstring>
#define VK_NUMPAD0        0x60

using namespace std;
int qstate;
MYSQL* conn;
MYSQL_ROW row;
MYSQL_RES* res;

enum class EMenu {
    EXIT,CALCOUNT, DPC, NEWUSER, DELETEUSER,
    EDIT, SHOW = 9
};

void Menu();
double CaloriesCountMale(double height, double weight, int age);
double CaloriesCountFemale(double height, double weight, int age);
void AddInfoToDataBase(Person& someone);
double ProteinInTake(Person& someone);
void PickGender();
void DeleteFromData(int IdToDelete);
void ShowInfo();
void AddUser(Person& someone);
void HeightWeightAge(Person& someone);


int main()
{
    EMenu menu;
    Person someone;
    cout << "Greeting, this CalorieAppBeta!" << endl;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", "root", "Akoliush17042006", "Calories", 3306, NULL, 0);

    if (conn) {
        string query = "SELECT * FROM Calories";
        const char* q = query.c_str();
        qstate = mysql_query(conn, q);

        if (!qstate) {

            res = mysql_store_result(conn);
        }
        else {
            cout << "Query failed: " << mysql_error(conn) << endl;
        }
    }
    else
        puts("Connection to database has failed!");

    do {
        Menu();
        int USER_CHOICE;
        cin >> USER_CHOICE;
        menu = static_cast<EMenu>(USER_CHOICE);
        switch (menu) {
        case EMenu::EXIT:
            cout << "Closing application...";
            return 0;
            break;
        case EMenu::CALCOUNT:
            PickGender();
            int pick;
            cin >> pick;
            HeightWeightAge(someone);
            cin.ignore(100, '\n');
            switch (pick) {
            case 1:
                cout << CaloriesCountMale(someone.height, someone.weight, someone.age) << " grams" << endl;
                break;
            case 2:
                cout << CaloriesCountFemale(someone.height, someone.weight, someone.age) << " grams" << endl;
                break;
            }
            break;
        case EMenu::DPC:
            cout << "If you know your average number of proteins press 1, if not press 0: ";
            cin >> pick;
            switch (pick) {
            case 0:
                cout << "The recommended dietary allowance to prevent deficiency for an average sedentary adult is 0.8 grams per kilogram of body weight." << endl;
                break;
            case 1:
                cout << ProteinInTake(someone) << " grams" << endl;
                break;
            }
            break;
        case EMenu::NEWUSER:
            AddInfoToDataBase(someone);
            AddUser(someone);
            break;
        case EMenu::DELETEUSER:
            cout << "Enter id you want to delete: ";
            cin >> someone.id;
            DeleteFromData(someone.id);
            break;
        case EMenu::EDIT:
            ShowInfo();
            cout << "Enter id you want to edit: ";
            cin >> someone.id;
            EditInfoInDataBase(someone.id, someone);
            break;
        case EMenu::SHOW:
            ShowInfo();
            break;
        }
    } while (VK_NUMPAD0);
    mysql_free_result(res);
    mysql_close(conn);
    return 0;
}

void Menu() {
    cout << "1 - calorie counter" << endl
        << "2 - daily protein counter" << endl
        << "3 - add new user to database" << endl
        << "4 - delete user from database" << endl
        << "5 - edit info in database" << endl
        << "0 - exit program" << endl
        << "9 - show info in database" << endl;
}
