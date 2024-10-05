#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> slidingWindowMaximum(const vector<int>& nums, int k) {
    vector<int> result;
    multiset<int> window;  // To maintain the elements of the sliding window

    for (int i = 0; i < nums.size(); ++i) {
        // Insert the current element into the multiset
        window.insert(nums[i]);

        // Once we've added enough elements to form a full window
        if (i >= k - 1) {
            // The maximum element in the current window is the largest element in the multiset
            result.push_back(*window.rbegin());

            // Remove the element that is sliding out of the window
            window.erase(window.find(nums[i - k + 1]));
        }
    }

    return result;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> result = slidingWindowMaximum(nums, k);

    // Print the result
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
