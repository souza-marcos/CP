#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

// 1 => -1 -2
// 2 => -2 -1
// x(-1, -2) + y(-2, -1) = (a, b)
// (-x-2y, -2x-y) = (a, b)
// x + 2y = a
// 2x + y = b


// y = b-2x = (a-x)/2
// 2b-4x=a-x => 2b-a = 3x
// x = (2b-a)/3

// y = (2a-b)/3
// x = b-2y

int main(){ _
    int t; cin >> t;
    while(t--){
        int a, b; cin >> a >> b;
        int val1 = 2*b-a;
        int val2 = 2*a-b;
        if(val1 >= 0 and val1 % 3 == 0){
            int x = val1/3;
            int y = b-2*x;
            if(y >= 0){
                cout << "YES\n";
                continue;
            }
        }
        if(val2 >= 0 and val2 % 3 == 0){
            int y = val2/3;
            int x = b-2*y;
            if(x >= 0){
                cout << "YES\n";
                continue;
            }
        }
        cout << "NO\n";
    }

    return 0;
} 
