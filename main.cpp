//
// Created by finas on 4/23/2024.
//

#include <iostream>
#include <vector>
#include "database.h"

using namespace std;

int main() {
    Database inmemoryDB;

// should return null, because A doesn’t exist in the DB yet
    optional<int> test1_res = inmemoryDB.get("A");
    if (test1_res != nullopt) {
        cout << "you FAIL!!! 1" << endl;
    }


// should throw an error because a transaction is not in progress

//    inmemoryDB.put("A", 5);
//    cout << "if you got here test 2 failed" << endl;

// starts a new transaction
    inmemoryDB.begin_transaction();
    if (!inmemoryDB.in_transaction()) {
        cout << "you failed test 3!!" << endl;
    }

// set’s value of A to 5, but its not committed yet
    inmemoryDB.put("A", 5);


// should return null, because updates to A are not committed yet
    optional<int> test5_res = inmemoryDB.get("A");
    if (test5_res != nullopt) {
        cout << "you FAIL!!! 5" << endl;
    }

// update A’s value to 6 within the transaction
    inmemoryDB.put("A", 6);



// commits the open transaction
    inmemoryDB.commit();
    if (inmemoryDB.in_transaction()) {
        cout << "you failed test 7!!" << endl;
    }




// should return 6, that was the last value of A to be committed
    if (inmemoryDB.get("A") != 6) {
        cout << "you failed test 8!!" << endl;
    }
    else {
    }

//// throws an error, because there is no open transaction
//    inmemoryDB.commit();
//    cout << "if you got here test 9 failed" << endl;


//    cout << "running test 10" << endl;
//// throws an error because there is no ongoing transaction
//    inmemoryDB.rollback();
//    cout << "if you got here test 10 failed" << endl;


// should return null because B does not exist in the database
    optional<int> test11_res = inmemoryDB.get("B");
    if (test11_res != nullopt) {
    }

//    cout << "running test 12" << endl;
// starts a new transaction
    inmemoryDB.begin_transaction();
    if (!inmemoryDB.in_transaction()) {
//        cout << "you failed test 12!!" << endl;
    }

//    cout << "running test 13" << endl;
// Set key B’s value to 10 within the transaction
    inmemoryDB.put("B", 10);


//    cout << "check if u passed test 13 based on the values above" << endl;

//    cout << "running test 14" << endl;
// Rollback the transaction - revert any changes made to B
    inmemoryDB.rollback();


//    cout << "check if u passed test 14 based on the values above" << endl;

//    cout << "running test 15" << endl;
// Should return null because changes to B were rolled back
    optional<int> test15_res = inmemoryDB.get("B");
    if (test15_res != nullopt) {
//        cout << "you FAIL!!! 15" << endl;
    }

    return 0;
}
