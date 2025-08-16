#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

const int MAX = 1e6;

int main(){ _ 
    vector<bool> ehprimo(MAX + 1, 1);
    vector<ll> primos; 
    for(int i = 2; i <= MAX; i ++){
        if(ehprimo[i])
        {
            for(int j = i * i; j <= MAX; j += i)
                ehprimo[j] = 0;
            primos.push_back(i);

        }
    }

    int t; cin >> t;
    while( t--){
        ll n; cin >> n;
        ll st = sqrt(n);

        for(ll i = st*st; i <= (st + 1) * (st + 1); i++){
            if
        }
    }


    return 0;
} 
