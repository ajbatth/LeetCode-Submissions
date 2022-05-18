class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0,j=n-1;
        int ans=min(height[i],height[j])*(j-i);
        while(i<j){
            if(height[i]<height[j])i++;
            else j--;
            ans=max(ans,min(height[i],height[j])*(j-i));
        }
        return ans;
    }
};