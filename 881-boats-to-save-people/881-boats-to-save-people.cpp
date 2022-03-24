class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n=people.size();
        int s=0,e=n-1,count=0;
        while(s<=e){
            if(people[s]+people[e]<=limit && s!=e){
                count++;
                s++;
                e--;
                
            }
            else{
                count++;
                e--;
            }
        }
        return count;
    }
};