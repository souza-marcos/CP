#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int32_t main(){

    int n, k, q; cin >> n >> k >> q;
    vector<int> arr(2e5 + 10);
    for(int i = 0 ; i < n; i ++){
        int a, b; cin >> a >> b;
        arr[a] += 1;
        arr[b+1] -= 1;
    }

    vector<int> nindica(2e5+10);
    nindica[0] = arr[0];
    for(int i = 1; i < 2e5+10; i ++){
        nindica[i] = nindica[i-1]+arr[i];
        nindica[i-1] = (nindica[i-1] >= k);
    }

    for(int i = 1; i < 2e5+10; i ++){
        nindica[i] += nindica[i-1];
    }

    while(q--){
        int a, b; cin >> a >> b;
        cout << nindica[b] - nindica[a-1] << endl;
    }
}

