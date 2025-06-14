#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

const int MAX = 2e5 + 3;

namespace seg{
    int seg[4*MAX];
    
    int query(int p, int l, int r, int lq, int rq){
        if(l > rq or r < lq) return 0;
        if(lq <= l and r <= rq) return seg[p];
        int m = (l + r)>>1;
        return max(query(p << 1, l, m, lq, rq), query(p << 1 | 1, m+1, r, lq, rq));
    }

    int update(int p, int l, int r, int i, int x){
        if(i < l or i > r) return seg[p];
        if(l == r) return seg[p] = x;
        int m = (l + r) >> 1;
        return seg[p] = max(update(p << 1, l, m, i, x), update(p << 1 | 1, m + 1, r, i, x));
    }

    int print(int p, int l, int r){
        if(l == r) return cout << seg[p] << " ", 0;
        int m = (l + r) >> 1;
        print(p << 1, l, m), print(p << 1 | 1, m + 1, r);  
        return 0;
    }
};

int32_t main(){ _ 
    
    int n; cin >> n;
    vector<pair<int, int>> height(n);
{
    int i = 0; 
    for(auto& [el, idx] : height) cin >> el, idx = i ++;
}

    vector<int> right(n), left(n);
    vector<pair<int, int>> st; // height - idx
    st.push_back({INF, n});
    for(int i = n-1; i >= 0; i --){
        while(st.back().first < height[i].first) 
            st.pop_back();
        right[i] = st.back().second;
        st.push_back({height[i].first, i});
    }
    st.clear(); st.push_back({INF, -1});

    for(int i = 0; i < n; i ++){
        while(st.back().first < height[i].first) 
            st.pop_back();
        left[i] = st.back().second;
        st.push_back({height[i].first, i});
    }


    sort(height.begin(), height.end());
    for(auto [el, idx] : height){
        int r = right[idx] - 1;
        int l = left[idx] + 1;
        
        int val = seg::query(1, 0, n-1, l, r);
        seg::update(1, 0, n-1, idx, val + 1);
        // cout << idx << " " << l << " " << r << " " << val << " => ";
        // seg::print(1, 0, n-1); cout << endl;
    }
    cout << seg::query(1, 0, n-1, 0, n-1) << endl;    

}
