class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        int half = (total + 1) / 2;

        vector<int> a, b;
        if (nums1.size() < nums2.size()) {
            a = nums1;
            b = nums2;
        }
        else {
            a = nums2;
            b = nums1;
        }

        int l = 0;
        int r = a.size();

        while (true) {
            int i = (l + r) / 2; // A
            int j = half - i; // B

            int aLeft = INT_MIN, aRight = INT_MAX, bLeft = INT_MIN, bRight = INT_MAX;
            if (i - 1 >= 0) aLeft = a[i - 1];
            if (i < a.size()) aRight = a[i];
            if (j - 1 >= 0) bLeft = b[j - 1];
            if (j < b.size()) bRight = b[j];

            // Partition is correct
            if (aLeft <= bRight && bLeft <= aRight) {
                // Odd num elements
                if (total % 2 == 1) {
                    return max(aLeft, bLeft);
                }
                // Even
                return ((double) max(aLeft, bLeft) + (double) min(aRight, bRight)) / 2.0;
            }
            else if (aLeft > bRight) {
                r = i - 1;
            }
            else {
                l = i + 1;
            }
        }
    }
};
