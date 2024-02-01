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

