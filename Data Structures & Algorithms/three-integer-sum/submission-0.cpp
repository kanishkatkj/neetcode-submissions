class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> MySet;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n-2; i++){
            int l = i+1;
            int r = n-1;
            int target = -nums[i];
            while(l < r){
                if(nums[l] + nums[r] == target){
                    MySet.insert({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                }
                else if(nums[l] + nums[r] > target){
                    r--;
                }
                else{
                    l++;
                }
            }
        }
        return vector<vector<int>>(MySet.begin(), MySet.end());
    }
};
