#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

int josephus(int n, int k){
    if(n == 1) return 1;
    if(k <= n/2) return 2*k;
    
    int m  = n - n/2;
    int down = josephus(m, k - n/2); 

    // Shiftar o circulo
    int st = (n%2 == 0? 1 : m); /// I X I X   -   I X I X I 
    int idx = (st-1 + (down - 1)) % m + 1;
    return 2*idx-1;
}

int main(){ _

    int t; cin >> t;
    while(t --){
        int n, k; cin >> n >> k;
        cout << josephus(n, k) << endl;    
    }

    return 0;
} 
