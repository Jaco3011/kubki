#include <string>
#include "TSubstance.h"
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