#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'
// #define int ll

int32_t main(){ _

    // Divide the array into blocks.
    // For each element we mantain the next hole that is outside of the own block
    // And the number of steps to get there.
    // The query I will be in each block I point until get outside the array.
    // The update: If the point is outside the block, just update.
    //      When it is inside, get the point the position I get.

    int n, q; cin >> n >> q;
    vector<int> arr(n);
    for(int& el : arr) cin >> el;
    vector<int> next_pos(n), step_next(n); 
    
    int b = sqrt(n) + 1;
    for(int i = n-1; i >= 0; i --){
        int cur_block = i/b;
        int jump_to = i + arr[i];
        if (jump_to >= n) {
            next_pos[i] = n;
            step_next[i] = 1;
        } else if (jump_to / b == cur_block) {
            next_pos[i] = next_pos[jump_to];
            step_next[i] = 1 + step_next[jump_to];
        } else {
            next_pos[i] = jump_to;
            step_next[i] = 1;
        }
    }

    while(q --){
        int t; cin >> t;
        if(t == 0){
            int pos, val; cin >> pos >> val;
            pos --;

            arr[pos] = val;
            for(int i = pos; i >= 0 and i/b == pos/b ; i --){
                int cur_block = i/b;
                int jump_to = i + arr[i];
                if (jump_to >= n) {
                    next_pos[i] = n;
                    step_next[i] = 1;
                } else if (jump_to / b == cur_block) {
                    next_pos[i] = next_pos[jump_to];
                    step_next[i] = 1 + step_next[jump_to];
                } else {
                    next_pos[i] = jump_to;
                    step_next[i] = 1;
                }

            }
        }
        else{
            int pos; cin >> pos; pos --;

            int cnt = 0;
            while(next_pos[pos] < n){
                cnt += step_next[pos];
                pos = next_pos[pos];
            }
            cnt += step_next[pos];
            while(arr[pos] + pos < n){
                pos += arr[pos];
            }
            cout << pos + 1 << " " << cnt  << endl;
        }
    }

    return 0;
} 