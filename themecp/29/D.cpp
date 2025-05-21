#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    // Quero para cada el => definir sua classe mod k
    // Cada classe deve ser par 
    // o minimo é arranjado em ordem e pego dois els adjacentes.

    ll n, k; cin >> n >> k;
    
    
    map<ll, vector<ll>> classes;
    for(int i = 0; i < n; i ++){
        ll a; cin >> a;
        classes[a%k].push_back(a);
    }

    if(n == 1) { cout << 0 << endl; return ;}


    // Se n eh impar tenho que escolher qual o melhor elemento para o meio

    ll res = 0;
    int rem = n&1;
    for(auto& [b, bag] : classes){
        if(sz(bag)%2 == 1 and rem<1){
            cout << -1 << endl;
            return;
        }

        if(sz(bag) == 1){
            rem --;
            continue;
        }

        vector<ll> pre(sz(bag)), suff(sz(bag));
        sort(bag.begin(), bag.end());
        for(int i = 0; i + 1 < sz(bag); i+=2){
            pre[i/2 + 1] = pre[i/2] + (bag[i + 1] - bag[i]) /k;
        }
 
        for(int i = sz(bag)-1; i -1 > 0; i-=2){
            suff[ceil(i/2.0)] = suff[ceil(i/2.0) + 1] + (bag[i] - bag[i-1])/k;
        }
        
        if(sz(bag)%2==0){
            for(int i = 0; i + 1 < sz(bag); i+=2){
                res += (bag[i + 1] - bag[i]) /k;
            }
        }else{
            ll minv = LINF;
            for(int i = 0; i < sz(bag); i++){
                ll val =  pre[i/2] + suff[(i + 1)/2 + 1] + (i%2 == 1? (bag[i + 1] - bag[i-1])/k : 0);
                minv = min(minv, val);
            }
            res += minv;
            rem --;    
        }
    }
    cout << res << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
