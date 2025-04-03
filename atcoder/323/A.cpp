#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int main(){ _
    string s; cin >> s;
    bool ok = true;
    for(int i = 1; i < 16; i += 2) ok &= s[i]=='0';

    cout << (ok ? "Yes\n": "No\n");
} 
