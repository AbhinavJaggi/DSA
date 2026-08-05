class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        vector<int> vec(2,0);
        int pt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') vec[0]++;
            else vec[1]++;
            if(vec[0]==vec[1] && vec[1]>1){
                while(pt<i){
                    if( pt+1 != i) ans+=s[pt+1];
                    pt++;
                }
                vec[0]=0;
                vec[1]=0;
                pt=i+1;
            }
            else if(vec[0]==vec[1] && vec[1]<=1){
                vec[0]=0;
                vec[1]=0;
                pt=i+1;
            }
        }
        return ans;
    }
};