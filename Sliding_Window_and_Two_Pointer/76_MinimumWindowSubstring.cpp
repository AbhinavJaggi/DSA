class Solution {
public:
    string minWindow(string s, string t) {
        int l=0;
        int r=0;
        int count=0;
        int minLen=INT_MAX;
        int startIndx=-1;
        map<char,int> mpp;
        for(auto it:t){
            mpp[it]++;
        }
        while(r<s.size()){
            if(mpp[s[r]]>0) count++;
            mpp[s[r]]--;
            while(count==t.size()){
                if(r-l+1<minLen){
                minLen=r-l+1;
                startIndx=l;
                }
                mpp[s[l]]++;
                if(mpp[s[l]]>0) count--;
                l++;
            }
            r++;
        }
        return startIndx==-1 ? "" : s.substr(startIndx,minLen);
    }
};