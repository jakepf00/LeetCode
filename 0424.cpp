class Solution { // O(n) solution
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> contains;
        int l = 0;
        int maxf = 0;
        int longest = 0;

        for (int r = 0; r < s.length(); r++) {
            contains[s[r]]++;
            maxf = max(contains[s[r]], maxf);

            while ((r - l + 1) - maxf > k) {
                contains[s[l]]--;
                l++;
            }

            longest = max(longest, r - l + 1);
        }
        return longest;
    }
};

class Solution { // O(26n) solution
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> contains;
        int l = 0;
        int longest = 0;

        for (int r = 0; r < s.length(); r++) {
            contains[s[r]]++;

            int maximum = 0;
            for (auto i : contains) {
                maximum = max(i.second, maximum);
            }
            while ((r - l + 1) - maximum > k) {
                contains[s[l]]--;
                l++;
                for (auto i : contains) {
                    maximum = max(i.second, maximum);
                }
            }
            
            longest = max(longest, r - l + 1);
        }
        return longest;
    }
};
