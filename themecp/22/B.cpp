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
    map<int, int> cnt;
    set<int> done;
    for(int i = 0; i < n; i ++){
        int el; cin >> el;
        cnt[el] ++;
    }

    int flip = (1 << 31) -1;
    int res = 0;
    for(auto [key, val] : cnt){
        if(done.count(key)) continue;
        if(cnt.count(key ^ flip)) 
            res += max(val, cnt[key ^ flip]), done.insert(key), done.insert(key^flip);
        else res += val;
    }

    cout << res << endl;
}



int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
