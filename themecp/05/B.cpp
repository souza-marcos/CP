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
    vector<int> arr(n);

    map<int , vector<int>> cnt;

    bool ok = true;
    int minv = INF;
    int i = 0;
    set<int> check;
    for(auto& el: arr) {
        cin >> el; minv = min(minv, el);
        check.insert(el);
        cnt[el].push_back(i ++);
    } 

    if(sz(check) == 1) { cout << 0 << endl; return; } 

    priority_queue<int> pq;
    for(auto [fr, sn]: cnt) pq.push(fr); 

    vector<pair<int , int>> res;
    ok = true;
    while(sz(pq) > 1){
        auto t1 = pq.top(); pq.pop();
        auto t2 = pq.top();

        if(t2 == 1) { ok = false; break; }
        res.push_back({cnt[t1].back(), cnt[t2].back()});

        if(sz(cnt[t1]) > 1) pq.push(t1);
        cnt[t1].pop_back();
        int newel = ceil(t1/(double)t2);
        if(!cnt.count(newel) or sz(cnt[newel]) == 0) pq.push(newel);
        cnt[newel].push_back(res.back().first);
    }

    if(!ok) { cout << -1 << endl; return; }
    cout << sz(res) << endl;
    for(auto el : res){
        cout << el.first + 1 << " " << el.second + 1 << endl;
    }
}   

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
