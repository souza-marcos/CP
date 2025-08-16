#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

int main(){ _

    int n; cin >> n;
    vector<int> arr(n), fenwick(n); 
    for(int i = 0; i < n; i ++) {
        cin >> arr[i];
        fenwick[i] += 1;
        int next = i | (i + 1);
        if(next < n) fenwick[next] += fenwick[i];   
    }

    auto query = [&](int a) -> int {
        int res = 0;
        for(int i = a; i >= 0; i = (i & (i + 1)) -1){
            res += fenwick[i];
        }
        return res;
    };

    auto add = [&](int a, int delta){ 
        for(int i = a; i < n; i = i | (i + 1)){
            fenwick[i] += delta;
        }
    };

    for(int q = 0; q < n; q ++){
        int k; cin >> k;
        int l = -1, r = n-1;
        while(l + 1 < r){
            int m = (l + r)/2;
            if(query(m) < k) l = m;
            else r = m;
        }
        // cout << r << " " << arr[r] << "\n";
        cout << arr[r] << " ";
        add(r, -1);
    }
    cout << endl;
    return 0;
} 
