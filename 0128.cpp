class Solution { // Slightly better solution
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> seq;
        for (auto i : nums) {
            seq[i] = i;
        }
        int maxSeq = 0;
        for (auto i : seq) {
            if (seq.find(i.first - 1) != seq.end()) continue;
            int cur = i.first;
            while (seq.find(cur + 1) != seq.end()) {
                cur++;
            }
            maxSeq = max(maxSeq, cur - i.first + 1);
        }
        return maxSeq;
    }
};

class Solution { // Initial solution
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> seq;
        for (auto i : nums) {
            if (seq.find(i) == seq.end()) seq[i] = i;
            if (seq.find(i-1) != seq.end()) seq[i-1] = i;
            if (seq.find(i+1) != seq.end()) seq[i] = i + 1;
        }
        int maxSeq = 0;
        for (auto i : seq) {
            if (seq.find(i.first-1) != seq.end()) continue;
            int curMax = 1;
            int cur = i.first;
            while (seq[cur] != cur) {
                curMax++;
                cur++;
            }
            maxSeq = max(maxSeq, curMax);
        }
        return maxSeq;
    }
};
