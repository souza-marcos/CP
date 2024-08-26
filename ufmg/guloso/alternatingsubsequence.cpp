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

vector<int> arr;

ll sum_max(){
    ll better_prev = arr[0];
    ll sum = 0;
    bool signal = (arr[0] > 0);
    for(int i = 0; i < arr.size(); i++){

        if(better_prev < arr[i]){
            better_prev = arr[i];
        }

        if(i + 1 < arr.size() && signal != (arr[i + 1] > 0)) { 
            sum += better_prev;
            better_prev = -INF;
            signal = !signal;
        }
    }

    sum += better_prev;
    return sum;
}

int main(){ _

    int t, n; cin >> t;
    while(t--){
        cin >> n;
        arr.resize(n);
        for(auto& el: arr) cin >> el;
        
        cout << sum_max() << endl;
    }
    return 0;
} 
