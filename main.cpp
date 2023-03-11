#include <iostream>
#include <vector>
#include "TSubstance.h"
#include "Tcup.h"
using namespace std;

vector<TSubstance>substancje={
	TSubstance{"woda",997.8},
	TSubstance{"mleko",1030.0},
	TSubstance{"oliwa",920.0},
	TSubstance{"krew",1050.0}
};
int main(){
	for (int i = 0; i < 4; i++){
		cout << substancje[i].get_name() << ": " <<	substancje[i].get_ro() << "kg/m3\n";
	};
	cout << "\nHello World!\n\n" ;
	TCup kubek1;
	kubek1.add(substancje[0],100);
	kubek1.add(substancje[2],50);
	kubek1.show();
};