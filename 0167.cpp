class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans = {0, 1};
        while (numbers[ans[0]] + numbers[ans[1]] != target) {
            if (numbers[ans[0]] + numbers[ans[1]] > target || ans[1] + 1 == numbers.size()) {
                int curVal = numbers[ans[0]];
                while (numbers[ans[0]] == curVal) ans[0]++;
                ans[1] = ans[0] + 1;
            }
            else {
                ans[1]++;
            }
        }
        ans[0]++;
        ans[1]++;
        return ans;
    }
};
