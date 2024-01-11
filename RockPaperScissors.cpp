#include <iostream>
#include <string>
#include <ctime>

using namespace std;

void Show_Menu();
void Computer_Choice(string arr[], int& comp_choice);
void Winner_Out(string arr[], int mychoice, int comp_choice, int& my_score, int& computer_score);

int main() {
	srand(static_cast<unsigned>(time(NULL)));
	cout << "Greetings! This is a game Rock-Paper-Scissors" << endl;
	int COMPUTER_SCORE = 0;
	int MY_SCORE = 0;

	while (COMPUTER_SCORE != 2 && MY_SCORE != 2) {
		Show_Menu();
		const int SIZE = 3;
		string array[SIZE] = { "Rock" , "Paper", "Scissors" };
		int MY_CHOICE;
		int COMPUTER_CHOICE;
		cout << "Make your choice: ";
		cin >> MY_CHOICE;

		Computer_Choice(array, COMPUTER_CHOICE);
		Winner_Out(array, MY_CHOICE, COMPUTER_CHOICE, MY_SCORE, COMPUTER_SCORE);
	}
}

void Show_Menu() {
	cout << "The rules are:" << endl
		 << "0 - Rock" << endl
		 << "1 - Paper" << endl
		 << "2 - Scissors" << endl;
}
void Computer_Choice(string arr[], int& comp_choice) {
	comp_choice = rand() % 3;
	string comp_choice_out = arr[comp_choice];
}
void Winner_Out(string arr[], int mychoice, int comp_choice, int& my_score, int& computer_score) {
	if (arr[mychoice] == arr[comp_choice])
		cout << "Draw!" << endl;
	else if (mychoice == 0 && comp_choice == 1) {
		cout << "Computer won!" << endl;
		computer_score++;
	}
		
	else if (mychoice == 0 && comp_choice == 2) {
		cout << "You won!" << endl;
		my_score++;
	}
		
	else if (mychoice == 1 && comp_choice == 0) {
		cout << "You won!" << endl;
		my_score++;
	}
		
	else if (mychoice == 1 && comp_choice == 2) {
		cout << "Computer won!" << endl;
		computer_score++;
	}
		
	else if (mychoice == 2 && comp_choice == 0) {
		cout << "Computer won!" << endl;
		computer_score++;
	}
		
	else if (mychoice == 2 && comp_choice == 1) {
		cout << "You won!" << endl;
		my_score++;
	}
	cout << "Your score: " << my_score << "  Computer's score: " << computer_score << endl;
}
		
