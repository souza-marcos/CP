#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

void solve(){
    int n, m, k ; cin >> n >> m >> k;
    string s; cin >> s;

    int cnt = 0, acc = 0;
    
    for(int i = 0; i < sz(s);){
        if(s[i] == '0') acc ++;
        if(s[i] == '1') acc = 0;

        if(acc >= m){
            cnt ++;
            acc = 0;
            i += k;
        }
        else i ++;
    }
    cout << cnt << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
