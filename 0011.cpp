class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1, maxArea = 0;
        while (r > l) {
            maxArea = max(maxArea, min(height[l], height[r]) * (r - l));
            if (height[r] < height[l]) r--;
            else l++;
        }
        return maxArea;
    }
};
