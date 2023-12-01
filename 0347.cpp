class Solution { // Faster(?) solution
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> count;
        for (auto i : nums) count[i]++;

        vector<vector<int>> frequency;
        frequency.resize(nums.size() + 1);
        for (auto i : count) {
            frequency[i.second].push_back(i.first);
        }

        vector<int> ans;
        for(int i = frequency.size() - 1; i >= 0; i--) {
            for (auto j : frequency[i]) ans.push_back(j);
            if (ans.size() == k) return ans;
        }
        return ans;
    }
};

class Solution { // Initial solution
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> frequency;
        for (auto i : nums) frequency[i]++;

        vector<pair<int, int>> temp;
        for (auto& it : frequency) temp.push_back(it);
        sort(temp.begin(), temp.end(), cmp);

        vector<int> ans;
        for (int i = 0; i < k; i++) ans.push_back(temp[i].first);
        return ans;
    }

    static bool cmp(pair<int, int>& a, pair<int, int>& b) { 
        return a.second > b.second; 
    } 
};
