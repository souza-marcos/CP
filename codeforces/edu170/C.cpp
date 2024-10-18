#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    int n, k; cin >> n >> k;
    vector<int> arr(n); for(auto&el: arr) cin>>el;

    sort(arr.begin(), arr.end());
    vector<pair<int, int>> aux;
    int last = arr[0], cnt = 0;
    for(int i = 0; i < n; i ++){
        if(arr[i] == last) cnt++;
        else {
            aux.push_back({last, cnt});
            cnt = 1;
            last = arr[i];
        }
    }
    aux.push_back({last, cnt});


    // Sliding Window size k;
    int maxv = 0, sum = 0;
    cnt = 0;
    for(int i = 0; i < sz(aux); i ++){

        if(i > 0 and aux[i].first > aux[i-1].first + 1)
            sum = 0, cnt = 0;

        sum += aux[i].second; cnt ++;
        if(cnt > k){
            sum -= aux[i-k].second;
            cnt --;
        }
        maxv = max(maxv, sum);
    }

    cout << maxv << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
