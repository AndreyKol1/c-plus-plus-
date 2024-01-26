#include <iostream>
#include "Functions.h"
#include <mysql.h>
#include <string>
#include < stdlib.h >
#define VK_NUMPAD0        0x60

using namespace std;
int qstate;
double height, weight, calories;
int age, id;
string Name;


MYSQL* conn;
MYSQL_ROW row;
MYSQL_RES* res = nullptr;

void Menu();
double CaloriesCountMale(double height, double weight, int age);
double CaloriesCountFemale(double height, double weight, int age);
void AddInfoToDataBase();
double ProteinInTake();
void PickGender();
void DeleteFromData(int IdToDelete);
void ShowInfo();
void AddUser();
void HeightWeightAge();


int main()
{
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
        switch (USER_CHOICE) {
        case 0:
            cout << "Closing application...";
            return 0;
            break;
        case 1:
            PickGender();
            int pick;
            cin >> pick;
            HeightWeightAge();
            cin.ignore(100, '\n');
            switch (pick) {
            case 1:
                cout << CaloriesCountMale(height, weight, age) << " grams" << endl;
                break;
            case 2:
                cout << CaloriesCountFemale(height, weight, age) << " grams" << endl;
                break;
            }
            break;
        case 2:
            cout << "If you know your average number of proteins press 1, if not press 0: ";
            cin >> pick;
            switch (pick) {
            case 0:
                cout << "The recommended dietary allowance to prevent deficiency for an average sedentary adult is 0.8 grams per kilogram of body weight." << endl;
                break;
            case 1:
                cout << ProteinInTake() << " grams" << endl;
                break;
            }
            break;
        case 3:
            AddInfoToDataBase();
            AddUser();
            break;
        case 4:
            cout << "Enter id you want to delete: ";
            cin >> id;
            DeleteFromData(id);
            break;
        case 5:
            ShowInfo();
            cout << "Enter id you want to edit: ";
            cin >> id;
            EditInfoInDataBase(id);
            break;
        case 9:
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
