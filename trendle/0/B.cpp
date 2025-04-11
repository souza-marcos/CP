#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()


void solve(){
    int n; cin >> n;
    map<string, int> cnt;
    for(int i = 0; i < n; i ++){
        string s; cin >> s;
        cnt[s] ++;
    }

    for(auto [key, val] : cnt){
        if(val > n/2){
            cout << key << endl;
            return;
        }
    }
    cout << "vixe\n";
}

int main(){ _
    // int t; cin >> t;
    // while(t--) 
        solve();
} 
