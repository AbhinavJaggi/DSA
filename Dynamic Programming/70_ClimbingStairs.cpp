class Solution {
    int rec(int n,vector<int>& vec){
        if(n==0) return vec[0];
        if(n==1) return vec[1];
        if(vec[n]!=-1) return vec[n];
        int left=rec(n-1,vec);
        int right=rec(n-2,vec);
        return vec[n]=left+right;
    }
public:
    int climbStairs(int n) {
        vector<int>vec (n+1,-1);
        vec[0]=1;
        vec[1]=1;
        // for(int i=2;i<=n;i++){           // tabulation way
        //     vec[i]=vec[i-1]+vec[i-2];
        // }
        rec(n,vec); // memoization way
        return vec[n];
    }
};