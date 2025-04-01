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
    vector<bool> eh_primo(MAX, true);
    
    for(ll i = 2; i < MAX; i ++){
        if(eh_primo[i]){
            for(ll j = i*i; j < MAX; j += i)
                eh_primo[j]=true;
        }
    }

    int t; cin >> t;
    while(t --){

        ll n, m; cin >> n >> m;
        if(n % m == 0){
            cout << "NO\n";
        } else
            cout << (eh_primo[m] ? "YES\n" : "NO\n");
    }
    return 0;
} 
