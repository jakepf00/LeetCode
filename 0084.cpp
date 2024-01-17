class Solution { // Much faster solution with same general idea
public:
    int largestRectangleArea(vector<int>& heights) {
        int largest = 0;
        stack<pair<int, int>> rects;
        for (int i = 0; i < heights.size(); i++) {
            if (rects.empty() || heights[i] > rects.top().second) {
                rects.push(make_pair(i, heights[i]));
            }
            else if (heights[i] == rects.top().second) continue;
            else {
                int startIndex = i;
                while (!rects.empty() && rects.top().second > heights[i]) {
                    startIndex = rects.top().first;
                    largest = max(largest, rects.top().second * (i - rects.top().first));
                    rects.pop();
                }
                rects.push(make_pair(startIndex, heights[i]));
            }
        }
        while (!rects.empty()) {
            largest = max(largest, (rects.top().second * ((int) heights.size() - rects.top().first)));
            rects.pop();
        }
        return largest;
    }
};

class Solution { // Initial solution
public:
    int largestRectangleArea(vector<int>& heights) {
        int largest = 0;
        vector<pair<int, int>> rects;
        for (auto i : heights) {
            if (rects.empty()) {
                rects.push_back(make_pair(i, 1));
                largest = max(largest, rects.back().first * rects.back().second);
                continue;
            }
            
            if (i == 0) rects.clear();
            else if (i <= rects.back().first) {
                int count = 0;
                while (!rects.empty() && rects.back().first >= i) {
                    count = rects.back().second;
                    rects.pop_back();
                }
                rects.push_back(make_pair(i, count));
                for (auto& j : rects) {
                    j.second++;
                    largest = max(largest, j.first * j.second);
                }
            }
            else if (i > rects.back().first) {
                rects.push_back(make_pair(i, 0));
                for (auto& j : rects) {
                    j.second++;
                    largest = max(largest, j.first * j.second);
                }
            }
        }
        return largest;
    }
};
