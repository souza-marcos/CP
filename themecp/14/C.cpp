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
    
    vector<int> arr(n), pref(n + 1);
    pref[0] = 0;
    for(int i = 0; i < n; i ++){
        cin >> arr[i];
        pref[i + 1] = pref[i] ^ arr[i];
    }
    int cur = pref[n];

    string s; cin >> s;
    int i = 0;
    for(auto c : s){
        if(c - '0' == 0) cur ^= arr[i ++];
    }
    int q; cin >> q;
    while(q --) {
        int t; cin >> t;
        if(t == 1){
            int l, r; cin >> l >> r;
            cur ^= pref[r]^pref[l-1];
        } else{
            int bit; cin >> bit;
            if(bit){
                cout << cur << " ";
            }
            else{
                cout << (cur ^ pref[n]) << " ";
            }
        }
    }
    cout << endl;

}   

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
