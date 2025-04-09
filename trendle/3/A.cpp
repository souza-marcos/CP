#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()


int main(){ _ 
    int n; cin >> n;
    bool ok = false;
    for(int i = 0; i < n; i ++){
        int a; cin >> a;
        if(a) ok = true;
    }
    if(ok) cout << "HARD\n";
    else cout << "EASY\n";
} 
