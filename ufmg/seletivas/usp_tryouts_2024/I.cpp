#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    int n; cin >> n;
    vector<int> v(n);
    int val;

    bool nonzero = false;
    int res = 0;
    for(int i = 0; i < n; i ++){
        cin >> val;
        if(val != 0) nonzero = true;
        if(val & 1) v[i] = val - 1, res = 1;
        else v[i] = val;
    }
    if(!nonzero){
        cout << 0 << endl;
        return 0;
    }

    for(auto el: v){
        if(el > 0) {
            res++;
            break;
        }
    }
    cout << res << endl;
    return 0;
} 
