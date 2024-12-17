#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

void solve(){
    
    string s; cin >> s;
    auto f = [&](int i) -> int {
        return s[i]-'0';
    };

    if(s[0] == '1' or s[sz(s)-1] == '1') { cout << -1 << endl; return; }
    if(sz(s) == 1) { cout << 1 << endl << 1 << " " <<  1 << endl; return; }

    int cur = 0;
    string s;

    queue<int> zeb;
    queue<int> quase;
    vector<vector<int>> res;

    for(int i = 0; i < sz(s)-1; i ++){
        int c = f(i);
        if(c == 0 and )
    }


}

int main(){ _
    solve();
    return 0;
} 
