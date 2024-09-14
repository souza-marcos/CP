#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

// guess how many attacks are nedded

bool valid(int init_dan, ll times, ll life){
    ll fim_dan = init_dan + times;
    ll tot= 0;
    while(init_dan%3 and init_dan < fim_dan) tot ++, init_dan++;
    if(init_dan < fim_dan) tot += 3, init_dan ++;
    tot += (fim_dan - init_dan) + 2 * ((fim_dan - init_dan)/3);
    return (tot >= life);
}

int main(){ _
    int n; cin >> n;
    vector<int> h(n); for(int& el: h) cin >> el;

    ll cnt = 1;
    for(int i = 0; i < n; i ++){
        int l = 0, r = 1e9;
        while(l + 1 < r){
            int m = (l + r)/2;
            if(valid(cnt, m, h[i])) r = m;
            else l = m;
        }

        cnt += r;
    }
    cout << cnt-1 << endl;
    return 0;
} 
