#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = acos(-1);
#define sz(x) (int)x.size()

const int MAX = 3001;
ll memo[MAX][MAX];

int main(){ _
    int n; cin >> n;
    vector<ll> arr(n); for(auto& el: arr) cin >> el;

    for(int i = 0; i < n; i ++) memo[i][i] = arr[i];

    for(int s = 2; s <= n; s ++){
        for(int i = 0, j = i+s-1; j < n; i ++, j ++){
            memo[i][j] = max(arr[i] - memo[i+1][j], arr[j] - memo[i][j-1]);
        }
    }
    cout << memo[0][n-1] << endl;
    // for(int i = 0; i <= n; i ++){
    //     for(int j = 0; j <= n; j ++) cout << memo[i][j] << " ";
    //     cout << endl;
    // }
    return 0;
} 
