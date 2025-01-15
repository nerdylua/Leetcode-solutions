class Solution {
public:
    int minimizeXor(int num1, int num2) {
        bitset<32> firstNumber(num1);
        bitset<32> SecondNumber(num2);
        int a=SecondNumber.count();
        bitset<32> result(0);
        int x=31;
        while(a!=0 && x>=0){
            if(firstNumber[x]==1){
                result[x]=1;
                a--;
            }
            x--;
        }
        if(a!=0){
            int z=0;
            while(a!=0 && z<31){
                if(result[z]==0){
                    result[z]=1;
                    a--;
                }
                z++;
            }
        }
        return result.to_ulong();
    }
};