#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'
// #define int ll

int32_t main(){ _
    
    int n, q; cin >> n >> q;
    vector<int> arr(n);
    for(int& el : arr) cin >> el;

    vector<tuple<int, int, int>> queries(q); // l, r, idx
    int i = 0;
    for(auto& [l, r, idx] : queries) cin >> l >> r, l --, r--, idx = i ++;

    int b = sqrt(n) + 1;

    sort(queries.begin(), queries.end(), [&](auto& l, auto& r){
        if(get<0>(l)/b == get<0>(r)/b) return get<1>(l) < get<1>(r);
        return get<0>(l)/b < get<0>(r)/b; 
    });

    int cnt = 0;
    int l0 = 0, r0 = -1;

    vector<int> times(1e5 + 1);

    auto add = [&](int comeco, int final) {
        for(int i = comeco; i <= final; i ++){
            if(arr[i] > 1e5) continue;
            
            int val = ++times[arr[i]];
            if(val == arr[i]) cnt ++;
            if(val == arr[i] + 1) cnt --;
        }
    };

    auto remove = [&](int comeco, int final){
        for(int i = comeco; i <= final; i ++){
            if(arr[i] > 1e5) continue;
            
            int val = --times[arr[i]];
            if(val == arr[i]) cnt ++;
            if(val == arr[i]-1) cnt --;
        }
    };

    vector<int> res(q);
    for(auto [l, r, idx] : queries){
        if(r0 < r){
            add(r0+1, r);
            r0 = r;
        }
        if(l0 > l){
            add(l, l0-1);
            l0 = l;
        }
        if(r0 > r){
            remove(r+1, r0);
            r0 = r;
        }
        if(l0 < l){
            remove(l0, l-1);
            l0 = l;
        }
        res[idx] = cnt;
    }

    for(int i : res) cout << i << "\n";
    
    return 0;
} 