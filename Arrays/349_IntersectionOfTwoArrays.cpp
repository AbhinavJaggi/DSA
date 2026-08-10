class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st;
        vector<int> vec;
        for( auto it : nums1){
            st.insert(it);
        }
        for(auto it: nums2){
           if(st.find(it)!=st.end()){
            vec.push_back(it);
            st.erase(it);
           }
        }
        return vec ;
    }
};