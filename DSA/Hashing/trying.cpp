#include <iostream>
#include <string>
using namespace std;

#define HASH_TABLE_SIZE 1000

// Function to compute custom hash value
long long customHash(const string& key) {
    long long hashValue = 0;
    for (char ch : key) {
        hashValue = (hashValue * 37) + ch; // Hash function calculation
    }
    return hashValue % HASH_TABLE_SIZE;
}

int main() {
    while (true) {
        string subject;
        getline(cin, subject);

        // Exit condition
        if (subject == "exit") {
            break;
        }

        // Calculate hash value for the subject name
        long long hashValue = customHash(subject);
        cout << hashValue << endl;
    }

    return 0;
}
