class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int l=k-1;
        int r=cardPoints.size()-1;
        int leftsum=0;
        int rightsum=0;
        int ans=0;
        for(int i=0;i<=l;i++){
            leftsum+=cardPoints[i];
        }
        ans=leftsum;
        while(l>-1){
            leftsum-=cardPoints[l];
            rightsum+=cardPoints[r];
            l--;
            r--;
            ans=max(ans,leftsum+rightsum);
        }
        return ans;
    }
};