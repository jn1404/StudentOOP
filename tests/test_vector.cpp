#include <cassert>
#include <iostream>
#include "../my_code/vector.h"

using namespace std;

int copy_vector(my_vector v) {
    my_vector local_v = v;
    return local_v.size();
}

int main() {
    my_vector v = my_vector();
    for (int i = 0; i < 200; i++) {
        v.push_back(i);
        copy_vector(v);
    }
    assert(v[199] == 199);
    for (int i = 0; i < 200; i++) {
        v[i] *= 2;
    }
    assert(v[199] == 398);
    my_vector v3;
    for (int i = 9; i < 100; i += 9) {
        v3.push_back(i);
    }
    assert(v3[1] == 18);

    my_vector v2 = v;
    print_my_vector(v2);
    assert(v2 == v);

    v2 = v3;
    print_my_vector(v2);
    assert(v2 == v3);
}