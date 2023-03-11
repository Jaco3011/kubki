#include <iostream>
#include "TCup.h"
using namespace std;

void TCup::add(TSubstance substance, double volume_in_ml){
	substances.push_back(substance);
	volumes.push_back(volume_in_ml / 1e6);
};

void TCup::show(){
	int count = substances.size();
	for (int i = 0; i < count; i++){
		double mass = substances[i].get_ro() * volumes[i] * 1000; //result in grams
		cout << substances[i].get_name() 
		<< "; volume: " << volumes[i] * 1e6
		<< " ml; mass: " << mass << " g\n";
	};
};

void TCup::print_coe_vol(){

};

void TCup::print_coe_mass(){

};