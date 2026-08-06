class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        int find_num;
        for(int i=0;i<nums.size();i++){
            find_num=target-nums[i];
            if(mpp.find(find_num)!=mpp.end()){
                return {mpp[find_num],i};
            }
            mpp[nums[i]]=i;
        }
        return {};
    }
};