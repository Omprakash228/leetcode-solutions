#include <iostream>

using namespace std;


class Solution {
    public: 
        static string intToRoman(int num) {
            int d=num/1000;    //thousands digit
            string roman(d,'M');
            num%=1000;

            d=num/100;         //hundreds digit
            if(d==9) roman+="CM";
            else if(d>=5) roman+="D"+string(d-5,'C');
            else if(d==4) roman+="CD";
            else roman+=string(d,'C');
            
            num%=100;
            d=num/10;          //tens digit
            if(d==9) roman+="XC";
            else if(d>=5) roman+="L"+string(d-5,'X');
            else if(d==4) roman+="XL";
            else roman+=string(d,'X');
                
            num%=10;
            d=num/1;           //units digit
            if(d==9) roman+="IX";
            else if(d>=5) roman+="V"+string(d-5,'I');
            else if(d==4) roman+="IV";
            else roman+=string(d,'I');
            
            return roman;
        }
};

int main() {
    cout << Solution::intToRoman(1994) << endl;
    return 0;
}