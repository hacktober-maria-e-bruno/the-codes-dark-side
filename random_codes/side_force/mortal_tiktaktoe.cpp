#include <iostream>
#include <windows.h>
#include <cctype>

using namespace std;

int second = 1000;

struct Game{
	
	string m[6] = {
		{' ', ' ', '1', ' ', '2', ' ', '3'},
		{'A', ' ', ' ', '|', ' ', '|', ' '},
		{' ', ' ', '-', '-', '-', '-', '-'},
		{'B', ' ', ' ', '|', ' ', '|', ' '},
		{' ', ' ', '-', '-', '-', '-', '-'},
		{'C', ' ', ' ', '|', ' ', '|', ' '},
	};
	
	void printMatriz(){
		for(int i = 0; i < 6; i++) cout << m[i] << endl;
	}
	
	int play(string move){
		
		int line, column;
		
		if(toupper(move[0]) == 'A') line = 1;
		else if(toupper(move[0]) == 'B') line = 3;
		else if(toupper(move[0]) == 'C') line = 5;
		else return false;
		
		if(toupper(move[1]) == '1') column = 2;
		else if(toupper(move[1]) == '2') column = 4;
		else if(toupper(move[1]) == '3') column = 6;
		else return false;
		
		if(m[line][column] != ' ') return false;
		
		m[line][column] = 'X';
		
		return true;
	}
	
	void playDarth(){
		
		pair<int, int> moveDarth = find_move();
		
		if(moveDarth.first == -1) return;
		
		m[moveDarth.first][moveDarth.second] = 'O';
	}
	
	pair<int, int> find_move(){
		
		if(m[1][2] == 'O' and m[1][4] == 'O' and m[1][6] == ' ') return {1, 6};
		if(m[3][2] == 'O' and m[3][4] == 'O' and m[3][6] == ' ') return {3, 6};
		if(m[5][2] == 'O' and m[5][4] == 'O' and m[5][6] == ' ') return {5, 6};
		
		if(m[1][4] == 'O' and m[1][6] == 'O' and m[1][2] == ' ') return {1, 2};
		if(m[3][4] == 'O' and m[3][6] == 'O' and m[3][2] == ' ') return {3, 2};
		if(m[5][4] == 'O' and m[5][6] == 'O' and m[5][2] == ' ') return {5, 2};
		
		if(m[1][2] == 'O' and m[1][6] == 'O' and m[1][4] == ' ') return {1, 4};
		if(m[3][2] == 'O' and m[3][6] == 'O' and m[3][4] == ' ') return {3, 4};
		if(m[5][2] == 'O' and m[5][6] == 'O' and m[5][4] == ' ') return {5, 4};
		
		if(m[1][2] == ' ' and m[3][2] == 'O' and m[5][2] == 'O') return {1, 2};
		if(m[1][2] == 'O' and m[3][2] == ' ' and m[5][2] == 'O') return {3, 2};
		if(m[1][2] == 'O' and m[3][2] == 'O' and m[5][2] == ' ') return {5, 2};
		
		if(m[1][4] == ' ' and m[3][4] == 'O' and m[5][6] == 'O') return {1, 4};
		if(m[1][4] == 'O' and m[3][4] == ' ' and m[5][6] == 'O') return {3, 4};
		if(m[1][4] == 'O' and m[3][4] == 'O' and m[5][6] == ' ') return {5, 4};
		
		if(m[1][6] == ' ' and m[3][6] == 'O' and m[5][6] == 'O') return {1, 6};
		if(m[1][6] == 'O' and m[3][6] == ' ' and m[5][6] == 'O') return {3, 6};
		if(m[1][6] == 'O' and m[3][6] == 'O' and m[5][6] == ' ') return {5, 6};
		
		if(m[1][2] == 'O' and m[3][4] == 'O' and m[5][6] == ' ') return {5, 6};
		if(m[1][2] == 'O' and m[3][4] == ' ' and m[5][6] == 'O') return {3, 4};
		if(m[1][2] == ' ' and m[3][4] == 'O' and m[5][6] == 'O') return {1, 2};
		
		if(m[5][2] == 'O' and m[3][4] == 'O' and m[1][6] == ' ') return {1, 6};
		if(m[5][2] == 'O' and m[3][4] == ' ' and m[1][6] == 'O') return {3, 4};
		if(m[5][2] == ' ' and m[3][4] == 'O' and m[1][6] == 'O') return {5, 2};
		
		return random_move();
	}
	
	pair<int, int> random_move(){
		for(int i = 1; i < 6; i += 2) for(int j = 2; j < 7; j += 2) if(m[i][j] == ' ') return {i, j};
		
		return {-1, -1};
	}
	
	int winner(){
		
		if(m[1][2] == 'O' and m[1][4] == 'O' and m[1][6] == 'O') return 2;
		if(m[3][2] == 'O' and m[3][4] == 'O' and m[3][6] == 'O') return 2;
		if(m[5][2] == 'O' and m[5][4] == 'O' and m[5][6] == 'O') return 2;
		
		if(m[1][2] == 'O' and m[3][2] == 'O' and m[5][2] == 'O') return 2;
		if(m[1][4] == 'O' and m[3][4] == 'O' and m[5][4] == 'O') return 2;
		if(m[1][6] == 'O' and m[3][6] == 'O' and m[5][6] == 'O') return 2;
		
		if(m[1][2] == 'O' and m[3][4] == 'O' and m[1][6] == 'O') return 2;
		if(m[5][2] == 'O' and m[3][4] == 'O' and m[1][6] == 'O') return 2;
		
		if(m[1][2] == 'X' and m[1][4] == 'X' and m[1][6] == 'X') return 1;
		if(m[3][2] == 'X' and m[3][4] == 'X' and m[3][6] == 'X') return 1;
		if(m[5][2] == 'X' and m[5][4] == 'X' and m[5][6] == 'X') return 1;
		
		if(m[1][2] == 'X' and m[3][2] == 'X' and m[5][2] == 'X') return 2;
		if(m[1][4] == 'X' and m[3][4] == 'X' and m[5][4] == 'X') return 2;
		if(m[1][6] == 'X' and m[3][6] == 'X' and m[5][6] == 'X') return 2;
		
		if(m[1][2] == 'X' and m[3][4] == 'X' and m[5][6] == 'X') return 1;
		if(m[5][2] == 'X' and m[3][4] == 'X' and m[1][6] == 'X') return 1;
		
		if(random_move().first == -1) return -1;
		
		return 0;
	}
	
} game;

int main(){
	
	cout << "Darth Vader: Haha, I'm Darth Vader and I will conquer the universe while playing Tik Tak Toe!!" << endl;
	Sleep(5 *second);
	cout << "You: Not while I'm alive!" << endl;
	Sleep(2 * second);
	
	cout << "Game has began!" << endl;
	Sleep(3 * second);
	
	int winner = 0;
	while(winner == 0){
		
		cout << "---" << endl;
		game.printMatriz();
		
		int validMove = false;
		while(!validMove){
			string move;
			cout << "Make your move(example: B2): ";
			cin >> move;
			
			validMove = game.play(move);
			if(!validMove) cout << "Invalid Move! Please follow the example." << endl;
		}
		
		winner = game.winner();
		if(winner) continue;
		
		game.playDarth();
		
		winner = game.winner();
	}
	
	cout << "---" << endl;
	game.printMatriz();
	Sleep(2 * second);
	
	if(winner == 1){
		cout << "Darth Vader: I'll beat you next time!" << endl;
		Sleep(second);
		cout << "You saved the Universe! Congratulations!" << endl;
	} else if(winner == 2) {
		cout << "Darth Vader: You can't defeat me. You're the worst! HAHA" << endl;
		Sleep(second);
		cout << "You lost! The Universe depends on you! Don't stop trying." << endl;
	} else {
		cout << "Draw! The Universe is save for now, but remember: the Dark Side never stop trying until they aren't defeated!" << endl;
	}
	
	Sleep(5 * second);
	
	return 0;
}
