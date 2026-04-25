#include <iostream>
using namespace std;

long long polyHash(string s) {
    long long p = 31;
    long long m = 1000000007;

    long long hash = 0;
    long long power = 1;

    for (char ch : s) {
        long long value = ch - 'a' + 1;
        hash = (hash + value * power) % m;
        power = (power * p) % m;
    }

    return hash;
}

int main() {
    string s = "geeksforgeeks";
    cout << polyHash(s) << '\n';
}
