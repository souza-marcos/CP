#include <bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 
// typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> set_t;


#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

void solve(){
    int a[2], b[2]; cin >> a[0] >> a[1] >> b[0] >> b[1]; 

    int cnt = 0;
    for(int i = 0; i < 2; i ++){
        for(int j = 0; j < 2; j++){
            if(a[i] > b[j]){
                if(a[(i+1)%2] >= b[(j+1)%2]) cnt ++;
            }
            else if(a[i] == b[j]){
                if(a[(i+1)%2] > b[(j+1)%2]) cnt ++;
            }
        }
    }
    cout << cnt << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();

    return 0;
} 
