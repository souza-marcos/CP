#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()


int main(){ _ 

    int n; cin >> n;
    int cnt = 0, d=5;
    
    while(d > 0){
        while(n > 0 and n >= d) cnt += n/d, n%=d; 
        d --;
    }

    cout << cnt << endl;
} 
