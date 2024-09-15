#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl "\n"

int main(){ _

    int t; cin >> t;
    while(t --){
        int n, m; cin >> n >> m;
        if(n < m) cout << "No\n";
        else{
            cout << ((n%2 == m%2)?"Yes":"No") << endl;
        }
    }

    return 0;
} 
