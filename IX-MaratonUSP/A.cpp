#include <bits/stdc++.h>
using namespace std;


#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

int main(){ _
    int n; cin >> n;
    vector<int> v(n);
    
    for(auto&el : v) cin >> el;
    // v.push_back(0);

    sort(v.begin(), v.end());

    int minval = v[n -1] - v[0] + 1;
    for(int i = 1; i < n; i++){
        int diff = v[n -1] - v[i] + 1;    
        diff += 360 - v[n-1] + v[i-1];
        minval = min(minval, diff);
    }    
    cout << minval << endl;

    return 0;
} 
