class TimeMap {
private:
    unordered_map<string, vector<pair<string, int>>> store;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if(store.find(key) == store.end()){
            return "";
        }
        const auto& pairs = store[key];
        auto it = upper_bound(pairs.begin(), pairs.end(), make_pair(string(""), timestamp), [](const pair<string, int>& a, const pair<string, int>& b){
            return a.second < b.second;
        });
        if(it == pairs.begin()){
            return "";
        }
        return prev(it)->first;
    }
};
