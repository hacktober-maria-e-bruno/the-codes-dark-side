#include <iostream>
#include <windows.h>
#include <cctype>

using namespace std;

int second = 1000;

int main(){
	
	cout << "Darth Vader: What's your name?" << endl;
	
	cout << "You: ";
	
	string name;
	
	cin >> name;
	
	for(int i = 0; i < (int)name.size(); i++){
		if(i) name[i] = tolower(name[i]);
		else name[i] = toupper(name[i]);
	}
	
	cout << "Darth Vader: " << name << ",";
	Sleep(second);
	
	cout <<  " I'm your father!" << endl;
	Sleep(2 * second);
	
	cout << "You: What?????????? (:-O)" << endl;
	
	Sleep(2 * second);
	
	return 0;
}
