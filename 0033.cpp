class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;

            if (nums[l] > nums[r]) { // Not crossed pivot
                if (nums[mid] > nums[r]) { // Mid not cross pivot
                    if (nums[mid] > target && nums[l] <= target) r = mid - 1;
                    else l = mid + 1;
                }
                else { // Mid cross pivot
                    if (nums[mid] < target && nums[r] >= target) l = mid + 1;
                    else r = mid - 1;
                }
            }

            else { // Crossed pivot
                if (nums[mid] > target) r = mid - 1;
                else l = mid + 1;
            }
        }
        return -1;
    }
};
