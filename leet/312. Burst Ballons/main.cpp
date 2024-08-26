#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


class Solution {
public:

    int memo[310][310];
    vector<int> vals;

    int dp(int l, int r){
        int& p = memo[l][r];
        if(p != -1) return p;
        cout << l << ", " << r << endl;

        if(l == r){
            int ret = 1;
            if(l > 0) ret *= vals[l - 1];
            if(r < vals.size()) ret *= vals[r + 1];
            return p = ret;
        }

        int max_val = -INF;
        for(int i = l; i < r; i++){
            max_val = max(max_val,(l < i?dp(l, i - 1): 0) + (r > i?dp(i + 1, r):0) + dp(i, i));
        }
        return p = max_val;

    }

    int maxCoins(vector<int>& nums) {
        memset(memo, -1, sizeof memo);
        vals = nums;

        return dp(0, nums.size());
    }
};


int main(){ _
    int n; cin >> n;
    vector<int> arr(n);
    for(auto& el: arr) cin >> el;

    Solution so;
    cout << so.maxCoins(arr) << endl;
    return 0;
} 
