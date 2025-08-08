
#include <iostream>
#include <vector>
using namespace std;

/*

Index :  0   1   2   3   4   5   6   7  8
Range :[0-4][0-2][3-4][0-1][2-2][3-3][4-4][0-0][1-1]
Value : 15   6   9   3   3   4   5   1   2

jb last me left or right ek ho jaega to uska value to wahi rhega, fir uske upar ka jo bhi segment tree hoga
| `segmentTree` Index | Range in `nums` | Value Stored | Explanation 2*i+1, 2*i+2       |
| ------------------- | --------------- | ------------ | ------------------------------ |
| 0                   | \[0, 4]         | 15           | Sum of \[0,2] + \[3,4] → 6 + 9 |
| 1                   | \[0, 2]         | 6            | Sum of \[0,1] + \[2,2] → 3 + 3 |
| 2                   | \[3, 4]         | 9            | Sum of \[3,3] + \[4,4] → 4 + 5 |
| 3                   | \[0, 1]         | 3            | Sum of \[0,0] + \[1,1] → 1 + 2 |
| 4                   | \[2, 2]         | 3            | Leaf → nums\[2] = 3            |
| 5                   | \[3, 3]         | 4            | Leaf → nums\[3] = 4            |
| 6                   | \[4, 4]         | 5            | Leaf → nums\[4] = 5            |
| 7                   | \[0, 0]         | 1            | Leaf → nums\[0] = 1            |
| 8                   | \[1, 1]         | 2            | Leaf → nums\[1] = 2            |


*/

void updateSegemntTree(vector<int>& nums, int left, int right, vector<int>& segmentTree, int index, int val, int updateIdx){
    if (left == right) {
        // Leaf node
        segmentTree[index] = val;
        nums[updateIdx] = val; 
        return;
    }

    int mid = left + (right - left) / 2;

    // Left child at 2*index + 1
    if(updateIdx <= mid)
        updateSegemntTree(nums, left, mid, segmentTree, 2 * index + 1, val, updateIdx);

    // Right child at 2*index + 2
    if(updateIdx > mid)
        updateSegemntTree(nums, mid + 1, right, segmentTree, 2 * index + 2, val, updateIdx);

    // Internal node: sum of left and right children
    segmentTree[index] = segmentTree[2 * index + 1] + segmentTree[2 * index + 2];
}

void buildSegmentTree(vector<int>& nums, int left, int right, vector<int>& segmentTree, int index) {
    if (left == right) {
        // Leaf node
        segmentTree[index] = nums[left];
        return;
    }

    int mid = left + (right - left) / 2;

    // Left child at 2*index + 1
    buildSegmentTree(nums, left, mid, segmentTree, 2 * index + 1);

    // Right child at 2*index + 2
    buildSegmentTree(nums, mid + 1, right, segmentTree, 2 * index + 2);

    // Internal node: sum of left and right children
    segmentTree[index] = segmentTree[2 * index + 1] + segmentTree[2 * index + 2];
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int n = nums.size();

    // Allocate enough space: at most 4*n is safe
    vector<int> segmentTree(4 * n, 0);

    // Build the segment tree from root (index 0)
    buildSegmentTree(nums, 0, n - 1, segmentTree, 0);

    // Print the first 2*n - 1 elements (optional)
    for (int i = 0; i < 2 * n - 1; i++) {
        cout << segmentTree[i] << ",";
    }
    cout << endl;


    /*

    vector<int> nums = {1, 2, 3, 4, 5};
    int n = nums.size();
    vector<int> segmentTree(4 * n);
    buildSegmentTree(nums, 0, n - 1, segmentTree, 0);

    updateSegmentTree(nums, 0, n - 1, segmentTree, 0, 10, 2);  // update nums[2] = 10
    */

    return 0;
}

// problems where we can use
// queries in range 
// range sum
// max in range
// any quries which lies in range