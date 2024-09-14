#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

int main(){ _

    int n; cin >> n; n <<= 1;
    vector<int> v(n); for(int& el: v) cin >> el;
    
    int cnt= 0;
    for (int i = 1; i < n-1; i++)
    {
        if(v[i-1] == v[i + 1]) cnt ++;
    }
    cout << cnt << endl;

    return 0;
} 
