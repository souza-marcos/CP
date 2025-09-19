// https://codeforces.com/problemset/problem/2048/C
#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()
#define int ll

int32_t main(){ _ 

    int t; cin >> t;
    while(t --) {

        string s; cin >> s;
        int n = sz(s);

        int fzero = -1, szero = -1;
        bool ok = true;
        for(int i = 0; i < sz(s); i ++){
            if(s[i] == '0'){
                if(ok) {
                    fzero = i;
                    ok = false;
                }
            }

            if(s[i] == '1' and not ok){
                szero = i-1;
                break;
            }
        }
        if(szero == -1) szero = n;

        cout << "1 " << n << " ";

        int cnt_zero = (fzero == -1 ? 0 : szero - fzero + 1);
        if(cnt_zero == 0){
            cout << n << " " << n << endl;
            continue;
        }

        int cnt_one_before = fzero; 
        if(cnt_one_before <= cnt_zero){
            cout << 1 << " " << n-fzero << endl;
        }
        else {
            int fone = fzero - cnt_zero + 1;
            cout << fone << " " << n-cnt_zero << endl;
        }
    }

} 
