//
// Created by finas on 4/23/2024.
//

#ifndef EC_DATAPROCESSING_DATABASE_H
#define EC_DATAPROCESSING_DATABASE_H

#include <unordered_map>
#include <optional>

using namespace std;

class Database {
    private:
        unordered_map<string, int> _data;
        unordered_map<string, int> _uncommitted;
        bool ongoingTransaction = false;
    public:
        void begin_transaction();
        void put(string key, int value);
        optional<int> get(string key);
        void commit();
        void rollback();
        bool in_transaction();
        void print_uncommitted();
        void print_data();
};


#endif //EC_DATAPROCESSING_DATABASE_H
