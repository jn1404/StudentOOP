#include <cassert>
#include <iostream>
#include <fstream> // file stream
#include "../my_code/weather.h"
#include "../my_code/date.h"

using namespace std;
/*
 * Another way we can loop asking for a good file name. 
string get_input_file() {
	string filenm;

	cout << "Input: ";
	cin >> filenm;
	return filenm;
}

Inside:
void get_wreadings(Weather& w) {
	ifstream rfile(get_input_file());
	while (!rfile) {
		cout << "Could not read." << endl;
		rfile.open(get_input_file());
	}
}
*/

void get_wreadings(Weather& w) {	
	string filenm;
	cout << "Input the name of the new readings file: ";
	cin >> filenm;

	ifstream rfile(filenm);
	while (!rfile) {
		rfile.clear();
		cout << "Could not read input file: " << filenm << endl 
			<< "Input the name of the new readings file: ";
		cin >> filenm;
		rfile.open(filenm);
	}
	int m, d, y;
	double temp, hum, ws;
	while (rfile >> m >> d >> y >> temp >> hum >> ws) {
		WReading wr = WReading(Date(d, m, y), temp, hum, ws);
		w.add_reading(wr);
	}
	rfile.close();
}

int main() {
	WReading test_temps = WReading(Date(1, 1, 2019), 0, 50, 10);
	double freezingF = test_temps.get_tempF();
	assert(freezingF == 32.0);

    Weather irkutsk = Weather("Irkutsk", GPS(46.3, 67.2));

	get_wreadings(irkutsk);
    cout << irkutsk << endl;
}