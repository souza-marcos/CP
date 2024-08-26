#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n1, n2, k1, k2;
ll mod = 1e8;
 
ll memu[110][110][2];
 
ll dp(int q1, int q2, bool c){
    if(q1<0 or q2 < 0) return 0;
    if(q1 == 0 and q2==0) return 1;
    if(memu[q1][q2][c] != -1) return memu[q1][q2][c];
 
    ll ans = 0;
    for(int i =1; i <= (!c ? min(q1, k1) : min(q2, k2)); i++) 
        ans = (ans + dp(!c ? q1-i : q1, c ? q2-i : q2 ,!c)) % mod;
 
    return memu[q1][q2][c] = ans;
}
 
int main(){_
    cin >> n1 >> n2 >> k1 >> k2;
    memset(memu, -1, sizeof memu);
    cout << (dp(n1,n2,0) + dp(n1,n2,1))  % mod << endl;
}