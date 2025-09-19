#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()
#define int ll

void solve(){
    int n, q; cin >> n >> q;
    vector<int> branch1, branch2;
    for(int i = 3; i <= n; i ++)
        branch1.push_back(i);

    for(int i = 1; i < n; i ++){
        cout << i << " " << i + 1 << endl;
    }

    while(q --){
        int a; cin >> a;
        if(sz(branch1) == a-1 or sz(branch2) == a-1){
            cout << "-1 -1 -1\n";
        }
        else {
            if(sz(branch1) > a-1){
                int pos = a-1;
                // cout << "DBG " <<pos << " " << sz(branch1) << " " << sz(branch2) << endl;
                cout << branch1[pos] << " " << (pos==0?2:branch1[pos-1]) << " " << (sz(branch2) == 0? 2 : branch2.back()) << endl;
                for(int i = pos; i < sz(branch1); i ++){
                    branch2.push_back(branch1[i]);
                }
                int tot = sz(branch1);
                for(int i = pos; i < tot; i ++) branch1.pop_back();
            } else {
                int res = a - 1 - sz(branch1);
                int pos = sz(branch2) - res;

                cout << branch2[pos] << " " << (pos==0?2:branch2[pos-1]) << " " << (sz(branch1) == 0? 2 : branch1.back()) << endl;
                for(int i = pos; i < sz(branch2); i ++){
                    branch1.push_back(branch2[i]);
                }
                int tot = sz(branch2);
                for(int i = pos; i < tot; i ++) branch2.pop_back();
            }
        }
    }
}

int32_t main(){ _
    int t; cin >> t;
    while(t --) solve();
} 
