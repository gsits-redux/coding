#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

string myitoa (int x)
{
    bool neg_sign = x < 0;
    
    if (x == 0 ) return "0";
    
    if (neg_sign)  
    {
        x *= -1;   
    }

    int n = 0; //number of digits
    int c = x;
    
    while (c>0)
    {
        n++;
        c /= 10;
    }    
    
    string s (n,0);
    c = x;
    for (int i = n-1; i >= 0; i--)
    {
        s[i] = '0' + (c%10);
        c /= 10;
    }
    
    if (neg_sign) 
    {
        s = "-" + s ;
    }
    
    return s + "\n";
    
}

int main()
{
    cout << myitoa(100);
    cout << myitoa(-123123100);
    cout << myitoa(12412100);
    cout << myitoa(142100);
    cout << myitoa(10630);
    cout << myitoa(-102352530);
    

}
    
    