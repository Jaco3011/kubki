#include <iostream>
#include <vactor>
#include "TSubstance"
#include "Tcup"
using namespace std;

vector<TSubstance>substancje={
	TSubstance{"woda",997.8},
	TSubstance{"mleko",1030.0},
	TSubstance{"oliwa",920.0},
	TSubstance{"krew",1050.0}
int main(){
	for (int i = 0; i < 4; i++){
		cout << substancje[i].get_name() << ": " <<	substancje[i].get_ro() << "kg/m3\n";
	};
};