#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

typedef long long ll;
const int INF = 0x3f3f3f3f; // -2e9 ... 2e9 
const ll LINF = 0x3f3f3f3f3f3f3f3fll; // -9e18 ... 9e18


int main(){ _

    int x, y; cin >> x >> y;
    int res = y - x;
    cout << ((res < 0 and abs(res) <= 3) or (res > 0 and abs(res) <= 2) ? "Yes":"No") << endl;

    return 0;
} 
