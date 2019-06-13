#include <iostream>
#include <string>
#include "weather.h"

using namespace std;

const double F_TO_C = 5 / 9;
const double C_TO_F = 9 / 5;


Image::Image(int w, int h, std::string flnm) : 
	width(w), height(h)
{
	filename = flnm;
	image_buf = new char[image_sz()]; // creates a new buffer
}

// Copy constructor:
Image::Image(const Image& img2) {
	copy_fields(img2);
}

// Destructor
Image::~Image() {
	if (image_buf != nullptr) delete [] image_buf ; // delete array []
}

// Assignment operator
Image& Image::operator=(const Image& img2) {
	if (&img2 != this) { // in case: img2 = img2 
		if (image_buf != nullptr) delete [] image_buf; // destructor
		copy_fields(img2); // copy constructor
	}
	return *this;
}

void Image::copy_fields(const Image& img2) { 
	height = img2.height;
	width = img2.width;
	filename = img2.filename;  // strings have copy control
	image_buf = new char[image_sz()]; // create a new buffer
	for (int i = 0; i < image_sz(); i++) { // copy the image 
		image_buf[i] = img2.image_buf[i];
	}
}

int Image::image_sz() {
	return width * height;
}

string Image::display(std::string s) {
	return "Displaying image " + s;
}


/*
 * TO DO 
*/

double WReading::get_tempF() {
	return (temperature * C_TO_F) + 32;
}

/*
double WReading::get_tempC() {
	return (temperature - 32) * F_TO_C;
}
*/

// END OF TO DO 
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





