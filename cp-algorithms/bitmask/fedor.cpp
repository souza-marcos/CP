#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

typedef long long ll;
const int INF = 0x3f3f3f3f; // -2e9 ... 2e9 
const ll LINF = 0x3f3f3f3f3f3f3f3fll; // -9e18 ... 9e18

// Substitui __popcount para g++ <= 17
int count_set_bits(ll x){
    int cnt = 0;
    while(x){
        cnt++;
        x = x & (x - 1);
    }
    return cnt;
}


int main(){ _
    int n, m, k; cin >> n >> m >> k;
    vector<ll> pler(m);
    for(auto& el: pler) cin >> el;

    int x; cin >> x;
    int cnt = 0;
    for(ll el: pler) 
        if(__popcount((x ^ el)) <= k) cnt ++;

    cout << cnt << endl;

    return 0;
} 
