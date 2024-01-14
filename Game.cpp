// Battleship Project
// Started 1/1/2023

#include <iostream>;
using namespace std;

int main() {
	bool ships[4][4] = {
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	};

	for (int i = 0; i < 4; i++) {
		int random1 = rand() % 5;
		int random2 = rand() % 5;
		if (ships[random1][random2] == 0) {
			ships[random1][random2] = 1;
		}
		else {
			i -= 1;
		}
	}
	
	string liveBoard[5][5] = {
		{" ", "1", "2", "3", "4"},
		{"1", "?", "?", "?", "?"},
		{"2", "?", "?", "?", "?"},
		{"3", "?", "?", "?", "?"},
		{"4", "?", "?", "?", "?"}
	};


	int hits = 0;
	int turns = 0;

	cout << "Hello! This is a battleship game!" << endl;

	while (hits < 4) {
		int row;
		int col;

		// Outputs board in visually correct way
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				cout << liveBoard[i][j];
			}
			cout << endl;
		}

		cout << "Choose a row: ";
		cin >> row;
		cout << "Choose a column: ";
		cin >> col;

		if (ships[row - 1][col - 1] == 1) {
			if (liveBoard[row][col] != "*") {
				cout << "Hit!" << endl;
				liveBoard[row][col] = "*";
				hits++;
			}
			else {
				cout << "You already guessed there." << endl;
				turns--;
			}
		}
		else {
			if (liveBoard[row][col] == "X") {
				cout << "You already guessed there." << endl;
				turns--;
			}
			else {
				cout << "Miss!" << endl;
				liveBoard[row][col] = "X";
			}
		}

		turns++;
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << liveBoard[i][j];
		}
		cout << endl;
	}
	cout << "Victory!!" << endl << "You beat Battleship in " << turns << " turns!";

	return 0;
}
