#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define dbg(x) cout << #x << " = " << x << endl;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

pair<int, int> convertP(pair<int, int> i, char move){
    if(move == 'N') return {i.f, i.s+1};
    if(move == 'S') return {i.f, i.s-1};
    if(move == 'W') return {i.f-1, i.s};
    return {i.f+1, i.s};
}

void solve(){
    string temp;
    set<pair<pair<int, int>, pair<int, int>>> comp;
    pair<int, int> cur = {0,0}, next;
    cin >> temp;
    int cost = 0;
    for(auto c: temp){
        next = convertP(cur, c);
        cost += 5 - 4 * comp.count({cur, next});
        comp.insert({cur, next});
        comp.insert({next, cur});
        
        cur = next;
    }
    cout << cost << endl;
}

int main(){ _
    int t; cin >> t;
    while(t-- > 0) solve();
    return 0;
} 
