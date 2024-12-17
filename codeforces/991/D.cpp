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
    for(int i = 0; i < sz(s); i ++){
        int best = i, val = s[i] - '0', original = val;
        for(int j = 1; j < 9; j++){
            if(i + j >= sz(s)) break;
            int el = s[i + j] - '0';
            el -= j;
            if(el > val) val = el, best = i + j;
            if(el == val and el + j < original) 
                val = el, best = i + j, original = el + j; 
        }
        if(val == 0) continue;
        for(int j = i; j < best; j ++){
            s[j + 1] = s[j];
        }
        s[i] = val + '0';

        cout << s << endl;
    }

    cout << s << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
