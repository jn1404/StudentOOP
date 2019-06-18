#include <iostream>
#include "vector.h"

using namespace std;

void print_my_vector(my_vector v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}


my_vector::my_vector() {
    sz = 0;
    capacity = DEF_CAPACITY;
    data = new int[DEF_CAPACITY];
}

my_vector::my_vector(const my_vector& v2) {
    capacity = v2.capacity;
    sz = v2.size();
    data = new int[capacity];
    // copy over existing data
    for (int i = 0; i < size(); i++) {
        data[i] = v2.data[i];
    }
}

my_vector::~my_vector() {
    delete[] data;
}

my_vector& my_vector::operator=(const my_vector& v2) {
    if (&v2 != this) {
        delete[] data;
        capacity = v2.capacity;
        sz = v2.size();
        data = new int[capacity];
        // copy over existing data
        for (int i = 0; i < size(); i++) {
            data[i] = v2.data[i];
        }
    }
    return *this;
}

bool operator==(const my_vector& v1, const my_vector& v2) {
    int v1_sz = v1.size();
    int v2_sz = v2.size();
    if (v1_sz == v2_sz) {
        for (int i = 0; i < v1_sz; i++) {
            if (v1[i] != v2[i])
                return false;
        }
        return true;
    } 
    else 
        return false;
}


void my_vector::push_back(int val) {
    if (sz == capacity) {
        cout << "Increasing capacity\n";
        // get new array of capacity * 2
        capacity *= 2;
        int* new_data = new int[capacity];
        // copy over existing data
        for (int i = 0; i < size(); i++) {
            new_data[i] = data[i];
        }
        // delete old array
        delete[] data;
        // set pointer to new array
        data = new_data;
    }
    data[sz++] = val;
}

int my_vector::operator[](int i) const {
    return data[i];
}

int& my_vector::operator[](int i) {
    return data[i];
}