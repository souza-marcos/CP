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

    int n; cin >> n;
    string s; cin >> s;
    deque<int> dq;
    for(auto ch : s) dq.push_back(ch - '0');

    int op = 0, init = 0;
    vector<int> pos;
    while(sz(dq)){
        if(op == 301){
            cout << -1 << endl;
            return;
        }

        if(dq.front() != dq.back()){
            dq.pop_front(), dq.pop_back();
            init ++;
        }
        else {
            if(dq.front() == 1){
                // Inserir na frente
                pos.push_back(init);
                op ++;
                dq.push_front(1), dq.push_front(0);  
            }
            else {
                pos.push_back(init + sz(dq));
                op ++;
                dq.push_back(0), dq.push_back(1);  
            }
        }
    }   
    cout << sz(pos) << endl;
    for(auto el : pos) cout << el << " ";
    cout << endl;
}

int32_t main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
