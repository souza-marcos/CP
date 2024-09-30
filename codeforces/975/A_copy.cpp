#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;

int main(){ _
    int t; cin >> t;
    while(t--) {
        int n; 
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) cin >> arr[i];

        // Initialize the maximum and minimum values and count of red elements
        int maxVal = 0, minVal = 1e9, count = 0;

        // Traverse the array and pick elements alternately to maximize the score
        for(int i = 0; i < n; i += 2) {
            count++;
            maxVal = max(maxVal, arr[i]);
            minVal = min(minVal, arr[i]);
        }

        // Try starting from the second element as well
        int maxValAlt = 0, minValAlt = 1e9, countAlt = 0;
        for(int i = 1; i < n; i += 2) {
            countAlt++;
            maxValAlt = max(maxValAlt, arr[i]);
            minValAlt = min(minValAlt, arr[i]);
        }

        // Calculate the scores for both options
        int score1 = maxVal + minVal + count;
        int score2 = maxValAlt + minValAlt + countAlt;

        // The maximum score is the answer
        cout << max(score1, score2) << endl;
    }

    return 0;
}
