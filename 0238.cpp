class Solution { // Solution with O(1) extra space complexity
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        ans.resize(nums.size());
        ans[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            ans[i] = ans[i-1] * nums[i-1];
        }
        int postfix = 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            postfix = postfix * nums[i+1];
            ans[i] *= postfix;
        }
        return ans;
    }
};

class Solution { // Better solution using pre and postfix
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans, prefix, postfix;
        ans.resize(nums.size());
        prefix.resize(nums.size());
        postfix.resize(nums.size());
        prefix[0] = 1;
        postfix[nums.size()-1] = 1;
        for (int i = 1; i < nums.size(); i++) {
            prefix[i] = prefix[i-1] * nums[i-1];
        }
        for (int i = nums.size() - 2; i >= 0; i--) {
            postfix[i] = postfix[i+1] * nums[i+1];
        }
        for (int i = 0; i < nums.size(); i++) {
            ans[i] = prefix[i] * postfix[i];
        }
        return ans;
    }
};

class Solution { // Solution using hashing
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        map<int, int> key;
        for (auto i : nums) {
            if (key.find(i) != key.end()) key[i] *= i;
            else key[i] = 1;
        }
        for (auto i : nums) {
            for (auto& j : key) {
                if (j.first != i) j.second *= i;
            }
        }
        for (auto i : nums) {
            ans.push_back(key[i]);
        }
        return ans;
    }
};
