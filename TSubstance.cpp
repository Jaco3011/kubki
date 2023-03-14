#include <string>
#include <iostream>
#include "TSubstance.h"
#include "TCup.h"
using namespace std;

TSubstance::TSubstance(string name, double ro){
	this->name = name;
	this->ro = ro;
};

string TSubstance::get_name(){
	return name;
};
double TSubstance::get_ro(){
	return ro;
};

double TSubstance::get_ro(string name){
	double ro= -1;
	int id = get_substance_id(substancje, name, false);
	if (id>=0) ro = substancje[id].get_ro();
	return ro;
};

int TSubstance::get_substance_id(vector<TSubstance> substance_buffer, string name, bool verbose){
	int count = substance_buffer.size();
	int _id = -1;
	bool run = (bool)count;
	while(run){
		_id += 1;
		string sub_name = substance_buffer[_id].get_name();
		
		if (sub_name == name) {run = false;};
		
		if((_id + 1 == count) && run == true){
			if (verbose) {
				cout << "Nie znaleziono cieczy o podanej nazwie: \"" << name <<"\"!\n";
			};
			run = false;
			_id = -1;
		}		
		
	}
	return _id;
};

vector <TSubstance> substancje = {
	TSubstance{"woda",997.8},
	TSubstance{"mleko",1030.0},
	TSubstance{"oliwa",920.0},
	TSubstance{"krew",1050.0}
};
