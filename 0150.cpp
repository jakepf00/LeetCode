class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> thing;
        for (auto i : tokens) {
            if (i.length() > 1 || isdigit(i[0])) {
                thing.push(stoi(i));
            }
            else {
                int a, b;
                b = thing.top();
                thing.pop();
                a = thing.top();
                thing.pop();
                if (i == "+") thing.push(a + b);
                else if (i == "-") thing.push(a - b);
                else if (i == "*") thing.push(a * b);
                else if (i == "/") thing.push(a / b);
            }
        }
        return thing.top();
    }
};
