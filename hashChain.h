//
// Created by Karyna Babenko on 20/05/2021.
//

#ifndef HASHCHAIN_H
#define HASHCHAIN_H
#include <tuple>
#include <vector>


int hash_chain(int k) {
    hash<int> hash;
    return hash(k);
}

struct hashChain {
    int find_counter = 0;
    vector<int> data[10];

    tuple<int, int> find_index(int k) {
        int h = hash_chain(k) % 10;

        for (auto it = data[h].begin(); it != data[h].end(); it++) {
            find_counter++;
            if (*it == k)
                return make_tuple(h, it - data[h].begin());
        }
        return make_tuple(h, -1);
    }

    int find(int k) {
        find_counter++;
        int h = get<0>(find_index(k));
        int i = get<1>(find_index(k));

        if (i == -1)
            return -3; //none, brak elementu
        return data[h][i];
    }

    void insert(int element) {
        int h = get<0>(find_index(element));
        int i = get<1>(find_index(element));

        if (i == -1)
            data[h].push_back(element); //wstawiamy na koniec
        else
            data[h][i] = element; //nadpisujemy element
    }

    void remove(int k) {
        int h = get<0>(find_index(k));
        int i = get<1>(find_index(k));

        if (i != -1) {
            data[h][i] = data[h].back();
            data[h].pop_back();
        } else
            throw "Element doesnt exist";
    }

    void print() {
        for (int i = 0; i < 10; i++) {
            cout << "Elements at index: " << i << ": ";
            for (auto it = data[i].begin(); it != data[i].end(); it++) {
                cout << *it << ' ';
            }
            cout << endl;
        }
    }

    void insert_random_values(int n, int from, int to) {
        for (int i = 0; i < n; i++) {
            int value = rand() % to + from;//random value from range
            insert(value);
        }
    }
};
#endif// HASHCHAIN_H
