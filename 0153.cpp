class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (r + l) / 2;
            if (nums[l] < nums[r]) return nums[l];
            if (nums[mid] >= nums[l]) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
        return nums[l];
    }
};
