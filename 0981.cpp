class TimeMap { // Binary search - runtime: 293ms
public:
    map<string, vector<pair<string, int>>> times;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        times[key].push_back(make_pair(value, timestamp));
    }
    
    string get(string key, int timestamp) {
        if (times.find(key) == times.end()) return "";
        if (times[key][0].second > timestamp) return "";
        int r = times[key].size() - 1;
        int l = 0;
        while (l < r) {
            int mid = (l + r) / 2;
            if (times[key][mid].second < timestamp) {
                l = mid + 1;
            }
            else if (times[key][mid].second > timestamp) {
                r = mid - 1;
            }
            else return times[key][mid].first;
        }
        if (times[key][l].second <= timestamp) return times[key][l].first;
        else return times[key][l - 1].first;
    }
};

class TimeMap { // Runtime: 258ms
public:
    map<string, vector<pair<string, int>>> times;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        times[key].push_back(make_pair(value, timestamp));
    }
    
    string get(string key, int timestamp) {
        for (int i = times[key].size() - 1; i >= 0; i--) {
            if (times[key][i].second <= timestamp) return times[key][i].first;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
