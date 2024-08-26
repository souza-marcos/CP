#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 998'244'353;

#define endl '\n'

void solve(){
    string s; cin >> s;
    int n = s.size();
    // Number of operations => Erase elements

    bool cur = (s[0] == '1');
    ll subtotal = 1;
    int cont = 1, blocks = 1; 
    for(int i = 1; i < n; i++){
        if((cur && s[i] == '1') || (!cur && s[i] == '0')) {
            cont ++;
            if(i + 1 == n) subtotal = (subtotal * cont) % MOD;
        }
        else{
            cur = !cur;
            blocks ++;
            subtotal = (subtotal * cont) % MOD;
            cont = 1;
        }
    }

    int op = n - blocks;
    for(int i = n - blocks; i >= 1; i--){
        subtotal = (subtotal * i) % MOD;
    }

    cout << op << " " << subtotal << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();

    return 0;
} 
