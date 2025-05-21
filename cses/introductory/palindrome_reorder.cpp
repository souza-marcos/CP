#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

int main(){ _
    
    string s, res; cin >> s;
    sort(s.begin(), s.end());
    res.resize(sz(s));
    char last = s[0];
    bool rest = 1;
    char carry;

    int cnt = 0, k = 0;

    for(int i = 0; i < sz(s); i ++){   
        if(s[i] == last) cnt ++;
        else {
            if(cnt&1 and rest < 1){
                cout << "NO SOLUTION\n";
                return 0;
            }
            if(cnt&1) rest = 0, carry = last;
            for(int j = 0;j < cnt/2; j ++, k ++) 
                res[k] = res[sz(s)-1-k] = last;
            cnt = 1;
        }
        last = s[i];
    }

    if(cnt&1 and rest < 1){
        cout << "NO SOLUTION\n";
        return 0;
    }
    if(cnt&1) rest = 0, carry = last;
    for(int j = 0;j < cnt/2; j ++, k ++) 
        res[k] = res[sz(s)-1-k] = last;

    if(rest == 0) res[sz(s)/2]=carry;
    cout << res << endl;
    return 0;
} 
