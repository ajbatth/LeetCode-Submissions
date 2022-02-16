class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>maxi(n);
        int m=height[0];
        for(int i=0;i<n;i++){
            m=max(m,height[i]);
            maxi[i]=m;
        }
         m=height[n-1];
        for(int i=n-1;i>=0;i--){
            m=max(m,height[i]);
            maxi[i]=min(m,maxi[i]);
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            
            ans+=abs(maxi[i]-height[i]);
        }
        return ans;
    }
};