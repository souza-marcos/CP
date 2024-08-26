#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl "\n"
#define szo(x) ((int)x.size()) 


void solve(){
    int n ; cin >> n;
    string s; cin >> s;
    set<char> pq;
    for(auto c: s) pq.insert(c);
    vector<char> v(pq.size());
    int i = 0;
    for(auto el: pq) v[i ++ ] = el;
    map<char, char> m;
    for(int i = 0; i < szo(v); i++){
        m[v[i]] = v[szo(v)-i-1];
    }
    for(auto c: s) cout << m[c];
    cout << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
