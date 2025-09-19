#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

int main(){  _

    int n; cin >> n;

    vector<int> primes;
    vector<bool> ehprimo(71, 1);
    ehprimo[1] = false;
    for(int i = 2; i <= 70; i ++)
    {
        if(ehprimo[i]){
            primes.push_back(i);
            for(int j = i*i; j <= 70; j += i){
                ehprimo[j] = 0;
            }
        }
    }


    vector<int> basis; // no expoente da fatoração

    auto add = [&](int a) {
        for(int u : basis) a = min(a, a ^ u);
        if(a) basis.push_back(a);
    };

    for(int i = 0; i < n; i ++) {
        int a; cin >> a;

        // fact
        int exp = 0;
        for(int j = 0; j < sz(primes); j ++){
            int d = primes[j];
            while(a % d == 0){
                exp = exp ^ (1 << j);
                a /= d;
            }
        }
        add(exp);
    }

    // size of nullspace

    int nspace = n-sz(basis);
    const int MOD = 1e9 + 7;
    ll res = 1;
    ll a = 2;
    while(nspace){
        if(nspace&1) res = res * a % MOD;
        a = a * a % MOD; 
        nspace >>= 1;
    }
    cout << (res - 1 + MOD) % MOD << endl; 
    return 0;
} 
