#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int main(){ _

    int n; cin >> n;
    vector<int> arr(n), zeros;
    int i = 0;
    for(auto &el : arr) {
        cin >> el;
        if(el == 0) zeros.push_back(i);
        i ++;
    }

    int j = 0;
    for(int i = 0; i < n;i ++){
        if(j+1 < sz(zeros) and zeros[j+1] < i) j ++;
        cout << min(abs(i - zeros[j]), abs((j + 1 < sz(zeros)? zeros[j + 1] : INF) - i)) << " ";
    }
    cout << endl;
} 
