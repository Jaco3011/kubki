#include <iostream>
#include "TCup.h"
#include "TSubstance.h"
using namespace std;

void TCup::add(TSubstance substance, double volume_in_ml){
	string new_name = substance.get_name();
	int pos = TSubstance::get_substance_id(substances, new_name, false);
	if (pos < 0){
		substances.push_back(substance);
		volumes.push_back(volume_in_ml / 1e6);
	} else {
		volumes[pos]+=(volume_in_ml / 1e6);
	};
};

void TCup::add(string name, double volume_in_ml){
	int _id = TSubstance::get_substance_id(substancje, name, true);
	
	if (_id>=0){
		add(substancje[_id], volume_in_ml);
	}
	
};

void TCup::add_to_vol_coe(string name, double target_percent){
	if (target_percent <=0 || target_percent >=100 || substances.empty()){
		return;
	}
	target_percent /= 100; //w zakresie od 0 do 1
	double sum = 0;
	for (int i=0; i<substances.size();i++){
		sum+=volumes[i];
	}
	int _id=TSubstance::get_substance_id(substances,name,false);
	if(volumes[_id]/sum>=target_percent) return;
	if (_id<0){
		this->add(name,1e6*target_percent*sum/(1-target_percent));
		return;
	} 
	this->add(name, 1e6 * ((target_percent*sum - volumes[_id])/(1-target_percent)));
};

void TCup::add_to_mass_coe(std::string name, double target_percent){
	if (target_percent <=0 || target_percent >=100 || substances.empty()){
		return;
	}
	target_percent /= 100; //w zakresie od 0 do 1
	double sum = 0;
	double ro = TSubstance::get_ro(name);
	for (int i=0; i<substances.size();i++){
		sum+=volumes[i]*substances[i].get_ro();
	}
	int _id=TSubstance::get_substance_id(substances,name,false);
	if(volumes[_id]*ro/sum>=target_percent) return;
	if (_id<0){
		this->add(name,1e6*target_percent*sum/(1-target_percent)/ro);
		return;
	}
	this->add(name, 1e6 *((target_percent*sum - volumes[_id]*ro)/(1-target_percent))/ro);
};

void TCup::show(){
	int count = substances.size();
	if (count == 0){
		cout <<"Kubek jest pusty!\n";
		return;
	}
	for (int i = 0; i < count; i++){
		double mass = substances[i].get_ro() * volumes[i] * 1000; //result in grams
		cout << substances[i].get_name()
		<< "; volume: " << volumes[i] * 1e6
		<< " ml; mass: " << mass << " g\n";
	};
	print_coe_vol();
	print_coe_mass();
};

void TCup::merge(TCup &kubek1, TCup &kubek2){
	if (kubek2.is_empty()) return;
	for (int i=0; i<kubek2.substances.size();i++){
		kubek1.add(kubek2.substances[i],kubek2.volumes[i]*1e6);
	}
	kubek2.substances.clear();
	kubek2.volumes.clear();
};

bool TCup::is_empty(){
	if (substances.size()==0) return true;
	for (int i=0;i<volumes.size();i++){
		if (volumes[i]>0) return false;
	}
	return true;
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
