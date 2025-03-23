#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    string a, b; cin >> a >> b;

    // max subsequence of B 
    vector<int> fo(26, -1);
    for(int i = 0; i < sz(b); i ++)
        if(fo[b[i] - 'a'] == -1) fo[b[i] - 'a'] = i; 


    int maxcnt = 0;
    for(int i = 0; i < sz(a); i ++){
        int beg = fo[a[i]-'a'];
        if(beg == -1) continue;

        int cnt = 1;
        int k = i + 1;
        for(int j = beg + 1; j < sz(b); j ++){
            while(k < sz(a) and a[k] != b[j]) k ++;
            if(k >= sz(a)) break;
            cnt ++, k ++;
        }
        
        maxcnt = max(maxcnt, cnt);
    }

    cout << sz(a) + sz(b) - maxcnt << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
