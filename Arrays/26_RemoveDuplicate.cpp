class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int first =0;
        while(i<nums.size()){

            if(nums[first]!=nums[i]){
                swap(nums[first+1],nums[i]);
                first ++;
            }
            i++;
        }
        return first+1;
    }
};