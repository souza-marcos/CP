#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define sx(x) (int)x.size()
#define endl "\n"

void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    map<char, int> smap;
    for(auto el: s) smap[el] ++;

    int impar = 0, par = 0;
    for(auto [key, val] : smap){
        if(val % 2) impar ++;
        else par ++;
    }
    // cout << impar << " " << par << endl;

    if(k < impar - 1){
        cout << "NO\n"; return;
    } 
    if(k == impar - 1 or k == impar){
        cout << "YES\n"; return;
    }

    cout << "YES\n";
}

int main(){ _

    int t; cin >> t; 
    while(t --) solve();

    return 0;
} 
