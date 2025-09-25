#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define int ll

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    vector<int> cnt(n);
    cnt[0] = s[0] == 'a';

    for(int i = 1; i < n; i ++) 
        cnt[i] = (s[i]=='a') + cnt[i-1];
    
    auto sum_a = [&](int l, int r) -> int {
        if(r < 0 or l >= n) return 0;
        return cnt[r] - (l > 0 ? cnt[l-1] : 0);
    };

    auto len = [&](int l, int r) -> int {
        return r - l + 1;
    };

    auto sum_b = [&](int l, int r) -> int {
        return len(l, r) - sum_a(l, r);
    };


    
    int mi = LINF;
    {
        // A
        int val = 0;
        for(int i = 0; i < n; i ++){
            if(s[i]=='a'){
                int el = min(sum_b(0, i-1), sum_b(i + 1, n-1));
                val += el;
                // cout << el << " ";
            }
        }
        mi = min(mi, val);
    }
    // cout << endl;
    {
        // A
        int val = 0;
        for(int i = 0; i < n; i ++){
            if(s[i]=='b'){
                int el = min(sum_a(0, i-1), sum_a(i + 1, n-1));
                val += el;
                // cout << el << " ";
            }
        }
        mi = min(mi, val);
    }
    // cout << endl;
    cout << mi << endl;

}

int32_t main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
