#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'
// #define int ll 

void solve(){
    int n, m; cin >> n >> m;
    priority_queue<pair<int, int>> pq;
    for(int i =0 ; i < n; i ++){
        string s; cin >> s;
        int j = sz(s)-1;
        while(j >= 0 and s[j] == '0') j--;
        pq.push({sz(s)-1-j, sz(s)});
        // cout << s << " " << sz(s)-1-j << " " << sz(s) << endl;
    }

    bool anna = 1;
    while(sz(pq) > 0){
        if(anna){
            auto el = pq.top(); pq.pop();            
            pq.push({0, el.second - el.first});
        } else{
            auto el1 = pq.top(); pq.pop();
            if(sz(pq) == 0){
                if(el1.second > m) cout << "Sasha\n";
                else cout << "Anna\n";
                return ;
            }

            auto el2 = pq.top(); pq.pop();
            pq.push({el2.first, el1.second + el2.second});
        }
        anna ^= 1;
    }

}

int32_t main(){ _ 
    int t; cin >> t;
    while(t --) solve();
} 
