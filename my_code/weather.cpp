#include <iostream>
#include <string>
#include "weather.h"

using namespace std;

/*
 * A constructor for weather class.
 * */
Weather::Weather(string nm, GPS loc) : 
	station_nm(nm), my_loc(loc) {
}

string Weather::get_name() {
	return station_nm;
}