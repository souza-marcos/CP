#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> arr;
        arr.push_back(0);

        for(int i = 1; i < n + 1; i++)
            arr.push_back((i % 2) + arr[i / 2]);
        
        return arr;
    }
};

int main(){ _
    int n; cin >> n;
    Solution s; 
    for(auto el : s.countBits(n)) cout << el << " ";

    return 0;
} 
