#include <cassert>
#include <iostream>
#include <fstream> // file stream
#include "../my_code/weather.h"
#include "../my_code/date.h"

using namespace std;

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
    Weather irkutsk = Weather("Irkutsk", GPS(46.3, 67.2));

	get_wreadings(irkutsk);
    cout << irkutsk << endl;
}