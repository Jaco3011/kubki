#pragma once
#include <string>
#include <vector>

class TSubstance{
	std::string name;
	double ro; //[kg/m3]
	
	public:
	TSubstance(std::string name, double ro);
	
	std::string get_name();
	double get_ro();  
	static double get_ro(std::string name);
	static int get_substance_id(std::vector<TSubstance> substance_buffer, std::string name, bool verbose);
};

extern std::vector <TSubstance> substancje;
