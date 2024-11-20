#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define end '\n' 
#define sz(x) (int)x.size()

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    ll res = 1ll * n * (n + 1) / 2;
    vector<bool> removed(n, false);


    // Erase zeros
    int i = n-1, j = n-1;
    while(i > 0 and j > 0) {
        while(j >= 0 and s[j] == '0') j --;
        i = min(i-1, j);
        while(i >= 0 and s[i] == '1') i --;
        if(i < 0 or j < 0) break;

        removed[j] = removed[i] = true;
        res -= (j + 1);
        j--;
    }

    i = 0, j = n-1;
    while(i < j) {
        while(j > 0 and (s[j] == '0' or removed[j])) j --;
        while(i < n and removed[i]) i ++;

        if(i >= j) break;
        res -= (j+1);
        removed[j] = removed[i] = true;
        j --;
        i ++;
    }
    cout << res << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --)solve();
    return 0;
} 
