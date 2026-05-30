class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        if(n == 0) return 0;
        vector<pair<int, double>> cars(n);
        for(int i = 0; i < n; i++){
            double time = (double)(target - position[i]) / speed[i];
            cars[i] = {position[i], time};
        }
        sort(cars.rbegin(), cars.rend());
        int carFleet = 0;
        double maxTime = 0.0;
        for(int i = 0; i < n; i++){
            double currentTime = cars[i].second;
            if(currentTime > maxTime){
                carFleet++;
                maxTime = currentTime;
            }
        }
        return carFleet;
    }
};
