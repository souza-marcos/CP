#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

int main(){ _
    int n; cin >> n;
    string s; cin >> s;

    int maxv = 1;
    for(int i= 0; i < n; i ++){
        if(s[i] != '/') continue;

        int cur = 1;
        int j = i - 1, k = i + 1;
        while(j >= 0 and k < n and s[j]=='1' and s[k]=='2')
            j --, k ++, cur += 2;

        maxv = max(maxv, cur);
    }

    cout << maxv << endl;

    return 0;
} 
