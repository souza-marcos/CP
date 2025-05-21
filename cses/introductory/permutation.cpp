#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

int main(){ _ 
    // 2, 3 => -1
    // 3 1 4 2
    int n; cin >> n;

    if(n == 2 or n == 3) {cout << "NO SOLUTION\n"; return 0;}
    if(n == 4){
        cout << "2 4 1 3 \n";
        return 0;
    }
    for(int i = 0; i < n; i += 2){
        cout << i + 1 << " ";
    }
    for(int i = 1; i < n; i += 2)
        cout << i + 1 << " ";

    cout << endl;
    return 0;
} 
