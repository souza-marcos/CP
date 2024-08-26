#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

void solve(){
    int l = 1, r = 1000;
    while(l + 1 < r){
        int m1 = l + (r - l)/3, m2 = l + 2 * (r - l)/3;
        cout <<"? " << m1 << " " << m2 << endl;
        int in; cin >> in;
        if(in == -1) exit(0);
        if(in == (m1 * m2)) l = m2;
        else if(in == (m1  * (m2 + 1))) l = m1, r = m2;
        else r = m1;
    }
    cout << "! " << r << endl;
}

int main(){

    int t; cin >> t;
    while(t --) solve();


    return 0;
} 
