//
// Created by finas on 4/23/2024.
//

#include <iostream>
#include <utility>
#include <optional>
#include "database.h"

using namespace std;

void Database::put(string key, int value) {
    /* will create a new key with the provided value if a key doesn’t exist.
     * Otherwise it will update the value of an existing key.*/
    if (ongoingTransaction) {
        _uncommitted[key] = std::move(value);
    }
    else {
        throw runtime_error("No transaction ongoing, cannot put.");
    }
}

optional<int> Database::get(string key) {
    /**/
    try {
        return _data.at(key);
    }
    catch (const out_of_range& e) {
        return nullopt;
    }
}

void Database::begin_transaction() {
    /**/
    if (!ongoingTransaction) {
        ongoingTransaction = true;
        cout << "Transaction started" << endl;
    } else {
        throw runtime_error("Already ongoing transaction!");
    }
}

void Database::commit() {
    /**/
    if (ongoingTransaction) {
        _data = _uncommitted;
        ongoingTransaction = false;
        cout << "Transaction committed" << endl;
    }
    else {
        throw runtime_error("No ongoing transaction to commit!");
    }

}

void Database::rollback() {
    /**/

    if (ongoingTransaction) {
        _uncommitted = _data;
        ongoingTransaction = false;
        cout << "Transaction rolled back" << endl;
    }
    else {
        throw runtime_error("No ongoing transaction to rollback!");
    }


}

bool Database::in_transaction() {
    return ongoingTransaction;
}

void Database::print_uncommitted() {
    cout << "Printing uncommitted data..." << endl;
    for (auto it = _uncommitted.begin(); it != _uncommitted.end(); it++) {
        cout << "Key: " << it->first << ", Value: " << it->second << endl;
    }
    cout << endl;
}
void Database::print_data() {
    cout << "Printing data..." << endl;
    for (auto it = _data.begin(); it != _data.end(); it++) {
        cout << "Key: " << it->first << ", Value: " << it->second << endl;
    }
    cout << endl;
}