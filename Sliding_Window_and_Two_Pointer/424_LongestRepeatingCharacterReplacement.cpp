class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int r=0;
        int maxFreq=0;
        int ans=0;
        map<char,int> mpp;
        while(r<s.size()){
            mpp[s[r]]++;
            maxFreq=max(maxFreq,mpp[s[r]]);
            if((r-l+1)-maxFreq>k){
                mpp[s[l]]--;
                l++;
            }
            if((r-l+1)-maxFreq<=k) ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};