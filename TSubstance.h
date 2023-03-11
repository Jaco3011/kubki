#pragma once
#include <string>

class TSubstance{
	std::string name;
	double ro; //[kg/m3]
	
	public:
	TSubstance(std::string name, double ro);
	
	std::string get_name();
	double get_ro();  
};