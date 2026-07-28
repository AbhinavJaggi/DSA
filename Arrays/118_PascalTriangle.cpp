class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vec;
        vector<int> v;
        int ans=1;
        for(int i=1;i<=numRows;i++){
            v={};
            v.push_back(1);
            for(int j=1;j<i;j++){
                ans=ans*(i-j);
                ans=ans/j;
                v.push_back(ans);
            }
            vec.push_back(v);
        }
        return vec;
    }
};