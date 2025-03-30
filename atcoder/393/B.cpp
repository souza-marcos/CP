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
    int n = sz(s);
    int cnt = 0;
    for(int i = 0; i < n; i ++){
        if(s[i] != 'A') continue;
        for(int j = 1; i + 2 * j < n; j ++){
            if(s[i + j] == 'B' and s[i + 2*j] == 'C') cnt ++;
        }
    }
    cout << cnt << endl;
    return 0;
} 
