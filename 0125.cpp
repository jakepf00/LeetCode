class Solution { // Fast solution
public:
    bool isPalindrome(string s) {
        string s2;
        for (auto i : s) {
            if (isalnum(i)) s2.push_back(tolower(i));
        }
        string s3 = s2;
        reverse(s3.begin(), s3.end());
        return s2 == s3;
    }
};

class Solution { // Slightly faster solution
public:
    bool isPalindrome(string s) {
        for (int i = 0; i < s.length(); i++) {
            if (!isalnum(s[i])) {
                s.erase(i, 1);
                i--;
            }
            else s[i] = tolower(s[i]);
        }
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};

class Solution { // Initial solution
public:
    bool isPalindrome(string s) {
        for (int i = 0; i < s.length(); i++) {
            if (!isalnum(s[i])) {
                s.erase(i, 1);
                i--;
            }
            else s[i] = tolower(s[i]);
        }
        string s2 = s;
        reverse(s2.begin(), s2.end());
        if (s == s2) return true;
        else return false;
    }
};
