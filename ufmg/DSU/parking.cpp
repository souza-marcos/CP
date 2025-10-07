#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()


int main(){ _
    int n; cin >> n;
    vector<int> arr(n);
    iota(arr.begin(), arr.end(), 0);

    function<int(int)> find = [&](int a) -> int{
        return arr[a] = (arr[a] == a ? a : find(arr[a]));
    };

    // Chuto que fica O(n) amortizado sem union by size/rank, soh com path compression
    auto uni = [&](int a, int b) -> void {
        a = find(a), b = find(b);
        arr[a] = b;
    };

    for(int i = 0; i < n; i ++){
        int a; cin >> a;
        a --;
        int pos = find(a);
        cout << pos + 1 << " ";
        uni(pos, (pos + 1) % n);
    }
    cout << endl;

    return 0;
} 
