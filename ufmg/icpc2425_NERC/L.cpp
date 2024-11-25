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
    if(n <= 3) cout << n + 1 << endl;
    else{

        // Grupos 21 + 21 + 18
        int ans = n/2;
        int rest = (n - n/2) + n%2; 

        // Grupos 18 18 18(21)
        int g = rest/3;
        rest = rest % 3;

        if(rest >= 2) g ++, rest = 0;
        // Grupos 25 25(18/21)
        int v = n/2 + (rest | n%2);
        cout << v + g + ans << endl;

    }

    return 0;
} 
