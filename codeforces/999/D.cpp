#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

void solve(){

    int n, m; cin >> n >> m;
    multiset<int> a, b;
    for(int i = 0; i < n; i ++){
        int el; cin >> el;
        a.insert(el);
    }

    for(int i = 0; i < m; i ++){
        int el; cin >> el;
        b.insert(el);
    }

    while(sz(b) < sz(a)){
        while(sz(b) > 0 and *b.rbegin() == *a.rbegin()){
            a.erase(a.find(*a.rbegin()));
            b.erase(b.find(*b.rbegin()));
        }
        if(sz(b) == sz(a) or sz(b) == 0){
            break;
        }
        auto it = *b.rbegin();
        if(it < *a.rbegin()){
            cout << "No\n";
            return;
        }
        b.erase(b.find(it));
        
        b.insert(it/2);
        b.insert(it/2 + (it&1));
    }
    if(sz(b) > sz(a)) {
        cout << "No\n";
        return;
    }
    
    while(sz(b) > 0 and *b.rbegin() == *a.rbegin()){
        a.erase(a.find(*a.rbegin()));
        b.erase(b.find(*b.rbegin()));
    }
    if(sz(b) > 0 or sz(a) > 0) cout << "No\n";
    else cout << "Yes\n";
}

int main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
