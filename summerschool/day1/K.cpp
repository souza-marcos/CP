#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int main(){ _
    int n; cin >> n;
    vector<int> arr(n); for(auto& el : arr) cin >> el;
    string s; cin >> s;
    
    set<int> st;
    for(int i = 0; i < n; i ++){
        st.insert(arr[i]);
        if(s[i] == '0'){
            for(int j = i; j > i-sz(st); j--) {
                if(st.count(j+1) == 0) {
                    cout << "NO\n";
                    return 0;
                }
            }
            st.clear();
        }
    }
    cout << "YES\n";
} 
