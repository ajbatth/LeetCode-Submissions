class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k=m;
        for(int i=0;i<n;i++){
            int key=nums2[i];
            int j=k;
            
            while(j>0&&nums1[j-1]>key){
                nums1[j]=nums1[j-1];
                j--;
            }
            nums1[j]=key;
            k++;
        }
        
    }
};