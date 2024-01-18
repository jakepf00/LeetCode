class Solution { // Binary search solution in O(log(n)) time - 23ms runtime
public:
    int search(vector<int>& nums, int target) {
        int high = nums.size() - 1;
        int low = 0;
        while (high >= low) {
            int mid = (high + low) / 2;
            if (nums[mid] < target) low = mid + 1;
            else if (nums[mid] > target) high = mid - 1;
            else return mid;
        }
        return -1;
    }
};

class Solution { // Cheater solution in O(n) time - 27ms runtime
public:
    int search(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) if (nums[i] == target) return i;
        return -1;
    }
};
