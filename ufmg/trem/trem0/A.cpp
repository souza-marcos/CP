#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl "\n"

void solve(){
    string s; cin >> s;
    int n = s.size();
    for(int i = 0; i < ceil(n/2) + 1; i++){
        if(s[i] != s[0]){
            char aux = s[i];
            s[i] = s[n - 1];
            s[n - 1] = aux;
            break;
        }
    }
    if(s[0] != s[n - 1]) cout << s << endl;
    else cout << -1 << endl;
}

int main(){ _

    int n; cin >> n;
    while(n--) solve();
    return 0;
} 
