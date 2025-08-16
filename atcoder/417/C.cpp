#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()
   
int main(){ _
    int n; cin >> n;
    
    ll res = 0;
    vector<ll> cnt(n);
    for(int i=0;i<n; i++){
        int a; cin >> a;
        if(i-a>=0) res += cnt[i-a];
        if(i+a<n) cnt[i+a]++;
    }
    cout << res << endl;
    return 0;
} 
