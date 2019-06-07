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

string Weather::get_name() const {
	return station_nm;
}

int Weather::get_rating() const {
	return rating;
}

void Weather::set_rating(int new_rating) {
	rating = new_rating;
}

void Weather::add_reading(WReading wr) {
	wreadings.push_back(wr);
}

ostream& operator<<(ostream& os, const GPS& gps) {
	os << "Latitude: " << gps.latitude << "; Longitude: " << gps.longitude;
	return os;
}

ostream& operator<<(ostream& os, const Weather& w) { // operator<< here we are defining the operator
	os << "Name: " << w.get_name() << "; Rating: " << w.get_rating() << "; " << w.my_loc << endl;
	for (WReading wr : w.wreadings) {
		os << "    " << wr << endl;
	}
	return os; // to chain (cout << "Hello" << endl) -> (os << endl)
}

ostream& operator<<(ostream& os, const WReading& wr) {
	os << wr.date << ": Temperature: " << wr.temperature << ": Humidity: " << wr.humidity 
		<< ": Windspeed: " << wr.windspeed;
	return os;
}





