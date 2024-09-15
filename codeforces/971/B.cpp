#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

void solve(){
    int n; cin >> n;
    stack<int> res;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        for(int i = 0; i < 4; i ++) 
            if(s[i] == '#') {
                res.push(i + 1);
                break;
            }

    }

    while(!res.empty()) {
        cout << res.top() << " ";
        res.pop();
    }
    cout << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
