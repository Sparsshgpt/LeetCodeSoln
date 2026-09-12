class Solution {
public:
    int subtractProductAndSum(int n) {
        int p=1;
        int s=0;
        while(n>0){
            int m=n%10;
            s+=m;
            p*=m;
            n=n/10;
        }
        return p-s;

        
    }
};