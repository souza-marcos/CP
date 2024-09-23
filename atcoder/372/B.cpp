#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

int main(){ _
    ll pre[11];
    ll cur = 1;
    for(int i = 0; i < 11; i ++){
        pre[i] = cur;
        cur *= 3;
    }

    int m; cin >> m;
    vector<int> res;
    for(int i = 10; i >= 0; i--){
        while(pre[i] <= m) res.push_back(i), m -= pre[i];
    }

    cout << sz(res) << endl;
    for(auto el : res) cout << el << " ";
    cout << endl; 
    return 0;
} 
