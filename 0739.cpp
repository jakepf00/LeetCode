class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans;
        ans.resize(temperatures.size());
        stack<int> days;
        for (int i = 0; i < temperatures.size(); i++) {
            while (!days.empty() && temperatures[days.top()] < temperatures[i]) {
                ans[days.top()] = i - days.top();
                days.pop();
            }
            days.push(i);
        }
        return ans;
    }
};
