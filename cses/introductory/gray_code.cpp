#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

int main(){ _
    int n; cin >> n;
    vector<string> res = {"0", "1"};
    int size = 2;
    for(int i = 1; i < n; i++){
        for(int j = size-1; j>=0; j--){
            res.push_back(res[j]);
            res.back().push_back('1');
        }
        for(int j = 0; j < size; j ++){
            res[j].push_back('0');
        }
        size <<= 1;
    }

    for(auto el : res)
        cout << el << endl;

    return 0;
} 
