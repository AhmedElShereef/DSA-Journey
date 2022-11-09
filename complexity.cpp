using namespace std;
#include<math.h>
#include<iostream>


// O(N^2)    quadratic
int sum(int n) {
    int res { };
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= i; j++)
            res++;
return res;            
}
// O(N)     linear
int sumOfN(int n) {
    int res { };
    for(int i = 1; i <= n; i++) 
        res += i;
    return res;
}
// O(1)     constant
int sumOfN_4(int n) {
     return n*(n+1) / 2; // formula   
}
// (N) WORST
// (N/2) -> (N)   AVERAGE
// (1) BEST 
int arrSum(int arr[],int sz) { 
    if(sz % 2 == 0) return 0;   // BEST

    int res { };
    for(int i = 0; i < sz; i++) 
        res += arr[i];
return res;        
}

/*
    BigO    UPPER   WORST  (N)              covers both best and average cases
    Theta   Exact(sure)   AVERAGE (n)

    Omega   LOWER   BEST    (1)

*/
int search(int arr[] , int sz , int num) {
    for(int i = 0; i < sz; i++) {
        if(arr[i] == num)  return i;   
    }
return -1;    
}


// recursion  
int sumOfN_3(int n) {
    if(!n) return 0;        // base case

    return sumOfN_3(n-1) + n;   // recursive step 
}
// O(N) 
int sumOfN_2(int n) {
    int res { };
    while(n) {
        res += n;
    n--;
    }    
return res;    
}

int main(void) {

/*
cout << sum(5) << endl;
cout << sumOfN(5) << endl;
cout << sumOfN_2(5) << endl;
cout << sumOfN_3(5) << endl;
cout << sumOfN_4(5) << endl;
*/

/*
int arr[]  {1 , 2 , 3 , 4 , 5};
cout << arrSum( arr,5) << endl;
cout << search( arr,5 , 5) << endl;
*/

////////////////////////////////////////////////////////////////////////////
// Loops
/*
int n , c; cin >> n >> c;


// C 
// O(N/C) -> c constant -> O(N)
for(int i = 0; i < n; i += c) {
    cout << i << " ";
}
cout << endl;
////////////////////////////////////////////////////////////////////////////
// N/C           ->  O(N)
for(int i = n; i >= 0; i -= c) {
    cout << i << " ";
}
cout << endl;
////////////////////////////////////////////////////////////////////////////
// Logarithmic

// Log(n)

// decreses (*c) each iteration
for(int i = 1; i < n; i *= c) {
    cout << i << " ";
}
cout << endl;
////////////////////////////////////////////////////////////////////////////
// Log(n)

// decreases (*c) 
for(int i = n; i > 1; i /= c) {
    cout << i << " ";
}
cout << endl;

////////////////////////////////////////////////////////////////////////////
// log(log(n))    fast as fuck
for(int i = 2; i < n; i = pow(i,c)) {
    cout << i << " ";
}

*/

////////////////////////////////////////////////////////////////////////////
// Multiple Loop 
// add -> upper bound
// nested ->  * multiply

// O(N LogN)
int n ;
cin >> n ;
for(int j = 0; j < n; j++)  // O(N)
    for(int i = 1; i < n; i *= 2)  // O(LogN)
     cout << i << " ";
    
// two inputs 
// DIFFERENT INPUT-variable !!    
// O(n logn) + o(m^2)  ->  O(n logn + m^2) 





cout << "\nHello world\n";
    return 0;
}