#include <iostream>
#include <stdint.h>
using namespace std;

class vec {
private:
    int fhaltu;
    int *ptr;
    uint64_t sz;
    uint64_t capacity;

public:
    vec() {
        ptr = nullptr;
        sz = 0;
        capacity = 0;
    }

    ~vec() {
        if (ptr) delete [] ptr;
        cout << "Destructor got called" << endl;
    }

    uint64_t get_size() { return sz; }
    uint64_t get_capacity() { return capacity; }

    void push_back(int num) {
        if (ptr == nullptr) {
            ptr = new int[1];
            ptr[0] = num;
            sz = 1;
            capacity = 1;
            return;
        }

        if (sz < capacity) {
            ptr[sz++] = num;
        } else {
            uint64_t cc = capacity * 2;
            int *k = new int[cc];
            for (uint64_t i = 0; i < sz; i++) k[i] = ptr[i];
            delete [] ptr;
            ptr = k;
            ptr[sz++] = num;
            capacity = cc;
        }
    }

    void resize(int sssz) {
        if (sssz == sz) return;
        if (sssz < sz) {
            sz = sssz;
        } else {
            if (sssz > capacity) {
                int* new_ptr = new int[sssz];
                for (int i = 0; i < sz; i++) new_ptr[i] = ptr[i];
                for (int i = sz; i < sssz; i++) new_ptr[i] = 0;
                delete [] ptr;
                ptr = new_ptr;
                capacity = sssz;
            }
            sz = sssz;
        }
    }

    int at(uint64_t index) {
        if (index >= sz) throw "Index out of bounds";
        return ptr[index];
    }

    int & operator[](int index) {
        if (index < 0 || index >= sz) return fhaltu;
        return ptr[index];
    }
};

void sam() {
    vec v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.resize(10);
    v[4] = 1221;
    v[5] = 652;
    v[6] = 92;
    v[7] = 922;

    cout << "Initial vec:" << endl;
    for (int i = 0; i < v.get_size(); i++) cout << v[i] << endl;

    v[2] = 100;
    v[1] = 2000;

    cout << "Updated vec:" << endl;
    for (int i = 0; i < v.get_size(); i++) cout << v[i] << endl;

    // This will throw exception if you uncomment:
    // v[100] = 500;
}

int main() {
    sam();
    cout << "The end" << endl;
    return 0;
}
