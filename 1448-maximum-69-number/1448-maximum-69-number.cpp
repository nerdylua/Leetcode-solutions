class Solution {
public:
    int maximum69Number (int num) {
        string numstring = to_string(num);
        for(char &digit : numstring){
            if(digit == '6'){
                digit = '9';
                break;
            }
        }
        return stoi(numstring);
    }
};