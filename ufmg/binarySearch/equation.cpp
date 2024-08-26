#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define dbg(x) cout << #x << " = " << x << endl;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _

    double c; cin >> c;
    cout << setprecision(20);
    double l = 0.0, r = c;
    for(int i = 0; i<100; i++){
        double m = (l + r) / 2.0;
        if((m * m + sqrt(m)) >= c) r = m;
        else l = m;
    }
    cout << (l + r)/ 2.0 << endl;

    return 0;
} 
