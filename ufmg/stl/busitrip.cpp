#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define dbg(x) cout << #x << " = " << x << endl;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    int k; cin>> k;
    vector<int> mo(12);
    for(auto& m: mo){
        cin >> m;
    }
    sort(mo.begin(), mo.end(), greater<>());
    for(int i=0; i<12; i++)
    {        
        if(k <= 0){
            cout << i << endl;
            return 0;
        }
        k -= mo[i];
    }
    if(k <= 0) cout << 12 << endl;
    else cout << -1 << endl;
    return 0;
} 
