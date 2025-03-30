#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
   
    int n, k; cin >> n >> k;
    vector<pair<int, int>> monsters(n);
    for(auto &[pos, h]: monsters) cin >> h;
    for(auto &[pos, h]: monsters) cin >> pos, pos = abs(pos);

    sort(monsters.begin(), monsters.end());

    int cur = 0; ll extra_bullets = 0;
    for(auto [pos, h]: monsters){
        extra_bullets += 1LL* k *(pos - cur);
        cur = pos;
        if(h > extra_bullets){
            cout << "NO\n";
            return;
        }
        extra_bullets -= h;
    }
    cout << "YES\n";
}



int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
