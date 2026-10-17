
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class MiniRedis {
private:
    unordered_map<string, string> db;

public:
    void setValue(const string& key, const string& value) {
        db[key] = value;
        cout << "OK\n";
    }

    void getValue(const string& key) {
        auto it = db.find(key);

        if (it != db.end()) {
            cout << it->second << '\n';
        } else {
            cout << "(nil)\n";
        }
    }

    void deleteValue(const string& key) {
        if (db.erase(key)) {
            cout << "Key deleted\n";
        } else {
            cout << "Key not found\n";
        }
    }
};

int main() {
    MiniRedis redis;
    string command, key, value;

    cout << "MiniRedis started!\n";
    cout << "Commands: SET, GET, DEL, EXIT\n";

    while (true) {
        cout << "MiniRedis> ";

        if (!(cin >> command)) {
            break;
        }

        if (command == "SET") {
            cin >> key;
            getline(cin >> ws, value);
            redis.setValue(key, value);
        }
        else if (command == "GET") {
            cin >> key;
            redis.getValue(key);
        }
        else if (command == "DEL") {
            cin >> key;
            redis.deleteValue(key);
        }
        else if (command == "EXIT") {
            break;
        }
        else {
            cout << "Unknown command\n";
        }
    }

    cout << "MiniRedis stopped!\n";
    return 0;
}
