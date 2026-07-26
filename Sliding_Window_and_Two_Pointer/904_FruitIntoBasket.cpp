class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0;
        int r=0;
        int distinct=0;
        int ans=0;
        map<int,int> freq;
        while(r<fruits.size()){
            freq[fruits[r]]++;
            if(freq[fruits[r]]==1) distinct++;
            if(distinct>2){
                freq[fruits[l]]--;
                if(freq[fruits[l]]==0) distinct--;
                l++;
            }
            if(distinct<=2) ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};