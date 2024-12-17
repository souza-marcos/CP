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
    string s; cin>> s;
    vector<int> dict(26, -1);
    vector<bool> vis(26, false);
    for(auto el: s){
        int c = el - 'a';
        if(vis[c]) continue;
        for(int i = 0; i < 26; i ++){
            if(!vis[i]) dict[i] =  
        }

    }


}

int main(){ _
    int t; cin >> t;
    while( t--) solve();
    return 0;
} 
