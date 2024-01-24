class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int depth = 0;
        int ans = 0;
        while (l < r) {
            if (min(height[l], height[r]) > depth) {
                ans += (r - l - 1) * (min(height[l], height[r]) - depth);
                depth = min(height[l], height[r]);
            }
            else if (height[l] > height[r]) {
                r--;
                if (r != l) ans -= min(height[r], depth);
            }
            else {
                l++;
                if (r != l) ans -= min(height[l], depth);
            }
        }
        return ans;
    }
};
