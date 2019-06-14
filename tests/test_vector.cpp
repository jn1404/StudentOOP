#include <cassert>
#include <iostream>
#include "../my_code/my_vector.h"

using namespace std;

int copy_my_vector(my_vector v) {
    my_vector local_v = v;
    return local_v.size();
}

int main() {
    my_vector v = my_vector();
    for (int i = 0; i < 200; i++) {
        v.push_back(i);
        copy_my_vector(v);
    }
    for (int i = 0; i < 200; i++) {
        v[i] *= 2;
    }
    my_vector v3;
    for (int i = 9; i < 99; i += 9) {
        v3.push_back(i);
    }

    my_vector v2 = v;
    print_my_vector(v2);

    v2 = v3;
    print_my_vector(v3);
}