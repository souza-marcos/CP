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

#define sz(x) (int)x.size()

int main(){ _

    int n; cin >> n;
    vector<tuple<int, int, int>> arr(n);
    for(auto& [id, num, pen] : arr) cin >> id >> num >> pen;

    sort(arr.begin(), arr.end(), [&](auto a, auto b){
        auto [id1, num1, pen1] = a;
        auto [id2, num2, pen2] = b;

        if(num1 > num2) return true;
        if(num1 < num2) return false;

        if(pen1 < pen2) return true;
        if(pen1 > pen2) return false;
        
        if(id1 < id2) return true;
        return false;
    });
    



    int cnt = 1, last = 0;
    auto lastval = arr[0];
    for(auto& [id, num, pen] : arr){
        if(last == 0) {
            cout << cnt << " " << id << " " << num << " " << pen << endl; 
            last = cnt;
            lastval = make_tuple(id, num, pen);
            cnt ++;
        }else{
            auto [idother, nother, penother] = lastval; 
            if (nother == num and penother == pen){
                cout << last << " " << id << " " << num << " " << pen << endl; 
            } else last = cnt, cout << cnt << " " << id << " " << num << " " << pen << endl; 
            lastval = make_tuple(id, num, pen);
            cnt ++;
        }
    }


    return 0;
} 
