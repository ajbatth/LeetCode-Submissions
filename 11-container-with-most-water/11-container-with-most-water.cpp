class Solution {
public:
    int maxArea(vector<int>& height) {
        int area=0;
        int minidx=0 , ans=0;
        
        int i=0;
        int j=height.size()-1;
        
        while(i<=j){
            minidx=height[i]<height[j]?i:j;
            area=(j-i)*height[minidx];
            ans=max(ans,area);
            minidx==i?i++:j--;
        }
        return ans;
        
    }
};