class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int sum=0,winsum=0;// total sum and sum of window(n-k elements)
        for(int i=0;i<n;i++){
            sum+=cardPoints[i];
            if(i<n-k)winsum+=cardPoints[i];
        }
        int ans=sum-winsum;
        for(int i=n-k;i<n;i++){
            winsum-=cardPoints[i-n+k];
            winsum+=cardPoints[i];
            ans=max(ans,sum-winsum);
        }
        return ans;
        
    }
};