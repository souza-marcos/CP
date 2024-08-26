#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

map<ll, ll> ing_rec;
vector<pair<ll, ll>> ing(3);
ll money;


int conv(char c) {
    if(c == 'B') return 0;
    if(c == 'S') return 1;
    return 2;
}

bool valid(ll chute){
    ll rest = money;
    for(int i = 0; i < 3; i++) {
        ll diff = (chute * ing_rec[i]) - ing[i].first;
        ll buy = ((diff <= 0)? 0: diff);
        rest -= (buy * ing[i].second);
        if(rest < 0) return false;
    }
    return true;
}

int main(){
    string rec; cin >> rec;
    for(auto el: rec) ing_rec[conv(el)] ++;
    for(auto& el: ing) cin >> el.first;
    for(auto& el: ing) cin >> el.second;
    cin >> money;

    ll l = 0, r = 1;
    while(valid(r)) r *= 2;

    while(l + 1 < r){
        ll m = (l + r)/2;
        if(valid(m)) l = m;
        else r = m;
    }
    cout << l << endl;

    return 0;
} 
