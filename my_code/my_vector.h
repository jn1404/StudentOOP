const int DEF_CAPACITY = 10;

class my_vector {
    public:
        my_vector();

        // copy control:
        my_vector(const my_vector& v2);
        ~my_vector();
        my_vector& operator=(const my_vector& v2);

        void push_back(int val);
        int size() const { return sz; }
        int operator[](int i) const;
        int& operator[](int i);
    private:
        int* data;
        int sz;
        int capacity;
};

void print_my_vector(my_vector v);