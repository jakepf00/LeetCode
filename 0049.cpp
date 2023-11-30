class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string, int> key;
        for (auto i : strs) {
            string original = i;
            sort(i.begin(), i.end());
            if (key.find(i) != key.end()) {
                ans[key[i]].push_back(original);
            }
            else {
                vector<string> newVec;
                newVec.push_back(original);
                ans.push_back(newVec);
                key[i] = ans.size() - 1;
            }
        }
        return ans;
    }
};