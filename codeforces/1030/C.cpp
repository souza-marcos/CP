#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
/*
Quero pegar sempre o numero com bit menos significativo das que ainda
tenho e tentar ligar.  
*/
void solve(){
    ll n, k; cin >> n >> k;
    priority_queue<string, vector<string>, greater<>> pq;
    ll res = 0;
    for(int i = 0; i < n; i ++){
        ll a; cin >> a;
        string s;
        for(int bit = 0; bit < 63; bit ++){
            s.push_back('0' + ((a >> bit) & 1LL));
            res += s[bit] == '1';
        }
        pq.push(s);
    }

    bool ok = true;
    while(k > 0){
        string s = pq.top(); pq.pop();
        for(ll i = 0, cost = 1; i < sz(s); i ++, cost <<= 1){
            if(s[i] == '0'){
                // Quanto custa eu aumentar esse bit? -> 2^i
                if(k < cost){
                    k = 0;
                    break;
                }
                k -= cost;
                s[i] = '1';
                pq.push(s);
                res ++;
                break;
            }
        }
    }
    cout << res << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
