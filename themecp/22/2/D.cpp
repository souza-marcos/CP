#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    int n, m; cin >> n >> m;
    set<int> st = {1, m};
    vector<tuple<int, int, int>> segs(n);

    for(int i = 0; i < n; i ++){
        auto &[fr, sn, id] = segs[i];
        cin >> fr >> sn;
        st.insert({fr, sn});
    }

    map<int, int> mp; int cnt = 0;
    for(auto el : st) mp[el] = cnt ++;

    for(auto &[l, r, id] : segs) l = mp[l], r = mp[r];
    sort(segs.begin(), segs.end());
    // for(auto [l, r, id] : segs) cout << l << " " << r << endl;

    // 0 livre
    vector<int> arr(cnt + 2);
    for(auto [l, r, id] : segs){
        if(l == 0) continue;
        arr[l] ++, arr[r + 1] --;
    }


    int maxd = 0;
    int cur = 0;
    for(auto el : arr) cur += el, maxd = max(maxd, cur);//, cout << el << " ";
    // cout << endl;

    arr.assign(cnt+2, 0);
    for(auto [l, r, id] : segs){
        if(r == mp[m]) continue;
        arr[l] ++, arr[r + 1] --;
    }
    cur = 0;
    for(auto el : arr) cur += el, maxd = max(maxd, cur);//, cout << el << " ";
    // cout << endl;
    cout << maxd << endl;
}   

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
