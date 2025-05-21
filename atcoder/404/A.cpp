#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

bool in[26];    
int main(){ _
    string s; cin >> s;
    for(auto c : s) in[c-'a']=1;
    for(int i = 0; i < 26; i ++)
        if(!in[i]) {
            cout << (char)('a' + i) << endl;
            return 0;
        }
    return 0;
} 
