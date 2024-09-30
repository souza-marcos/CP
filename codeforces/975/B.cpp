#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double PI = acos(-1);
#define endl '\n'
#define sz(x) (int)x.size()

int main(){ _


    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int max_score = 0;

        // Traverse the array and compute the score
        for (int i = 0; i < n; i++) {
            int max_value = arr[i];
            int num_red = 1;  // Start by making arr[i] red

            // Traverse the rest of the array skipping adjacent elements
            for (int j = i + 2; j < n; j += 2) {
                num_red++;
                max_value = max(max_value, arr[j]);
            }

            // Calculate score as max value of selected red elements + count of red elements
            max_score = max(max_score, max_value + num_red);
        }

        cout << max_score << '\n';
    }

    return 0;
} 
