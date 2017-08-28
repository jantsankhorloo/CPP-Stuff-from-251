#include <iostream>
#include <cstdlib>
#include <cstring>
#include <utility>
#include "cuckoo.h"
#include <cstdio>
using namespace std;

void CuckooHashing1() {
    int iter, len, num;
    char command;
    
    cin >> len >> iter;    
    Cuckoo cuckoo(len, iter);

    while (cin >> command) {
        cin >> num;
        if (command == 'i') {
            if (cuckoo.lookup(num) == false) {
                cuckoo.insert(num);
            }
            else if (cuckoo.lookup(num) == true) {
                cout << num << " already in T" << cuckoo.whichtable(num) 
                            << "[" << cuckoo.where(num) << "]" << endl;
            }
        }
        if (command == 'r') {
            cuckoo.remove(num);
        }
        if (command == 'l') {
            if (cuckoo.lookup(num)) {
                cout << num << " at T" << cuckoo.whichtable(num) 
                            << "[" << cuckoo.where(num) << "]" << endl;
            } else { cout << "no " << num << endl;}
        }
    }
}

/* Main function */
int main(int argc, char** argv) {

    /* Read the option */
    int option;
    std::cin >> option;

    /* Call the respective function */
    switch(option) {

        /* Cuckoo Hashing */
        case 1:
            CuckooHashing1();
            break;

        /* Binary Heap */
        /* Wrong option */
        default:
            std::cout << "Wrong option" << std::endl;

    }

    /* Close the program */
	return 0;
}

