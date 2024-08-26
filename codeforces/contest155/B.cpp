#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

typedef long long ll;
const int INF = 0x3f3f3f3f; // -2e9 ... 2e9 
const ll LINF = 0x3f3f3f3f3f3f3f3fll; // -9e18 ... 9e18

void solve(){
    ll n; cin >> n;
    vector<int> a(n), b(n);
    ll sum_a = 0, sum_b = 0;
    for(auto& el: a) {cin >> el; sum_a += el;}
    for(auto& el: b) {cin >> el; sum_b += el;}

    // iterate the rows
    auto min_b = min_element(b.begin(), b.end());
    auto min_a = min_element(a.begin(), a.end());
    cout << min((*min_a)*n + sum_b, (*min_b)*n + sum_a) << endl;
}

int main(){ _

    int t; cin >> t;
    while(t --) solve();

    return 0;
} 
