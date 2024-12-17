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
    string s, t1, t2; cin >> s >> t1;
    t2 = t1; reverse(t2.begin(), t2.end());

    int cnt1 = 0, cnt2 = 0;
    for(int i = 0 ; i < n ; i ++)
    {
        cnt1 += (s[i] != t1[i]);
        cnt2 += (s[i] != t2[i]);
    }

    int res1 = ((cnt1 == 0 or cnt1 == 1) ? 1 : 2 * (cnt1 + 1));
    int res2 = (cnt2 == 0 ? 0 : 2 * cnt2 -1 ); 
    cout << min(res1, res2) << endl;
}

int main(){ _
    
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
