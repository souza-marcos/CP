#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

int main(){ _
    // Solve draw cases

    int t; cin >> t;
    while(t--) {
        int n, a, b; cin >> n >> a >> b;

        if(a + b > n){
            cout << "NO\n";
            continue;
        }
        vector<int> res1(n), res2(n);
        if(a + b < n){
            int diff = n - a - b;
            for(int i = 1; i <= diff; i ++){
                res1[n-1]=res2[n-1]=n;
                n--;
            }
        }
        
        if(n == a or n == b){
            cout << "NO\n";
            continue;
        }
    }
    return 0;
} 
