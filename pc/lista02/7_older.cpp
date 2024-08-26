#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'

int n;
vector<int> v;
int memo[1001][1001];

int dp(int l, int r, int t){
    if(l > r) return 0;

    auto& p = memo[l][r];
    if(p != -1) return p;
    
    if(t%2) return p = min(dp(l + 1, r, t + 1), dp(l, r - 1, t + 1));
    return p = max(dp(l + 1, r, t + 1) + v[l], dp(l, r - 1, t + 1) + v[r]);
}

int main(){_

    while(cin >> n and n != 0){
        v.resize(2 * n);
        
        for(int& el: v) {
            cin >> el;
            el = (el + 1) % 2;
        }

        memset(memo, -1, sizeof memo);

        cout << dp(0, 2*n-1, 0) << endl;
    }

    return 0;
}