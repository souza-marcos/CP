#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

typedef long long ll;
const int INF = 0x3f3f3f3f; // -2e9 ... 2e9 
const ll LINF = 0x3f3f3f3f3f3f3f3fll; // -9e18 ... 9e18

void solve(){
    int n; cin >> n;
    vector<pair<int, int>> part(n);
    for(auto& el: part) cin >> el.first >> el.second;
    sort(part.begin() + 1, part.end()); // Policarp is on the 1-th position
    auto it = lower_bound(part.begin() + 1, part.end(), part[0]);
    if(it == part.end()){
        cout << part[0].first << endl;
        return;
    }
    while(it != part.end()){
        if(it->second >= part[0].second){
            cout << -1 << endl; return;
        }
        ++it;
    }
    cout << part[0].first << endl;

}

int main(){ _
    int t; cin >> t;
    while(t --) solve();

    return 0;
} 
