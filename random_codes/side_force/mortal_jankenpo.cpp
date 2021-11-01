#include <iostream>
#include <windows.h>
using namespace std;

int second = 1000;

int win(char x, char y){
	
	if(x == 'O' && y == 'O') return 2;
	if(x == 'O' && y == 'V') return 0;
	if(x == 'O' && y == 'X') return 1;
	
	if(x == 'V' && y == 'O') return 1;
	if(x == 'V' && y == 'V') return 2;
	if(x == 'V' && y == 'X') return 0;
	
	if(x == 'X' && y == 'O') return 0;
	if(x == 'X' && y == 'V') return 1;
	if(x == 'X' && y == 'X') return 2;
	
	return 2;
}

void play(char move, int& a, int& b){
	
	int random = rand() % 3;
	
	char moveDarth;
	
	if(random == 0) moveDarth = 'O';
	if(random == 1) moveDarth = 'V';
	if(random == 2) moveDarth = 'X';
	
	cout << "JAN..." << endl;
	cout << "KEN..." << endl;
	cout << "PO!" << endl;
	
	cout << moveDarth << " | " << move << endl;
	
	if(win(move, moveDarth) == 0){
		cout << "Darth won!" << endl;
		a++;
	}
	else if(win(move, moveDarth) == 1){
		cout << "You won!" << endl;
		b++;
	}
	else cout << "Draw!" << endl;
		
}

int main(){
	
	cout << "Darth Vader: Haha, I'm Darth Vader and I will conquer the universe while playing JANKENPO!!" << endl;
	Sleep(5 *second);
	cout << "You: Not while I'm alive!" << endl;
	Sleep(2 * second);
	
	cout << "Game has began! Winner is the first to reach 3 points" << endl;
	Sleep(3 * second);
	
	int a = 0, b = 0;
	while(a < 3 && b < 3){
		
		char move;
		
		cout << "Type \"O\" for stone, \"V\" for scissor or \"X\" for paper: ";
		cin >> move;
		
		play(move, a, b);
		
		cout << "(Darth) " << a << " X " << b << "(You)" << endl; 
	}
	
	if(a == 3) {
		cout << "Darth: The universe is MINE!! Easy Peasy!!" << endl;
		Sleep(3 * second);
		cout << "You: You won't get way with it! The Light Side will never give up!" << endl;
	}
	if(b == 3){
		cout << "Darth: NOOOOOOOOOOO! You and your friends always destroy my plans!!!!!!" << endl;
		Sleep(3 * second);
		cout << "You: What did you say? I can't hear from the podium! LOSERRRRR" << endl;
	}
	
	Sleep(3 * second);
	return 0;
}
