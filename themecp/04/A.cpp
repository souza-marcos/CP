#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    string s; cin >> s;
    vector<int> up, down;
    vector<int> removed;
    for(int i = 0; i < sz(s); i ++){
        if (s[i] == 'B') {
            if(sz(up)) removed.push_back(up.back()), up.pop_back();
            removed.push_back(i);
            continue;
        }
        if (s[i] == 'b') {
            if(sz(down)) removed.push_back(down.back()), down.pop_back();
            removed.push_back(i);
            continue;
        }

        if(s[i] >= 'a' and s[i] <='z') down.push_back(i);
        else up.push_back(i);
    }

    sort(removed.begin(), removed.end());
    if(sz(removed) == 0) { cout << s << endl; return; }
    int j = 0;
    for(int i = 0; i < sz(s); i ++){
        if(j > sz(removed)-1 or removed[j] != i) cout << s[i];
        if(removed[j] == i and j < sz(s)-1) j ++;
    }

    cout << endl;
}   


int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
