// https://csacademy.com/contest/archive/task/xor-closure/statement/
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
    vector<ll> basis;

    auto add = [&](ll a){
        for(ll b : basis) a = min(a, a ^ b);
        if(a) basis.push_back(a);
    };

    for(int i = 0; i < n; i ++){
        ll a; cin >> a;
        add(a);
    }

    cout << (1LL << sz(basis)) - n << endl;
    return 0;
} 
