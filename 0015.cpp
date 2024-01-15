class Solution { // More readable solution
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int first = 0; first < nums.size() - 1; first++) {
            if (first > 0 && nums[first] == nums[first - 1]) continue;
            int left = first + 1, right = nums.size() - 1;
            while (left < right) {
                if (nums[left] + nums[right] + nums[first] < 0) left++;
                else if (nums[left] + nums[right] + nums[first] > 0) right--;
                else {
                    vector<int> newAns = { nums[first], nums[left], nums[right] };
                    ans.push_back(newAns);
                    left++;
                    while (left < right && nums[left - 1] == nums[left]) left++;
                }
            }
        }
        return ans;
    }
};

class Solution { // Initial solution
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        int first = 0;
        int last = nums.size() - 1;
        while (first < last - 1) {
            int temp1 = first;
            int temp2 = last - 1;
            int needed = -nums[last];
            while (temp1 < temp2) {
                if (nums[temp1] + nums[temp2] == needed) {
                    vector<int> newAns = { nums[temp1], nums[temp2], nums[last] };
                    ans.push_back(newAns);
                    int oldTemp1 = temp1;
                    while (temp1 < temp2 && nums[oldTemp1] == nums[temp1]) temp1++;
                }
                else if (nums[temp1] + nums[temp2] < needed) {
                    temp1++;
                }
                else { // > needed
                    temp2--;
                }
            }
            int oldLast = last;
            while (first < last - 1 && nums[oldLast] == nums[last]) last--;
        }
        return ans;
    }
};
