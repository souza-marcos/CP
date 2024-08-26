#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl '\n'

void solve(){
    int n; cin >> n;
    char temp;

    int maxcont = 0, cont = 0, total = 0;
    while(n --){
        cin >> temp;
        if(temp == '.') cont ++;
        if(temp == '#') {
            maxcont = max(maxcont, cont);
            total += cont;
            cont = 0;
        }
    }
    maxcont = max(maxcont, cont);
    total += cont;
    
    if(maxcont >= 3) cout << 2 << endl;
    else cout << total << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();

    return 0;
} 
