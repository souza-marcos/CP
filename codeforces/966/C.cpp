#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

void solve(){
    int n; cin >> n;
    map<int, vector<int>> dict;
    vector<int> a(n); 

    for(int i = 0; i < n; i++){
        int el; cin >> el;
        a[i] = el;
        dict[el].push_back(i);
    }

    int m; cin >> m;

    while(m --){

        string s; cin >> s;
        if(sz(s) != n){
            cout << "NO\n";
            continue;
        }
        bool ok = true;
        for(auto [key, v]: dict){
            int f = s[v[0]];
            for(auto el : v){
                if(s[el] != f){
                    ok = false;
                    break;
                }
            }
            if(!ok) break;
        }
        if(!ok){
            cout << "NO\n";
            continue;
        }

        map<char,vector<int>> invlist;
        for(int i = 0; i < sz(s); i ++){
            invlist[s[i]].push_back(i);
        }

        for(auto [key, v]: invlist){
            int f = a[v[0]];
            for(auto el : v){
                if(a[el] != f){
                    ok = false;
                    break;
                }
            }
            if(!ok) break;
        }
        if(!ok){
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
    }

}

int main(){ _

    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
