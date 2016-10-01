#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

class BigFloat
{
    public:
    char* str;
    int length;
    int integral;
    int fractional;
    int hasDec;

    int getDigitAtIndex (int index)
    {
        if ( index > fractional || (index*(-1))-integral > 0 ) return 0;
        
        
        if (index < 0 ) return  str[integral+index] - '0';
        
        if (index > 0 ) return  str[integral+index+hasDec-1] - '0';
        
    
    }

    void setDigitAtIndex (int index, int digit)
    {
        char c = '0' + digit;
        
        if (index < 0 ) str[integral+index] = '0' + digit;
        if (index > 0 ) str[integral+index+hasDec-1] = '0' + digit;
        
        c = str[integral+index+hasDec-1];

    }
    
    void setStr (char* input)
    {
        str = input;
        hasDec = 0;
        fractional = 0;
        int count = 0;
        while (*input)
        {
            if (*input == '.') 
            {
                integral = count;
                hasDec = 1;
            }
            count++;
            input++;
        }
        
        length = count;
        fractional = length-integral-1;
    
    }
    
    static BigFloat* addBigFloats (BigFloat a, BigFloat b)
    {
        int largerFraction = a.fractional > b.fractional? a.fractional : b.fractional;
        int largerIntegral = a.integral > b.integral? a.integral : b.integral;
        int carry = 0;
        int hasDec = 0;

        if (a.hasDec || b.hasDec) hasDec = 1;

        char* retStr = (char*) malloc ( largerFraction+largerIntegral+hasDec+2);
        
        for (int i = 0; i<largerFraction+largerIntegral+hasDec+2; i++) retStr[i]='b';
        
        retStr[largerFraction+largerIntegral+hasDec+1] = 0; //null terminate

        
        BigFloat* retVal = new BigFloat();
        retVal->hasDec = hasDec;
        retVal->str = retStr;
        retVal->integral = largerIntegral+1;
        retVal->fractional = largerFraction;
        
        for (int i = largerFraction; i > 0; i--)
        {
            int setDigit = a.getDigitAtIndex(i) + b.getDigitAtIndex(i) + carry;
            carry = setDigit > 10 ? 1 : 0;
            setDigit %= 10;
            retVal->setDigitAtIndex (i, setDigit);
        }
        
        if (hasDec) retVal->str[largerIntegral+1] = '.'; // add the decimal.
        
        
        for (int i = -1; i >= (-1)*largerIntegral; i--)
        {
            int setDigit = a.getDigitAtIndex(i) + b.getDigitAtIndex(i) + carry;
            carry = setDigit > 10 ? 1 : 0;
            setDigit %= 10;
            retVal->setDigitAtIndex (i, setDigit);
        }
        
        if (carry) retVal->setDigitAtIndex ((-1)*largerIntegral-1, 1);
        else retVal->setDigitAtIndex ((-1)*largerIntegral-1, 0);
        
        
        return retVal;
         
        
        
    }
    
};
    
int main()
{
    BigFloat a, b;
    
    a.setStr("24.24335353533535353");
    b.setStr("535353535334.4");
    
    BigFloat* response = BigFloat::addBigFloats(a,b);

}