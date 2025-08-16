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
vector<string> res(26 * 3 + 1);
    for(int i = 25; i >= 0; i --){
    for(int j = 25; j >= 0; j --){
    for(int k = 25; k >= 0; k --){
        auto& el = res[i+j+k+3];
        el.clear();
        el.push_back((char)('a'+i));
        el.push_back((char)('a'+j));
        el.push_back((char)('a'+k));
    }   
    }    
    }

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << res[n] << endl;
    }
} 
