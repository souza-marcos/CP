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

int n, k; 
vector<int> arr;

bool valid(double x){
    int sum = 0;
    for(auto el: arr) {
        sum += floor(el/x);
    }
    if(sum >= k) return true;
    return false;
}

int main(){ _
    cin >> n >> k;
    arr.resize(n);
    for(auto& el: arr) cin >> el;
    double l = 0, r = 1e8;  
    for(int i = 0; i< 100; i ++){
        double m = (l+r)/2.0;
        if(valid(m)) l = m;
        else r = m;
    }
    std::cout << setprecision(20) << l << endl;
    return 0;
} 
