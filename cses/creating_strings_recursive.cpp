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

vector<string> ans;
int char_cnt[26];
string s;

void search(const string& cur = ""){
    if(sz(cur) == sz(s)) return ans.push_back(cur);

    for(int i = 0; i < 26; i ++){
        if(char_cnt[i] == 0) continue;
        char_cnt[i] --;
        search(cur + (char)('a' + i));   
        char_cnt[i] ++;
    }
}

int main(){ _
    cin >> s;
    for(auto c: s) char_cnt[c - 'a'] ++;
    search();

    cout << sz(ans) << endl;
    for(auto el: ans) cout << el << endl;

    return 0;
} 
