#include <iostream>
#include <vector>
#include "TSubstance.h"
#include "Tcup.h"
using namespace std;

int main(){
	/*for (int i = 0; i < 4; i++){
		cout << substancje[i].get_name() << ": " <<	substancje[i].get_ro() << "kg/m3\n";
	};*/
	TCup kubek;
	kubek.add("woda",100);
	//kubek.add("oliwa",250);
	kubek.add("woda",80);
	kubek.add("kwas",50);
	kubek.show();
	TCup drugi_kubek;
	TCup::merge(kubek, drugi_kubek);
	drugi_kubek.add("woda",50);
	drugi_kubek.add("krew",160);
	cout << endl;
	drugi_kubek.show();
	TCup::merge(kubek, drugi_kubek);
	cout << endl;
	kubek.show();
	cout << endl;
	drugi_kubek.show();
	kubek.add_to_vol_coe("mleko",5);
	cout<<endl<<"Dodano mleka:\n";
	kubek.show();
	kubek.add_to_mass_coe("woda",90);
	cout<<endl<<"Dodano wody:\n";
	kubek.show();
	kubek.add_to_mass_coe("oliwa",10);
	cout<<endl<<"Dodano oliwy:\n";
	kubek.show();
}
