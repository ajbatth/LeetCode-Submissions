class Solution {
public:
    int brokenCalc(int s, int t) {
        int count=0;
        while(s<t){
            
            if(t%2==0){
                t/=2;
                count++;
            }
            else{
                t+=1;
                count++;
            }
            
        }
        return count+s-t;
    }
};