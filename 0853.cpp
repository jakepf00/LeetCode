class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<long double, long double>> cars;
        for (int i = 0; i < position.size(); i++) cars.push_back(make_pair(position[i], speed[i]));
        sort(cars.rbegin(), cars.rend());
        int ans = 0;
        long double prevArrival = 0;
        for (auto i : cars) {
            long double curArrival = (target - i.first) / i.second;
            if (curArrival > prevArrival) {
                ans++;
                prevArrival = curArrival;
            }
        }
        return ans;
    }
};
