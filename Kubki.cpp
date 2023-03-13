#include <iostream>
#include <vector>
#include "TSubstance.h"
#include "Tcup.h"
using namespace std;

int main(){
	for (int i = 0; i < 4; i++){
		cout << substancje[i].get_name() << ": " <<	substancje[i].get_ro() << "kg/m3\n";
	};
	TCup kubek;
	kubek.add("woda",100);
	kubek.add("oliwa",250);
	kubek.add("mleko",80);
	kubek.add("kwas",50);
	kubek.show();
};