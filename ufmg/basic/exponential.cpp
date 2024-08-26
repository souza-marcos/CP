#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl "\n"

int main(){ _
    int a, b, c; cin >> a >> b >> c;
    int res = 1;
    for(int i = 0; i < b; i ++){
        res *= a; res %= c;
    }
    cout << res << endl;

    return 0;
} 
