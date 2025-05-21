#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int main(){ _

    int n; cin >> n;
    int tot = (n/2 + n%2) + (n/2 + n%2);
    int sobra = (n%2) + (n/2 + (n%2?2:0));
    int val = max(0, n-sobra);
    tot += val/3 + (val%3 > 0);
    cout << tot << endl;
    return 0;
} 
