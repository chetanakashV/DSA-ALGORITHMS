// This is euclidean algorithm to find gcd of two numbers and also the form ax+by = gcd. 

#include <bits/stdc++.h> 
using namespace std; 

int gcdBasic(int a, int b){
    if(a == 0) return b; 
    return gcdBasic(b%a, a); 
}

// also finds x and y such that ax + by = gcd(a,b); 
int gcdExtended(int a, int b, int& x, int& y){
    if(a == 0){
        x = 0; 
        y = 1; 
        return b; 
    }

    int x1, y1; 
    int gcd = gcdExtended(b%a, a, x1, y1) ; 

    x = y1 - (b/a) * x1; 
    y = x1; 

    return gcd; 

}

int main() {

    int a = 10, b = 15, x, y; 

    cout << "GCD of " << a << " and " << b << ": "<< gcdBasic(a,b) << endl; 

    int ans = gcdExtended(a,b,x,y); 

    cout << x <<"*"<< a << "+" << y <<"*" << b <<"=" << ans << endl; 

    return 0; 
}