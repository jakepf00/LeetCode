class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        //ans.push_back(strs.size());
        //ans.push_back('_');
        for (auto i : strs) {
            ans += to_string(i.length());
            ans.push_back('_');
            ans += i;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;

        while (s.length() > 0) {
            // Retrieve string length
            string curLenStr = "";
            while (s[0] != '_') {
                curLenStr += s[0];
                s.erase(0, 1);
            }
            s.erase(0, 1);
            int curLen = stoi(curLenStr);

            // Get num of chars for current string
            string curString = "";
            while (curLen--) {
                curString.push_back(s[0]);
                s.erase(0, 1);
            }
            ans.push_back(curString);
        }
        return ans;
    }
};
