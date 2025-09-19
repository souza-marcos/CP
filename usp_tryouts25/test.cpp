#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define ff first
#define ss second
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define int ll
#define sz(x) (int)x.size()

int32_t main() { _
    srand(time(0));

    int n = 100'000;
    int acerta1 = 0;
    for(int i = 0; i < n; i ++){
        int choose = rand() % 3;
        int right = rand() % 3;

        // Nunca troca
        acerta1 +=  choose == right;
    }

    int acerta2 = 0;
    for(int i = 0; i < n; i ++){
        int choose = rand() % 3;
        int right = rand() % 3;

        // Sempre troca
        acerta2 += choose != right;
    }
    
    cout << acerta1  << " " << acerta2 << endl;
}