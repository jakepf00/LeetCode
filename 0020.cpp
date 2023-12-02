class Solution { // Cleaner solution with map
public:
    bool isValid(string s) {
        map<char, char> pairs;
        pairs[')'] = '(';
        pairs['}'] = '{';
        pairs[']'] = '[';
        stack<char> par;
        for (auto i : s) {
            if (pairs.find(i) != pairs.end()) {
                if (par.empty()) return false;
                if (par.top() == pairs[i]) par.pop();
                else return false;
            }
            else par.push(i);
        }
        if (par.empty()) return true;
        else return false;
    }
};

class Solution { // Original solution
public:
    bool isValid(string s) {
        stack<char> par;
        for (auto i : s) {
            if (i == '(' || i == '{' || i == '[') par.push(i);
            else {
                if (par.empty()) return false;
                else if (i == ')') {
                    if (par.top() == '(') par.pop();
                    else return false;
                }
                else if (i == '}') {
                    if (par.top() == '{') par.pop();
                    else return false;
                }
                else if (i == ']') {
                    if (par.top() == '[') par.pop();
                    else return false;
                }
            }
        }
        if (par.empty()) return true;
        else return false;
    }
};
