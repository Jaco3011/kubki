#pragma once
#include <string>
#include <vector>
#include "TSubstance.h"

class TCup{
	std::vector<TSubstance> substances;
	std::vector<double> volumes;
	
public:
	void add(TSubstance substance, double volume_in_ml);
	void add(std::string name, double volume_in_ml);
	void show();
private:
	void print_coe_vol();
	void print_coe_mass();
	int get_substance_id(std::string name);
};