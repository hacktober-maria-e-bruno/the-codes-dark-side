#include <iostream>
#include <windows.h>
#include <cctype>

using namespace std;

struct person{
    string fname, sname;
    int age;

    string toString() {return fname + " " + sname;}

    string side(){

        int sideNumber = 0;
        
        for(auto i : fname) sideNumber = (sideNumber + (int)toupper(i)) % 23;
        for(auto i : sname) sideNumber = (sideNumber + (int)tolower(i)) % 23;

        sideNumber = (sideNumber * age) % 31;

        return (sideNumber & 1) ? "Dark Side" : "Light Side";
    }
} p;

int second = 1000;

int main(){
    
    cout << "What's your first name? ";
    cin >> p.fname;
    cout << "What's your second name? ";
    cin >> p.sname;
    cout << "How old are you, " << p.toString() << "? ";
    cin >> p.age;

    cout << "Ok...Processing informations..." << endl << "5..." << endl;
    Sleep(second);
    cout << "4..." << endl;
    Sleep(second);
    cout << "3..." << endl;
    Sleep(second);
    cout << "2..." << endl;
    Sleep(second);
    cout << "1..." << endl;
    Sleep(second);

    cout << p.toString() << " belongs to the " << p.side() << "." << endl;

    return 0;
}
