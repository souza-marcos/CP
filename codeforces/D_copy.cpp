#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L; 
#define sz(x) (int)x.size()

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

void solve(){
    int n; cin >> n;
    vector<int> v(n); for(int& el: v) cin >> el;

    if (n == 3) {
        int cur = gcd(v[0], v[1]);
        cur = gcd(cur, v[2]);
        if (cur == gcd(v[0], v[2])) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        return;
    }

    vector<int> a(n, -1), b(n, -1), c(n, -1);
    for(int i = 0; i < n-1; i++){
        int cur = gcd(v[i], v[i+1]);
        a[i] = cur;
    }

    bool possible = false;

    for (int i = 0; i < n; i++) {
        vector<int> temp;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            temp.push_back(v[j]);
        }

        vector<int> tempGCD;
        for (int j = 0; j < n-2; j++) {
            tempGCD.push_back(gcd(temp[j], temp[j+1]));
        }

        bool non_decreasing = true;
        for (int j = 1; j < tempGCD.size(); j++) {
            if (tempGCD[j-1] > tempGCD[j]) {
                non_decreasing = false;
                break;
            }
        }

        if (non_decreasing) {
            possible = true;
            break;
        }
    }

    if (possible) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main(){_
    int t; cin >> t;
    while(t --) solve();
}
