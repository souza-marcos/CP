#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()
#define int ll

int32_t main(){ _
    vector<int> cnt(26, 0);
    string s; cin >> s;
    for(auto ch : s) cnt[ch-'a'] ++;
    for(int i = 0; i < 26; i ++){
        if(cnt[i]==1){
            cout << (char)('a' + i) << endl;
            return 0;
        }
    }
    return 0;
} 
