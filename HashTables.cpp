//Using unordered_map (Standard library)
#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<string, int> hashTable;

    // Insert key-value pairs
    hashTable["Alice"] = 25;
    hashTable["Bob"] = 30;
    hashTable["Charlie"] = 22;

    // Access elements
    cout << "Alice's age: " << hashTable["Alice"] << endl;

    // Check if a key exists
    if (hashTable.find("David") == hashTable.end()) {
        cout << "David not found in the hash table.\n";
    }

    // Iterating through the hash table
    cout << "Hash Table Elements:\n";
    for (auto& pair : hashTable) {
        cout << pair.first << " -> " << pair.second << endl;
    }

    // Removing an element
    hashTable.erase("Bob");

    cout << "After deleting Bob:\n";
    for (auto& pair : hashTable) {
        cout << pair.first << " -> " << pair.second << endl;
    }

    return 0;
}
//Implementing a custom hash table(Using seperate chaining)
#include <iostream>
#include <list>
using namespace std;

class HashTable {
private:
    static const int SIZE = 10;
    list<pair<int, string>> table[SIZE]; // Array of linked lists

    int hashFunction(int key) {
        return key % SIZE; // Simple modulo-based hash function
    }

public:
    void insert(int key, string value) {
        int index = hashFunction(key);
        table[index].push_back({key, value});
    }

    string search(int key) {
        int index = hashFunction(key);
        for (auto& pair : table[index]) {
            if (pair.first == key)
                return pair.second;
        }
        return "Not Found";
    }

    void remove(int key) {
        int index = hashFunction(key);
        table[index].remove_if([key](const pair<int, string>& p) { return p.first == key; });
    }

    void display() {
        for (int i = 0; i < SIZE; i++) {
            cout << "Index " << i << ": ";
            for (auto& pair : table[i]) {
                cout << "[" << pair.first << " -> " << pair.second << "] ";
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable ht;
    ht.insert(1, "Alice");
    ht.insert(2, "Bob");
    ht.insert(12, "Charlie"); // Collides with key 2

    cout << "Searching for key 2: " << ht.search(2) << endl;

    cout << "Before deletion:\n";
    ht.display();

    ht.remove(2);
    cout << "After deleting key 2:\n";
    ht.display();

    return 0;
}
//Hash table using open addressing (Linear Probing)
#include <iostream>
using namespace std;

class HashTable {
private:
    static const int SIZE = 10;
    int keys[SIZE];
    string values[SIZE];
    bool occupied[SIZE];

    int hashFunction(int key) {
        return key % SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < SIZE; i++) {
            occupied[i] = false;
        }
    }

    void insert(int key, string value) {
        int index = hashFunction(key);

        // Linear probing in case of collision
        while (occupied[index]) {
            index = (index + 1) % SIZE; // Move to next index
        }

        keys[index] = key;
        values[index] = value;
        occupied[index] = true;
    }

    string search(int key) {
        int index = hashFunction(key);
        int startIndex = index; // Keep track of the start index to avoid infinite loops

        while (occupied[index]) {
            if (keys[index] == key)
                return values[index];

            index = (index + 1) % SIZE; // Move to the next slot
            if (index == startIndex) // Full loop
                break;
        }

        return "Not Found";
    }

    void display() {
        cout << "Hash Table:\n";
        for (int i = 0; i < SIZE; i++) {
            if (occupied[i]) {
                cout << i << " -> [" << keys[i] << " -> " << values[i] << "]\n";
            } else {
                cout << i << " -> [Empty]\n";
            }
        }
    }
};

int main() {
    HashTable ht;
    ht.insert(1, "Alice");
    ht.insert(2, "Bob");
    ht.insert(12, "Charlie"); // Collision with key 2 (same hash)

    cout << "Searching for key 12: " << ht.search(12) << endl;

    ht.display();

    return 0;
}
//Hash table using map (Red-black tree)
#include <iostream>
#include <map>

using namespace std;

int main() {
    map<int, string> hashTable; // Uses Red-Black Tree (ordered)

    // Insert key-value pairs
    hashTable[10] = "Apple";
    hashTable[20] = "Banana";
    hashTable[15] = "Cherry";
    hashTable[5] = "Dates";

    // Display elements (sorted order)
    cout << "Hash Table Elements:\n";
    for (auto& pair : hashTable) {
        cout << pair.first << " -> " << pair.second << endl;
    }

    // Search for an element
    int key = 15;
    if (hashTable.find(key) != hashTable.end()) {
        cout << "Found key " << key << ": " << hashTable[key] << endl;
    } else {
        cout << "Key " << key << " not found.\n";
    }

    // Delete an element
    hashTable.erase(20);
    cout << "After deleting key 20:\n";
    for (auto& pair : hashTable) {
        cout << pair.first << " -> " << pair.second << endl;
    }

    return 0;
}