#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()


int main(){ _ 
    
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int last = -1;

    for(int i = 0; i < n ; i++){
        if(s[i] == '#') continue;
        int step = i - last;
        if(step > k) {
            cout << "NO\n";
            exit(0);
        }
        last = i;
    }
    if(n - last > k) cout << "NO\n";
    else cout << "YES\n";

} 
