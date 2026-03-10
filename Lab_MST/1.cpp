#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int>& a, pair<int, int>& b) {
    return (a.second - a.first) > (b.second - b.first);
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> tasks(n);

    for (int i = 0; i < n; i++) {
        cin >> tasks[i].first >> tasks[i].second;
    }

    sort(tasks.begin(), tasks.end(), comp);

    long long start = 0;
    long long current = 0;

    for (auto& t : tasks) {
        if (current < t.second) {
            start += (t.second - current);
            current = t.second;
        }

        current -= t.first;
    }

    cout << start << endl;
}
