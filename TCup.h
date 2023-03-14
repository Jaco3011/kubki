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
	void add_to_vol_coe(std::string name, double target_percent);
	void add_to_mass_coe(std::string name, double target_percent);
	void show();
	static void merge(TCup &kubek1, TCup &kubek2); //funkcja przelewa Z drugiego DO pierwszego
	bool is_empty();
private:
	void print_coe_vol();
	void print_coe_mass();
};
