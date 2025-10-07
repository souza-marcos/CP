#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()
#define int ll

int32_t main(){ _

    int n; cin >> n;
    vector<int> a(n); for(int& el : a) cin >> el;
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    do{ 
        bool ok = true;
        for(int i = 0; i < n; i ++){
            if(a[i] > 0 and p[i] != a[i]){
                ok = false;
                break;
            } 
        }
        if(ok)
        {
            cout << "Yes\n";
            for(auto el : p) cout << el << " ";
            cout << endl;
            return 0;
        }

    }while(next_permutation(p.begin(), p.end()));
    cout << "No\n";
    return 0;
} 
