#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl "\n"

int main(){ _
    int t; cin >> t;
    while(t --){
        int n; cin >> n;
        map<int, int> cnt;
        int a;
        while(n--)
            cin >> a, cnt[__builtin_clz(a)]++;
        int maxval = 0;
        for(auto [k, val] : cnt) maxval = max(maxval, val);
        cout << maxval << endl;
    }


    return 0;
} 
