class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    int Csum=0;
    int sum=INT_MIN;
    for(int i=0;i<nums.size();i++){
        Csum+=nums[i];
        if(Csum>=sum){
            sum=Csum;
        }
        if(Csum<0){
            Csum=0;
        }
    }
    return sum;
    }
};