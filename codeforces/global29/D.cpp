#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        map<int, int> freq;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            freq[a[i]]++;
        }
        priority_queue<pair<int, int>> pq;
        for (auto &p : freq) {
            pq.push({p.second, p.first});
        }
        int turn = 0;
        long long alice = 0, bob = 0;
        while (!pq.empty()) {
            int f = pq.top().first;
            int v = pq.top().second;
            pq.pop();
            if (f != freq[v]) continue;
            if (turn == 0) {
                alice += f;
            } else {
                bob += f;
            }
            freq[v] = 0;
            if (v > 0) {
                freq[v-1] += f;
                pq.push({freq[v-1], v-1});
            }
            turn = 1 - turn;
        }
        cout << alice << " " << bob << endl;
    }
    return 0;
}