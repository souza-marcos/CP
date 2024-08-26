#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl '\n'
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int prof = 0;
        for(int i = 0; i + 1 < prices.size(); i++){
            if(prices[i] < prices[i + 1]){
                prof += prices[i + 1] - prices[i];
            }
        }
        return prof;
    }
};


int main(){ _
    int n; cin >> n;
    vector<int> s(n);
    for(auto& el: s) cin >> el;
    Solution so;
    cout << so.maxProfit(s) << endl;
    return 0;
} 
