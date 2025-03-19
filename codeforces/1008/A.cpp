#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()


int main(){ _
    int t; cin >> t;
    while(t --){
        int n, x; cin >> n >> x;
        ll sum = 0;
        for(int i = 0; i < n; i ++){
            int a; cin >> a;
            sum +=  x-a;
        }
        if(sum == 0) cout << "YES\n";
        else cout << "NO\n";
    }



    return 0;
} 
