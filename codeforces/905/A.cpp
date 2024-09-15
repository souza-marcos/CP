#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define sx(x) (int)x.size()
#define endl "\n"

void solve(){
    string s; cin >> s;
    int cnt = 0, cur = 1;
    for(int i = 0; i < s.size(); i++){
        int val = s[i] - '0';
        if(val == 0) val = 10;
        cnt += abs(cur - val) + 1;
        cur = val;
    }
    cout << cnt << endl;
}

int main(){ _

    int t; cin >> t;
    while(t --) solve();

    return 0;
} 
