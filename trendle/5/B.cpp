#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()


int main(){ _ 
    int n; cin >> n;
    vector<int> row(n), col(n);
    for(int i = 0; i < n; i ++){
        string s; cin >> s;
        for(int j = 0; j < n; j ++){
            col[j] += s[j] == 'C';
            row[i] += s[j] == 'C';
        }
    }

    int res = 0;
    for(auto el : row) res += el*(el-1)/2;
    for(auto el : col) res += el*(el-1)/2;
    cout << res << endl;
} 
