class Solution {
public:
    bool isPalindrome(double x) {
if (x<0) return false;
double reverse = 0; int temp = x;
while (temp>0){
    reverse = reverse*10 + (temp%10); 
     temp /=10;
     }
    return reverse==x;
}
};