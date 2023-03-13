#include <iostream>
#include "TCup.h"
using namespace std;

void TCup::add(TSubstance substance, double volume_in_ml){
	substances.push_back(substance);
	volumes.push_back(volume_in_ml / 1e6);
};

void TCup::add(string name, double volume_in_ml){
	int _id = get_substance_id(name);
	
	if (_id>=0){
		add(substancje[_id],volume_in_ml);
	}
	
};

void TCup::show(){
	int count = substances.size();
	for (int i = 0; i < count; i++){
		double mass = substances[i].get_ro() * volumes[i] * 1000; //result in grams
		cout << substances[i].get_name()
		<< "; volume: " << volumes[i] * 1e6
		<< " ml; mass: " << mass << " g\n";
	};
	print_coe_vol();
	print_coe_mass();
};

void TCup::print_coe_vol(){
    double total_volume = 0;
    int count = substances.size();
    for(int i = 0; i<count; i++){
        total_volume+=volumes[i];
    }
    for(int i = 0; i<count; i++){
        if (i > 0) {cout << " : ";}
        cout << volumes[i]/total_volume;
    }
    cout << endl;
};

void TCup::print_coe_mass(){
    double total_mass = 0;
    int count = substances.size();
    for(int i = 0; i<count; i++){
        total_mass+=volumes[i]*substances[i].get_ro();
    }
    for(int i = 0; i<count; i++){
        if (i > 0) {cout << " : ";}
        cout << volumes[i]*substances[i].get_ro()/total_mass;
    }
    cout << endl;
};

int TCup::get_substance_id(string name){
	int count = substancje.size();
	int _id = -1;
	bool run = true;
	while(run){
		_id += 1;
		string sub_name = substancje[_id].get_name();
		
		if (sub_name == name) {run = false;};
		
		if((_id + 1 == count) && run == true){
			cout << "Nie znaleziono cieczy o podanej nazwie: \"" << name <<"\"!\n";
			run = false;
			_id = -1;
		}		
		
	}
	return _id;
};
