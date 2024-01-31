#include <iostream>
#include <mysql.h>
#include <string>
#define VK_NUMPAD0        0x60

using namespace std;


struct Person {
	int age, id;
	string Name;
	double height, weight, calories;
};

extern int qstate;
extern	MYSQL* conn;
extern	MYSQL_ROW row;
extern	MYSQL_RES* res;



void PickGender();
double CaloriesCountMale(double height, double weight, int age);
double CaloriesCountFemale(double height, double weight, int age);
double ProteinInTake(Person& someone);
void AddInfoToDataBase(Person& someone);
void ShowInfo();
void DeleteFromData(int IdToDelete);
void HeightWeightAge(Person& someone);
void EditInfoInDataBase(int idToEdit, Person& someone);
void AddUser(Person& someone);

void PickGender() {
	cout << "Pick for whom you want to count calories" << endl
		<< "1 - Male" << endl
		<< "2 - Female" << endl;
}

double CaloriesCountMale(double height, double weight, int age) {
	cout << "Your daily calorie allowance: ";
	return (13.75 * weight) + (5 * height) - (6.76 * age) + 655;
}
double CaloriesCountFemale(double height, double weight, int age) {
	cout << "Your daily calorie allowance: ";
	return (9.56 * weight) + (1.85 * height) - (4.68 * age) + 655;
}
double ProteinInTake(Person& someone) {
	double protein;
	cout << "Enter your estimated protein per kilos: ";
	cin >> protein;
	cout << "Enter your weight: ";
	cin >> someone.weight;
	cin.ignore(100, '\n');
	cout << "Your daily protein intake: ";
	return someone.weight * protein;
}
void AddInfoToDataBase(Person& someone) {
	cout << "Enter your name: ";
	cin >> someone.Name;
	cout << "Enter your age: ";
	cin >> someone.age;
	cout << "Enter your height: ";
	cin >> someone.height;
	cout << "Enter your weight: ";
	cin >> someone.weight;
	cout << "Enter your daily calories taken from the calculations: ";
	cin >> someone.calories;
}

void ShowInfo() {
	if (res) {
		while (row = mysql_fetch_row(res)) {
			cout << "ID: " << row[0]
				<< " Name: " << row[1]
				<< " Age: " << row[2]
				<< " height: " << row[3]
				<< " weight: " << row[4]
				<< " calories: " << row[5] << endl;
		}
	mysql_data_seek(res, 0);
	}
}

void DeleteFromData(int IdToDelete)
{
	string DeleteQuery = "DELETE FROM calories WHERE ID =" + to_string(IdToDelete);
	qstate = mysql_query(conn, DeleteQuery.c_str());

	if (!qstate) {

		cout << "Record deleted successfully!" << endl;
	}
	else {
		cout << "Error deleting: " << mysql_error(conn) << endl;
	}
}

void HeightWeightAge(Person& someone) {
	cout << "Your height: ";
	cin >> someone.height;
	cout << "Your weight: ";
	cin >> someone.weight;
	cout << "Your age: ";
	cin >> someone.age;
}
void UpdateName(int idToEdit) {
	string NewName;
	cout << "Enter new name: ";
	cin.ignore();
	cin >> NewName;

	string updateQuery = "UPDATE Calories SET Name = '" + NewName + "' WHERE ID = " + to_string(idToEdit);
	qstate = mysql_query(conn, updateQuery.c_str());

	if (!qstate)
		cout << "Name updated successfully!" << endl;
	else
		cout << "Error updating name: " << mysql_error(conn) << endl;

	mysql_free_result(res);
}
void UpdateAge(int idToEdit) {
	int NewAge;
	cout << "Enter new age: ";
	cin >> NewAge;
	string updateQuery = "UPDATE calories SET age = " + to_string(NewAge) + " WHERE ID = " + to_string(idToEdit);
	qstate = mysql_query(conn, updateQuery.c_str());
	if (!qstate)
		cout << "Age updated successfully!" << endl;
	else
		cout << "Error updating age: " << mysql_error(conn) << endl;
	mysql_free_result(res);
}
void UpdateHeight(int idToEdit) {
	double NewHeight;
	cout << "Enter new height: ";
	cin >> NewHeight;
	string updateQuery = "UPDATE calories SET height = " + to_string(NewHeight) + " WHERE ID = " + to_string(idToEdit);
	qstate = mysql_query(conn, updateQuery.c_str());
	if (!qstate)
		cout << "Height updated successfully!" << endl;
	else
		cout << "Error updating height: " << mysql_error(conn) << endl;
	mysql_free_result(res);
}
void UpdateWeight(int idToEdit) {
	double NewWeight;
	cout << "Enter new weight: ";
	cin >> NewWeight;
	string updateQuery = "UPDATE calories SET weight = " + to_string(NewWeight) + " WHERE ID = " + to_string(idToEdit);
	qstate = mysql_query(conn, updateQuery.c_str());
	if (!qstate)
		cout << "Weight updated successfully!" << endl;
	else
		cout << "Error updating weight: " << mysql_error(conn) << endl;
	mysql_free_result(res);
}
void UpdateCalories(int idToEdit) {
	double NewCalories;
	cout << "Enter new amount of calories: ";
	cin >> NewCalories;
	string updateQuery = "UPDATE calories SET calories = " + to_string(NewCalories) + " WHERE ID = " + to_string(idToEdit);
	qstate = mysql_query(conn, updateQuery.c_str());
	if (!qstate)
		cout << "Calories updated successfully!" << endl;
	else
		cout << "Error updating Calories: " << mysql_error(conn) << endl;
	mysql_free_result(res);
}

void EditInfoInDataBase(int idToEdit, Person& someone)
{
	string selectQuery = "SELECT * FROM calories WHERE ID = " + to_string(idToEdit);
	qstate = mysql_query(conn, selectQuery.c_str());
	if (!qstate) {

		res = mysql_store_result(conn);
	}
	else {
		cout << "Error deleting: " << mysql_error(conn) << endl;
	}

	do
	{
		int number;
		cout << "1 - Name" << endl
			<< "2 - Age" << endl
			<< "3 - Height" << endl
			<< "4 - Weight" << endl
			<< "5 - Calories intake" << endl
			<< "0 - stop editing" << endl;
		cout << "Enter new information you want to update:" << endl;
		cin >> number;
		switch (number) {
		case 0:
			cout << "Stopping program..." << endl;
			return;
			break;
		case 1:
			UpdateName(idToEdit);
			break;
		case 2:
			UpdateAge(idToEdit);
			break;
		case 3:
			UpdateHeight(idToEdit);
			break;
		case 4:
			UpdateWeight(idToEdit);
			break;
		case 5:
			UpdateCalories(idToEdit);
			break;
		}
	} while (VK_NUMPAD0);
}
void AddUser(Person& someone)
{
	string insertQuery;
	insertQuery = "INSERT INTO Calories ( Name, Age, Height, Weight, Calories) VALUES ('" + someone.Name + "'," + to_string(someone.age)
		+ ", " + to_string(someone.height) + ", " + to_string(someone.weight) + ", " + to_string(someone.calories) + ")";

	qstate = mysql_query(conn, insertQuery.c_str());

	if (!qstate) {
		cout << "Record added successfully!" << endl;
		mysql_free_result(res);
	}
	else {
		cout << "Error adding record: " << mysql_error(conn) << endl;
	}
}

