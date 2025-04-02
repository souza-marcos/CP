#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()



int main(){ _
    const int MAX = 1e6 + 10;
    vector<ll> mindiv(1e6 + 10);
    iota(mindiv.begin(), mindiv.end(), 0);
    for(ll i = 2; i < MAX; i ++){
        if(mindiv[i] == i){
            for(ll j = i*i; j < MAX; j += i)
                mindiv[j]=min(mindiv[j], i);
        }
    }
    // for(int i = 0 ; i < 100; i ++) cout << mindiv[i] << " ";
    // cout << endl;

    int t; cin >> t;
    while(t --){

        ll n, m; cin >> n >> m;
        if(n == 1){
            cout << "YES\n";
            continue;
        }
        
        if(m >= mindiv[n]) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
} 
