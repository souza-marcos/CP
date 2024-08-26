#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

class Solution {
public:
    const int MAX = 510;
    int memo[510][510];

    // Return point of Alice and Bob
    pair<int, int> solve(int l, int r, vector<int>& piles){
        if(l >= r) return 0;
        int& p = memo[l][r];
        if(p != -1) return p;

        


    }

    bool stoneGame(vector<int>& piles) {
        memset(memo, -1, sizeof memo);


    }
};
int main(){ _
    int n; cin >> n;
    vector<int> arr(n);
    for(auto& el: arr) cin >> el;

    Solution so;
    cout << so.stoneGame(arr) << endl;
    return 0;
} 
