class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        long int low = 1;
        long int high = piles[piles.size()-1];
        long int mid = (low + high) / 2;
        while (low < high) {
            long int time = 0;
            for (auto i : piles) {
                time += (i / mid + (i % mid != 0));
		if (time > h) continue;
            }
            if (time > h) low = mid + 1;
            else high = mid;
            mid = (low + high) / 2;
        }
        return mid;
    }
};
