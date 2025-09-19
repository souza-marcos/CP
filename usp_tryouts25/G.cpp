#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define ff first
#define ss second
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define int ll
#define sz(x) (int)x.size()

int32_t main() { _
    int n; cin >> n;
    string s; cin >> s;

    ll res = 0;
    ll depth = 0;
    ll cur_open = 0, cur_close = 0;
    ll next_open = 0, next_close = 0;
    for(int i = 0; i < n; i ++){
        depth += (s[i] == '(' ? +1 : -1);
        next_close += (s[i] == ')');
        next_open += (s[i] == '(');
        if(depth == 0){
            res += cur_open * next_close;
            cur_open += next_open;
            cur_close += next_close;
            next_open = 0, next_close = 0;
        }
    }
    cout << res << endl;
}