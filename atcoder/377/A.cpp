#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'


int main(){ _
    string s; cin >> s;
    int cntA = 0, cntB = 0, cntC = 0;
    for(auto c: s)
    {
        if(c == 'A') cntA ++;
        if(c == 'B') cntB ++;
        if(c == 'C') cntC ++;
        
    }    
    if(cntA and cntB and cntC)cout << "Yes\n";
    else cout << "No\n";
    return 0;
} 
