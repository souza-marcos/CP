#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    int n; cin >> n;
    vector<pair<int, int>> events;
    for(int i = 0; i < n; i ++){
        int a; cin >> a;
        events.push_back({a, 0});
    }
    
    for(int i = 0; i < n; i ++){
        int a; cin >> a;
        events.push_back({a, 1});
    }

    vector<ll> weig(n); for(auto& el : weig) cin >> el;
    sort(weig.begin(), weig.end());
    sort(events.begin(), events.end());
    ll res = 0;
    vector<ll> szs;
    vector<ll> wait;
    for(auto [p, t]: events){
        if(t == 0) wait.push_back(p);
        else szs.push_back(p - wait.back()), wait.pop_back();
    }
    sort(szs.rbegin(), szs.rend());
    for(int i = 0; i < n; i ++){
        res += szs[i] * weig[i];
    }
    cout << res << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
