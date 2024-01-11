#include <iostream> 
#include <ctime>
using namespace std;

int attempts = 0;

void Fill_Array(int number, int arr[]);
void Sort_Array(int arr[], int size);
void Show(int arr[], int size);
void Count_Attempts(int arr[], int size);



int main() {
	srand(static_cast<unsigned>(time(NULL)));

	
	const int SIZE = 255;
	int array[SIZE];
	int MY_CHOICE;
	cout << "Type in any number you want in range 0-99: ";
	cin >> MY_CHOICE;

	Fill_Array(MY_CHOICE, array);
	Sort_Array(array, attempts);
	cout << "Sorted array: ";
	Show(array, attempts);
	cout << "Attempts used: ";
	Count_Attempts(array, attempts);

}

void Fill_Array(int number, int arr[]) {
	int comp_guess = 0;
	
	

	while (comp_guess != number) {
		comp_guess = rand() % 100;
		arr[attempts] = comp_guess;
		cout << comp_guess << ' ';
		attempts++;
	} 
	cout << endl;
	cout << "Attempts used: " << attempts << endl;

}

void Sort_Array(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
void Show(int arr[], int size) {
	for (int i = 0; i < size; i++)
		cout << arr[i] << ' ';
	cout << endl;
}
void Count_Attempts(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		if (arr[i] == arr[i + 1])
			attempts--;

	}
	cout << attempts;
}