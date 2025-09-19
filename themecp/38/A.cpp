// https://codeforces.com/problemset/problem/1925/B
#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()
#define int ll

int32_t main(){ _ 

    int t; cin >> t;

    while(t--){
        
        int x, n; cin >> x >> n;
        int mx = -1;
        vector<int> divs = {1, x};
        
        for(int i = 1; i * i <= x; i ++){
            divs.push_back(i), divs.push_back(x/i);
        }

        sort(divs.begin(), divs.end());
        
        for(int el : divs){
            int rest = x - (n-1) * el;
            if(rest > 0 and rest % el == 0) mx = el;
        }
        cout << mx << endl;
    }
} 
