// https://codeforces.com/gym/348180/problem/C
#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


int main(){ _

    int t; cin >> t;
    while(t --) {
        int n, k; cin >> n >> k;
        k--;
        int m = 0;
        if(n&1) m = (n-1)/2, k += k/m;
        cout << (k % n) + 1 << endl;
    }

    return 0;
} 
