#include <iostream>
#include <time.h>
#include <conio.h>
#include <windows.h>
using namespace std;

void FindRepeatingDigit(int array[4][4]);
void Upward(int array[4][4]);
void Downward(int array[4][4]);
void Leftward(int array[4][4]);
void Rightward(int array[4][4]);
bool CheckWin(int array[4][4]);
void PrintPuzzle(int array[4][4]);
void Command();

int main() {
	const int arraySize = 4;
	int mainBox[arraySize][arraySize], box[arraySize][arraySize];
	char userInput;

	srand(time(NULL));
	FindRepeatingDigit(box);

	while (true) {
		system("cls");
		PrintPuzzle(box);
		Command();
		if (CheckWin(box)) {
			cout << "\n\n     CONGRATULATIONS!!!\n\tYOU WIN!!!" << "\n\n";
			break;
		}
		cout << "\n\n\t\tEnter a Command"; userInput = _getch();

		switch (userInput) {
		case char(72): Upward(box);	break;
		case char(80): Downward(box); break;
		case char(75): Leftward(box); break;
		case char(77): Rightward(box); break;
		case char(27): return 0;
		}
	}
}

void FindRepeatingDigit(int array[4][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4;) {
			int digit = (rand() % 16) + 1;
			bool found = true;

			for (int ii = 0; ii <= i; ii++) {
				for (int jj = 0; jj < 4; jj++) {
					if (ii == i && jj == j) {
						break;
					}
					else if (array[ii][jj] == digit) {
						found = false;
						ii = i + 1;
						break;
					}
				}
			}
			if (found) {
				array[i][j] = digit;
				j++;
			}
		}
	}
}

void Upward(int array[4][4]) {
	int getX = 0, getY = 0;

	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 4; i++) {
			if (array[i][j] == 16) {
				getX = j;
				getY = i;
			}
		}
	}

	if (getY != 0) {
		int swap = array[getY - 1][getX];
		array[getY - 1][getX] = 16;
		array[getY][getX] = swap;
		getY--;
	}
}

void Downward(int array[4][4]) {
	int getX = 0, getY = 0;

	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 4; i++) {
			if (array[i][j] == 16) {
				getX = j;
				getY = i;
			}
		}
	}

	if (getY != 3) {
		int swap = array[getY + 1][getX];
		array[getY + 1][getX] = 16;
		array[getY][getX] = swap;
		getY++;
	}
}

void Leftward(int array[4][4]) {
	int getX = 0, getY = 0;

	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 4; i++) {
			if (array[i][j] == 16) {
				getX = j;
				getY = i;
			}
		}
	}

	if (getX != 0) {
		int swap = array[getY][getX - 1];
		array[getY][getX - 1] = 16;
		array[getY][getX] = swap;
		getX--;
	}
}

void Rightward(int array[4][4]) {
	int getX = 0, getY = 0;

	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 4; i++) {
			if (array[i][j] == 16) {
				getX = j;
				getY = i;
			}
		}
	}

	if (getX != 3) {
		int swap = array[getY][getX + 1];
		array[getY][getX + 1] = 16;
		array[getY][getX] = swap;
		getX++;
	}
}

bool CheckWin(int array[4][4]) {
	int counter = 1;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++, counter++) {
			if (array[i][j] != counter) {
				return false;
			}
		}
	}
	return true;
}

void PrintPuzzle(int array[4][4]) {
	cout << "\n";
	cout << "=================================================== \n";
	cout << "                Game: 15-Pyatnashki \n";
	cout << "=================================================== \n\n";

	for (int i = 0; i < 4; i++) {
		cout << "\t+-------+-------+-------+-------+\n";
		cout << "\t" << "| ";
		for (int j = 0; j < 4; j++) {
			if (array[i][j] == 16) cout << "  " << "\t" << "| ";
			else cout << array[i][j] << "\t" << "| ";
		}
		cout << endl;
	}
	cout << "\t+-------+-------+-------+-------+\n";
}

void Command() {
	cout << "\n\t\tCommand: " << "\n\n";
	cout << "\t\tUp" << "\n";
	cout << "\t\tDown" << "\n";
	cout << "\t\tLeft" << "\n";
	cout << "\t\tRight" << "\n";
	cout << "\t\tESC - Quit." << "\n";
}