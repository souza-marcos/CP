#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int main(){ _ 

    int n; cin >> n;
    vector<tuple<int, int, int>> arr(n); 
    int i = 0;
    for(auto& [a, b, idx] : arr) 
        cin >> a >> b, idx = i ++;

    vector<bool> contain(n), is_contained(n);

    // If we sort the segments by low start and high end, we can check if this segment is contained by any
    sort(arr.begin(), arr.end(), [](auto& left, auto& right){
        auto [la, lb, lidx] = left;
        auto [ra, rb, ridx] = right;

        if(la == ra) return (lb > rb);
        else return (la < ra);
    });

    int curend = -1;
    for(auto [a, b, idx] : arr){
        if(b <= curend) 
            is_contained[idx] = true;
        curend = max(curend, b);
    }


    sort(arr.begin(), arr.end(), [](auto& left, auto& right){
        auto [la, lb, lidx] = left;
        auto [ra, rb, ridx] = right;

        if(lb == rb) return la > ra;
        else return lb < rb;
    }); 
    
    int curstart = -1;
    for(auto [a, b, idx] : arr){
        if(a <= curstart)
            contain[idx] = true;
        curstart = max(curstart, a);
    }
    
    for(auto el : contain)
        cout << el << " ";
    cout << endl;

    for(auto el : is_contained)
        cout << el << " ";
    cout << endl;
    return 0;       
}
