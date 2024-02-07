class Solution { // Final solution - neater code
public:
    int lengthOfLongestSubstring(string s) {
        set<char> contains;
        int longest = 0;
        int l = 0;
        for (int r = 0; r < s.length(); r++) {
            while (contains.contains(s[r])) {
                contains.erase(s[l]);
                l++;
            }
            contains.insert(s[r]);
            longest = max(longest, r - l + 1);
        }
        return longest;
    }
};

class Solution { // Slightly faster solution with set
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) return 0;
        set<char> contains;
        contains.insert(s[0]);
        int longest = 1;
        int l = 0, r = 1;
        while (r < s.length()) {
            if (contains.contains(s[r])) {
                contains.erase(s[l]);
                if (r == l) r++;
                else l++;
            } 
            else {
                contains.insert(s[r]);
                longest = max(longest, r - l + 1);
                r++;
            }
        }
        return longest;
    }
};

class Solution { // Initial solution with map
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) return 0;
	unordered_map<char, int> contains;
        contains[s[0]] += 2;
        int longest = 1;
        int l = 0, r = 0;
        while (r < s.length()) {
            bool containsDouble = false;
            for (auto i : contains) {
                if (i.second > 1) {
                    containsDouble = true;
                    break;
                }
            }
            if (containsDouble) {
                contains[s[l]]--;
                if (r == l) {
                    r++;
                    contains[s[r]]++;
                }
                else l++;
            } 
            else {
                longest = max(longest, r - l + 1);
                r++;
                contains[s[r]]++;
            }
        }
        return longest;
    }
};
