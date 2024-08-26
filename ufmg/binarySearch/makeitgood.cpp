#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define dbg(x) cout << #x << " = " << x << endl;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


bool possible(vector<int> arr, int val){
    int begin = val, end = arr.size() -1;
    int last = min(arr[begin], arr[end]);
    while(begin <= end){
        if(arr[begin] <= arr[end]){
            if(arr[begin] < last) return false;
            last = arr[begin];
            begin++;
        }else{
            if(arr[end] < last) return false;
            last = arr[end];
            end--;
        }
        //cout << "val:" << val <<", last :" << last << ", begin:" << begin << ", end:" << end << endl;
    }
    //cout << endl;
    return true;
}

int main(){ _
    int t; cin >> t;
    while (t--)
    {
        int n, el = 0; cin >>n;
        vector<int> arr;
        for(int i = 0; i<n; i++) {
            cin >> el;
            arr.push_back(el);
        }
        
        int l = 0, r = n;
        int m = 0;
        while(l < r){
            m = (l + r)/2;
            if(!possible(arr, m)) {
                l = m+1;
            }
            else r = m;
        }
        cout << l << endl;
    }
    

    return 0;
} 
