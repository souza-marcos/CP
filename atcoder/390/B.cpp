#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int main(){ _

    int n; cin >> n;
    vector<ll> arr(n); for(auto& el: arr) cin >> el;

    if(n == 2){
        if(arr[0] != 0 or (arr[0] == arr[1])) return cout << "Yes\n", 0;
        cout << "No\n";
    } 

    auto test = [&](){
        bool ok = true;
        for(int i = 0; i < n-2; i++){
            if(arr[i + 1] * arr[i + 1] != arr[i + 2] * arr[i]) { ok = false; break;}
        }
        return ok;
    };

    bool ok = test();
    cout << (ok? "Yes\n" : "No\n");

    return 0;
} 
