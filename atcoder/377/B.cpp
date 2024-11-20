#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'


int main(){ _
    set<int> unsaferow, unsafecol;
    for(int i = 0; i < 8; i ++){
        string s; cin >> s;
        for(int j = 0; j < 8; j ++){
            if(s[j] == '#') unsaferow.insert(i), unsafecol.insert(j);
        }
    }

    cout << (8-sz(unsafecol)) * (8-sz(unsaferow)) << endl;

    return 0;
} 
