#ifndef WEATHER_H
#define WEATHER_H

#include <string>
#include <vector>
#include "date.h"

const int UNRATED = -1;
const int BAD = 0;
const int OK = 1;
const int GOOD = 2;


/*
 * This will be the base class for all types of images.
 * */
class Image {
 public:
    Image(int w, int h, std::string flnm);
    // copy constructor:
    Image(const Image& img2);
    ~Image();
    Image& operator=(const Image& img2);
    int image_sz();

    /*
     * Setting `display() = 0` here makes this an abstract
     * class that can't be implemented.
     * */
    virtual std::string display(std::string s);
    /*
     * If we don't want virtual method lookup, we
     * could just declare:
     * void display();
     * */

    int get_height() { return height; }
    int get_width() { return width; }

 private:
    int width;
    int height;
    std::string filename;
    char* image_buf;
    void copy_fields(const Image& img2);
};

class Gif : public Image { // Inheritance
 public:
    Gif(int w, int h, std::string flnm, int cl=0) 
        : Image(w, h, flnm), compress_level(cl) // Constructor
    {}

    std::string display(std::string s);

 private:
    int compress_level;
};


const int HIGH = 3;
const int MEDIUM = 2;
const int LOW = 1;

class Jpeg : public Image { // Inheritance
 public:
    Jpeg(int w, int h, std::string flnm, int q=HIGH) 
        : Image(w, h, flnm), quality(q) // Constructor
    {}

    std::string display(std::string s);

 private:
    int quality;
};

struct GPS {
    double latitude;
    double longitude;
    GPS(double la, double lo) : latitude(la),
        longitude(lo) {}
};

std::ostream& operator<<(std::ostream& os, const GPS& gps);

class WReading {
    friend std::ostream& operator<<(std::ostream& os, const WReading& wr);
 public:
	WReading(Date dt, double temp, double hum, double ws) :
     date(dt), temperature(temp), humidity(hum), windspeed(ws)
	{
	}
    double get_tempF();
    double get_tempC() { return temperature; }

 private: 
	Date date;
	double temperature;
	double humidity;
	double windspeed;
};


class Weather {
    friend std::ostream& operator<<(std::ostream& os, const Weather& w);
 public:
    Weather(std::string nm, GPS loc);
    std::string get_name() const;
    int get_rating() const;
    void set_rating(int new_rating);
    void add_reading(WReading wr);
 private:
	std::vector<WReading> wreadings;
    std::string station_nm;
    GPS my_loc;
    int rating = UNRATED;
};

#endif