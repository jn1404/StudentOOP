#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int DEF_CAPACITY = 10;
const int CAPACITY_MULT = 2;

template <typename DATA>
class MyVec {
    public:
        MyVec() : sz(0) {
            capacity = DEF_CAPACITY;
            data = new DATA[DEF_CAPACITY];
        }

        MyVec(int sz, DATA val=0) {
            capacity = sz;
            data = new DATA[sz];
            for (int i = 0; i < sz; i++)
                data[i] = val;
        }

        // copy control:
        MyVec(const MyVec& v2) {
            copy(v2);
        }
        ~MyVec() {
            if (data != nullptr) delete [] data;
        }
        MyVec& operator=(const MyVec& v2) {
            if (this != &v2) {
                delete [] data;
                copy(v2);
            }
            return *this;
        }

        /*
        * Puts an element at the back of a vector.
        * */
        void push_back(int val) {
            sz++;
            if (sz > capacity) {
                cout << "Increasing capacity\n";
                DATA* old_data = data;
                data = new DATA[capacity * CAPACITY_MULT];
                for (int i = 0; i < sz; i++) {
                    data[i] = old_data[i];
                }
                capacity *= CAPACITY_MULT;
                delete [] old_data;
            }
            data[sz - 1] = val;
        }

        int size() const { return sz; }

        DATA operator[](int i) const {
            return data[i];
        }
        DATA& operator[](int i) {
            return data[i];
        }

    private:
        void copy(const MyVec& v2) {
            sz = v2.sz;
            capacity = v2.capacity;
            data = new DATA[capacity];
            for (int i = 0; i < sz; i++) {
                data[i] = v2.data[i];
            }
        }
        DATA* data;
        int sz;
        int capacity;
};

template <typename DATA>
void print_vector(const MyVec<DATA>& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

/*
 * == is true when every element of the vectors are the same in
 * the same order. (Thus they must be the same size.)
 * */
template <typename DATA>
bool operator==(MyVec<DATA>& v1, MyVec<DATA>& v2) {
    if (v1.size() == v2.size()) {
        for (int i = 0; i < v1.size(); i++) {
            if (v1[i] != v2[i])
                return false;
        }
        return true;
    } 
    else 
        return false;
}


