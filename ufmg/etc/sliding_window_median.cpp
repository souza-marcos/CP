#include <iostream>
#include <queue>
#include <vector>
#include <functional> // For std::greater

using namespace std;

class SlidingWindowMedian {
private:
    priority_queue<int> maxHeap; // left side (max heap)
    priority_queue<int, vector<int>, greater<int>> minHeap; // right side (min heap)

public:
    // Helper function to balance the heaps
    void balanceHeaps() {
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    // Insert a number into the correct heap
    void insert(int num) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }
        balanceHeaps();
    }

    // Remove a number from one of the heaps
    void remove(int num) {
        if (num <= maxHeap.top()) {
            // Remove from maxHeap
            maxHeap.pop();  // Lazy removal by rebalancing
        } else {
            // Remove from minHeap
            minHeap.pop();  // Lazy removal by rebalancing
        }
        balanceHeaps();
    }

    // Get the current median
    int getMedian() {
        return maxHeap.top(); // The median is always at the top of the maxHeap
    }
};

vector<int> slidingWindowMedian(const vector<int>& nums, int k) {
    SlidingWindowMedian windowMedian;
    vector<int> result;

    for (int i = 0; i < nums.size(); ++i) {
        windowMedian.insert(nums[i]);

        if (i >= k - 1) {
            result.push_back(windowMedian.getMedian());

            // Remove the element that slides out of the window
            windowMedian.remove(nums[i - k + 1]);
        }
    }

    return result;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<int> result = slidingWindowMedian(nums, k);

    for (int median : result) {
        cout << median << " ";
    }
    cout << endl;

    return 0;
}
