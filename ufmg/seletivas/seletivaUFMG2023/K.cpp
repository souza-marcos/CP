#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int main(){ _
    int n; cin >> n;
    string s; cin >> s;
    char maxc = 0;
    vector<int> present(256, 0);
    for(int i = 0; i < sz(s)/2 + 1; i ++){
        int j = s.size() - i - 1;
        present[s[i]] = true;
        present[s[i]] = true;
        if(s[i] != '?') maxc = max(maxc, s[i]);
        if(s[j] != '?') maxc = max(maxc, s[j]);

        if(s[i] == '?' and s[j] != '?') s[i] = s[j]; 
        else if(s[j] == '?' and s[i] != '?') s[j] = s[i];

        if(s[i] != s[j]) {cout << "IMPOSSIVEL\n"; return; }
    }
    if(maxc-'a' + 1 > n){cout << "IMPOSSIVEL\n"; return; }

    for(char c: s) if(c == '?')

    return 0;
} 
