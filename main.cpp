#include <iostream>
using namespace std;
#include "hashChain.h"
#include "hashOpen.h"
#include <ctime>

int random_int(int from, int to) {
    return rand() % to + from;
}

int main() {
    srand(time(NULL));

    //open addressing test
    hashOpen dict(100000);

    int number = 0;
    int insertions = 0;
    int from = 0;
    int to = 1000000;

    int sum = 0;

    while (insertions < dict.size) {
        do {
            number = random_int(from, to);
        } while (dict.find(number) != -2);
        dict.insert(number);
        insertions++;

        int looking_for = random_int(from, to);
        dict.find_counter = 0;
        dict.find(looking_for);
        sum += dict.find_counter;

        if (insertions % 100 == 0) {
            cout << endl
                 << insertions << "\t" << sum / 100;
            sum = 0;
        }
    }

    cout<<endl<<endl;

    //separate chaining test
    hashChain dict1;
    number = 0;
    insertions = 0;
    from = 0;
    to = 1000000;

    int size = 10000;
    sum = 0;

    while (insertions < size) {
        do {
            number = random_int(from, to);
        } while (dict1.find(number) != -3);
        dict1.insert(number);
        insertions++;

        int looking_for = random_int(from, to);
        dict1.find_counter = 0;
        dict1.find(looking_for);
        sum += dict1.find_counter;

        if (insertions % 10 == 0) {
            cout << endl
                 << insertions << "\t" << sum / 10;
            sum = 0;
        }
    }

    //bucket size
    for (int i = 0; i < 10; i++) {
        cout << "\nBucket "<<i <<": "<< "\t" << dict1.data[i].size();
    }


    return 0;
}
