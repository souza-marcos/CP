#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'

int n;
int v[10001];
map<tuple<int, int, int>, bool> memo;

bool dp(int l, int r, int i){
    if(abs(l - r) > 5) return 0;
    if(i == n) return 1;
    
    if(memo.count({l, r, i}) > 0) return memo[{l, r, i}];

    return memo[{l, r, i}] = dp(l + v[i], r, i + 1) or dp(l, r + v[i], i+1);
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> v[i]; 
    memo.clear();
    cout << (dp(0,0,0)?"Feliz Natal!": "Ho Ho Ho!") << endl;
}

int main(){_

    int t; cin >> t;
    while(t --) solve();

    return 0;   
}