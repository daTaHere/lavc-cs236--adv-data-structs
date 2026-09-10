/*
Lab Assignment - Store and Display Players
Object-Oriented Design and Fundamental Data Structures

This program demonstrates the OOP principles of
inheritance, polymorphism, and encapsulation using C++ instead of Java.
*** IDE -> Visual Studio 2026 ***

Key features:
- A base Player class containing the protected name and score members
- A derived VIPPlayer class that inherits from Player and adds a bonus member
- An overridden display() method that demonstrates runtime polymorphism
- Dynamic storage of Player and VIPPlayer objects in the same array

Note:
The main function was modified from the Java starter program to conform to C++ language. 
An array of base-class pointers is used enabling access to a Player or VIPPlayer object from 
the same container.
( No input validation, No error handling )

    Created by :
     - Adam Huynh
     - CS 236 Fall Semester LAVC
     - 09/10/2026
    github repo:
     - https://github.com/daTaHere/lavc-cs236--adv-data-structs/blob/main/assignments

*/

#include <iostream>
#include <string>

using namespace std;

// Base Class
class Player {
	// shared between Base and sub Classes
	protected :
		string name;
		int score;

	public:
		// constructor
		Player() :  name(""), score( 0) {};
		Player(string n, int s) : name(n), score(s) {};
		// vitual destructor 
		virtual ~Player() = default;

		// getter
		virtual void display() {
			cout << name << " - " << "Score: " << score << endl;
		}
};

// Derive Class inherit from Base Casses
class VIPPlayer : public Player {
	// SubClass member only
	private:
		int bonus;

	public:
		// constructors
		VIPPlayer() : Player(), bonus(0) {};
		VIPPlayer(string name, int score, int b) : Player(name, score), bonus(b) {};

		// Override Base Class method
		void display() override {
			int totalScore = score + bonus;
			cout << name << " - " << "Total  Score: " << totalScore << endl;
		}
};

int main() {
	

	int playerCnt;
	cout << "Enter number of players: ";
	cin >> playerCnt;

	// pointer to array of Base Class pointers
	Player** players = new Player*[playerCnt];


	// hydrate n  objects 
	for (int i = 0; i < playerCnt; i++) {
		string pName, temp;
		int pScore= 0, bonus= 0;

		cout << "Player " << i + 1 << " name:\n";
		getline(cin >> ws, pName);
		cout << "Score:\n";
		cin >> pScore;
		cout << "VIP? (true/false):\n";
		getline(cin >> ws, temp);

		// Allocate and create object based on VIP status
		if (temp == "true") {
			cout << "Bonus: \n";
			cin >> bonus;
			players[i] = new  VIPPlayer(pName, pScore, bonus);
		}
		else {
			players[i] = new Player(pName, pScore);
		}
		
	}

	cout << "\nPlayer List: \n";
	for (int i = 0; i < playerCnt; i++) {
		players[i]->display();
		// free obj addresses
		delete players[i];
	}
	
	// free pointer array addresses
	delete[]  players;
}
