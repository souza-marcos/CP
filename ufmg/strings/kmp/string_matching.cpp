// https://cses.fi/problemset/task/1753/
#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'
int main(){ _
    string s, p; cin >> s >> p;
    string t = p + '$' + s;

    vector<int> pi(sz(t));
    int cnt = 0;
    for(int i = 1, j = 0; i < sz(t); i ++){
        while(j > 0 and t[j] != t[i]) j = pi[j-1];
        if(t[i] == t[j]) j ++;
        pi[i] = j;

        if(j == sz(p)) cnt ++;
    }

    cout << cnt << endl;
    return 0;
} 
