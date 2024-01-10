class Solution { // Final solution - deque for still great memory but much improved speed
public:
    vector<string> generateParenthesis(int n) {
        deque<string> temp;
        temp.push_back("(");
        while (temp.front().length() < n * 2) {
            int open = ranges::count(temp.front(), '(');
            int close = ranges::count(temp.front(), ')');
            if (open < n) temp.push_back(temp.front() + "(");
            if (open > close) temp.push_back(temp.front() + ")");
            temp.pop_front();
        }
        vector<string> ans = {temp.begin(), temp.end()};
        return ans;
    }
};

class Solution { // Second solution (GREAT memory performance, speed a bit lagging)
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        ans.push_back("(");
        while (ans[0].length() < n * 2) {
            int open = ranges::count(ans[0], '(');
            int close = ranges::count(ans[0], ')');
            if (open < n) ans.push_back(ans[0] + "(");
            if (open > close) ans.push_back(ans[0] + ")");
            ans.erase(ans.begin());
        }
        return ans;
    }
};

class Solution { // Initial (terrible) solution
public:
    vector<string> generateParenthesis(int n) {
        vector<string> temp;
        temp.push_back("(");
        temp.push_back(")");
        for (int i = 1; i < n * 2; i++) {
            while (temp[0].length() <= i) {
                if (isValidMid(temp[0] + "(")) temp.push_back(temp[0] + "(");
                if (isValidMid(temp[0] + ")")) temp.push_back(temp[0] + ")");
                temp.erase(temp.begin());
            }
        }
        vector<string> ans;
        for (auto i : temp) {
            if (isValid(i)) ans.push_back(i);
        }
        return ans;
    }

    bool isValidMid(string paren) {
        stack<char> test;
        for (auto i : paren) {
            if (i == '(') {
                test.push(i);
            }
            else {
                if (test.size() == 0) return false;
                else if (test.top() == '(') {
                    test.pop();
                }
                else return false;
            }
        }
        return true;
    }

    bool isValid(string paren) {
        stack<char> test;
        for (auto i : paren) {
            if (i == '(') {
                test.push(i);
            }
            else {
                if (test.size() == 0) return false;
                else if (test.top() == '(') {
                    test.pop();
                }
                else return false;
            }
        }
        if (test.size() == 0) return true;
        else return false;
    }
};
