class Solution {
public:
    int reverse(int x) {
        long long revnum=0;
        while(x!=0){
            int lastnum=x%10;
            revnum=(revnum*10)+lastnum;
            x/=10;
        }if(revnum<INT_MIN || revnum>INT_MAX) return 0;
        else return (int)revnum;
    }
};