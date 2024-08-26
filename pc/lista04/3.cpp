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

const int lim = 2e6 ;
vector<bool> primo(lim, 1);

void crivo(){
    // primo[0] = primo[1] = false;
    for(int i = 2; i * i < lim; i++){
        if(primo[i]){
            for(int j = i * i; j < lim; j += i)
                primo[j] = false;
        }
    }
}

void solve(){
    int n; cin >> n;
    set<int> els;
    while (n--){
        int a;
        cin >> a; els.insert(a); 
    }
    for(int i = 1; i < lim; i++){
        if(primo[i] and !els.count(i)){
            cout << i-1 << endl; return;
        }
    }

}

int main(){ _
    crivo();
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
