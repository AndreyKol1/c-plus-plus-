#include <iostream> 
#include <ctime>
using namespace std;

void Guess_Function(int number);

int main() {
	srand(static_cast<unsigned>(time(NULL)));
	int COMPUTER_CHOICE = rand() % 100;
	
	
	cout << "Welcome to the guess game. You have 5 attempts to guess the number picked by a computer in range 0 - 99" << endl;
	
	Guess_Function(COMPUTER_CHOICE);
}

void Guess_Function(int number) {
	int USER_INPUT;
	cout << "Type in the number: ";
	cin >> USER_INPUT;
	int size = 5;
	for (int i = 1; i < size; ++i) {
		if (USER_INPUT == number) {
			cout << "You won!";
			break;
		}
		else {
			cout << "Attempts left " << size - i << endl;
			if (USER_INPUT < number)
				cout << "The number is bigger than yours" << endl;
			else
				cout << "The number is smaller than yours" << endl;
			cout << "Try again: ";
			cin >> USER_INPUT;
		}
	}
	cout << "The number was " << number << ".Better luck next time!";
}