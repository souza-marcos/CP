#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

int main(){  _
    int n, q; cin >> n >> q;
    vector<int> arr(n); 
    for(int& el : arr) cin >> el;    
    arr.push_back(INF);

    // monotonic stack to precalculate ups 
    int MAX = log2(n) + 1;
    int up[n+1][MAX];
    
    vector<int> st;
    for(int i = 0; i < n; i ++){
        while(sz(st) > 0 and arr[st.back()] < arr[i]){
            up[st.back()][0] = i; 
            st.pop_back();
        }
        st.push_back(i);
    }
    while(sz(st))
        up[st.back()][0] = n,
        st.pop_back();


    for(int h = 0; h < MAX; h ++)
        up[n][h] = n;

    // sparse table - binary lifting
    for(int h = 1; h < MAX; h ++){
        for(int i = 0; i < n; i ++){
            up[i][h] = up[up[i][h-1]][h-1];
        }
    }

    // for(int i = 0; i < n; i ++){
    //     for(int j = 0; j < MAX; j ++){
    //         cout << up[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    while(q--){
        int l, r; cin >> l >> r; l--, r--;
        int cnt = 0;
        for(int h = MAX - 1; h >= 0; h --){
            if(up[l][h] < r) cnt += (1<<h), l = up[l][h];
        }
        if(l < r and up[l][0] <= r) cnt ++;

        cout << cnt + 1 << endl;
    }

    return 0;
} 
