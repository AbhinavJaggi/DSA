class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       int lastM =m-1;
       int lastN =n-1;
       int lastarr=m+n-1;
       while(lastM>=0 && lastN>=0){
            if(nums1[lastM]>nums2[lastN]){
                nums1[lastarr]=nums1[lastM];
                lastM--;
            }
            else{
                nums1[lastarr]=nums2[lastN];
                lastN--;
            }
            lastarr--;
       }
        while(lastN>=0){
                nums1[lastarr]=nums2[lastN];
                lastN--;
                lastarr--;
            } 
       
    }
};