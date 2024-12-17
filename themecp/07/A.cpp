#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int main(){ _
    int t; cin >> t;
    while(t --){
        string s; cin >> s;
        int cnt[2] = {0};
        for(auto c: s) cnt[c-'0'] ++;
        int res = 0;
        for(int i = 0; i < sz(s); i ++){
            int ch = (s[i] - '0') ^ 1;
            if(cnt[ch] == 0) {
                res = sz(s) - i;
                break;
            }
            cnt[ch] --;
        }
        cout << res << endl;
    }

    return 0;
} 
