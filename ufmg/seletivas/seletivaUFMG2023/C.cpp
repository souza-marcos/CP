#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L; 
#define sz(x) (int)x.size()

pair<ll, ll> compute_hash(string const& s){
    auto handler = [](const int p, const int m, const string& s){
        ll hash_val = 0, p_pow = 1;
        for(char c: s){
            hash_val += (c - 'a' + 1) * p_pow, hash_val %= m;
            p_pow = (p_pow * p) % m;
        }
        return hash_val;
    };
    return {handler(5, 1e9 + 7, s), handler(7, 1e9 + 9, s)};
}


set<pair<ll, ll>> sack;
void solve(string& s){
     for(int i = 0; i < sz(s); i ++){
            for(int j = 0; j < 3; j ++){
                if(s[i] - 'a' == j) continue;
                char aux = s[i];
                s[i] = 'a' + j;
                if(sack.count(compute_hash(s))) {
                    cout << "YES\n";
                    return; 
                }
                s[i] = aux;
            }
     }
    cout << "NO\n";
}

int main(){_
    int n, m; cin >> n >> m;
    

    while(n--){
        string s; cin >> s;
        sack.insert(compute_hash(s));
    }

    while(m --){
        string s; cin >> s;
        solve(s); 
    }
}
