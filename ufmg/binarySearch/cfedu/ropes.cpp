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

#define sz(x) (int) x.size()

int n, k;
vector<int> v;

bool valid(double size){
    int cnt = 0;
    for(auto el : v){
        cnt += (int)(el/size);
        if(cnt >= k) return true;
    }
    return false;
}

int main(){ _
    cout << fixed << setprecision(10);
    cin >> n >> k;
    v.assign(n, 0);
    for(auto& el: v) cin >> el;

    double l = 0, r = 1e7 + 10, eps = 1e-8; 
    while(r - l > eps){

        double m = (l + r)/2.0;
        if(valid(m)) l = m;
        else r = m;
    }

    cout << (l + r)/2.0 << endl;

    return 0;
} 
