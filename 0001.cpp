class Solution { // Fast solution
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        map<int, int> key;
        for (int i = 0; i < nums.size(); i++) {
            if (key.find(nums[i]) != key.end()) {
                ans.push_back(key[nums[i]]);
                ans.push_back(i);
                return ans;
            }
            key[target - nums[i]] = i;
        }
        return ans;
    }
};

class Solution { // Initial solution
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }
};

