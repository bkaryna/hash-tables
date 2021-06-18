//
// Created by Karyna Babenko on 20/05/2021.
//

#ifndef HASHOPEN_H
#define HASHOPEN_H

int hash_open(int k) {
    hash<int> hash;
    return hash(k);
}

struct hashOpen {
    int size;
    int find_counter;
    int *data;

    hashOpen() {
        size = 1;
        find_counter = 0;
        data = new int[size];
        initialize();
    }

    hashOpen(int n) {
        size = n;
        find_counter = 0;
        data = new int[n];
        initialize();
    }
    ~hashOpen() {
        delete[] data;
    }

    void initialize() {
        for (int i = 0; i < size; i++) {
            data[i] = -1;
        }
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << data[i] << "\t";
        }
    }

    bool empty(int i) {
        if (data[i] == -1)
            return true;
        else
            return false;
    }

    bool deleted(int i) {
        if (data[i] == -2)
            return true;
        else
            return false;
    }

    void cancel(int i) {
        data[i] = -2;
    }

    int key(int i) {
        return i;
    }

    int scan_for(int k) {
        int f = hash_open(k) % size; //pierwszy indeks
        int d = -1; //indeks pierwszej skasowanej komórki
        int i = f;
        while (!empty(i)) {
            find_counter++;
            if (deleted(i)) {
                if (d = -1)
                    d = i;
            } else if (key(data[i]) == k)
                return i;
            i = (i + 1) % size;
            if (i == f) //przeliczylismy cala tablice
                return d;
        }
        if (d != -1)
            return d;
        return i;
    }

    //zwraca elemt o kluczu k lub none gdy nie ma takiego elementu
    int find(int k) {
        find_counter++;
        int i = scan_for(k);
        if (i == -1 || empty(i) || deleted(i))
            return -2;
        return data[i];
    }

    void insert(int e) {
        int i = scan_for(key(e));
        if (i == -1)
            throw "No space for item";
        data[i] = e;
    }

    void remove(int k) {
        int i = scan_for(k);
        if (i != -1 && !empty(i))
            cancel(i);
    }

    void insert_random_values(int n, int from, int to) {
        for (int i = 0; i < n; i++) {
            int value = rand() % to + from;//random value from range
            insert(value);
        }
    }
};

#endif//HASHOPEN_H
