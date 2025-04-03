#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
const int MAX = 100 * 1000;
ll ways[70001];

int main(){ _
    int n; cin >> n;
    ll maxs = (n+1)*n/2;
    if(maxs&1){ cout << 0 << endl; return 0; }
    maxs /= 2;
    const int MOD = 1e9 + 7;

    ways[0] = 1;
    for(int i = 1; i < n; i ++){
        for(int j = maxs; j >= i; j --){
            ways[j] = (ways[j] + ways[j-i]) % MOD;
        }
    }

    cout << ways[maxs]<< endl;
    return 0;
} 
