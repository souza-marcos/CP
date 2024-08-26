#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


bool is_bigger(int a, int b){ // a.b or b.a
    string as = to_string(a);
    string bs = to_string(b);
    return as + bs > bs + as;
}

class Solution {
public:

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), is_bigger);
        string res;
        if(nums[0] == 0) return "0";
        for(int el: nums) res.append(to_string(el));
        return res;
    }
};

int main(){ _
    int n; cin >> n;
    vector<int> vals(n);
    for(auto& el: vals) cin >> el;
    Solution s; 
    cout << s.largestNumber(vals);
    return 0;
} 
