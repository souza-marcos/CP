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

int main(){ _
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &el : v) cin >> el;

    map<int, int> cnt_el;
    int comp = 0, maxval = 0;
    int j = 0;

    pair<int, int> res;

    for (int i = 0; i < n; i++) {
        cnt_el[v[i]]++;
        if (cnt_el[v[i]] == 1) {
            comp++;
        }

        while (comp > k) {
            cnt_el[v[j]]--;
            if (cnt_el[v[j]] == 0) {
                comp--;
            }
            j++;
        }

        if (i - j + 1 > maxval) {
            maxval = i - j + 1;
            res = {j, i};
        }
    }

    cout << maxval << endl;
    cout << res.first + 1 << " " << res.second + 1 << endl;
    return 0;
} 
