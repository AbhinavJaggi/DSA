class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long g=1;
        long long maxi=INT_MIN;
        long long a=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                g=gcd(nums[i],nums[j]);
                a=1LL*nums[i]*nums[j]; 
                maxi=max(maxi,a/(g*g));
            }
        }
        return maxi;
    }
};