#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    for(int i = k; i < n; i ++){
        if(s[i] == '0' and s[i - k] == '1') { cout << "NO\n"; return; }
        if(s[i] == '1' and s[i - k] == '0') { cout << "NO\n"; return; }
        if(s[i] == '?') s[i] = s[i-k];
        if(s[i - k] == '?') s[i-k] = s[i];
    }
    int cnt_z = 0, cnt_o = 0;
    for(int i = 0; i < k; i ++){
        if(s[i] == '0') cnt_z ++;
        else if(s[i] == '1') cnt_o ++;
    }
    if(cnt_z > k/2 or cnt_o > k/2) { cout << "NO\n"; return; }

    for(int i = k; i < n; i++){
        if(s[i-k] == '0') cnt_z --;
        else if(s[i-k] == '1') cnt_o --;

        if(s[i] == '0') cnt_z ++;
        else if(s[i] == '1') cnt_o ++;

        if(cnt_z > k/2 or cnt_o > k/2) { cout << "NO\n"; return; }    
    }

    cout << "YES\n"; 
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
