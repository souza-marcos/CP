#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

void solve(){
    int n; cin >> n;
    vector<int> x(n-1); for(int& el: x) cin>> el;
    x.push_back(0);

    int last = x[0] + 1;
    cout << last << " ";
    for(int i = 0; i < n-1; i++){
        int a = x[i] % last;
        if(a == x[i + 1]) a+= last;
        if(a < x[i + 1]){
            int times = ceil((x[i+1] - a + 1)/(double)last) + 1;
            a += times * last;
        }
        last = a;
        cout << last << " ";
    }
    cout << endl;

}

int main(){ _

    int t; cin >> t;
    while(t --) solve();

    return 0;
} 
