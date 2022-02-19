class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int>s;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%2==1)nums[i]*=2;
            s.insert(nums[i]);
        }
        int ans=*s.rbegin()-*s.begin();
        while(*s.rbegin()%2==0){
            int temp=*s.rbegin();
            
            if(temp%2==0){
                s.erase(temp);
                temp/=2;
                s.insert(temp);
                ans=min(ans,(*s.rbegin()-*s.begin()));
            }
            
            
            ans=min(ans,(*s.rbegin()-*s.begin()));
        }
        cout<<*s.rbegin()<<" "<<*s.begin()<<endl;
        return ans;
    }
};