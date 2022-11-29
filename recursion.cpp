using namespace std;
#include<math.h>
#include<iostream>


// aux space - time 


// DP       Backtracking        D&C --- iteration = complex
// DFS traversal (tree - graph)

// infinite loop stack overflow - base case
void func(int n) {
if(!n)  
    return;
    cout <<  "hello\n";
 func(n-1);
}



// call overhead
// stack function calls ... Auxiliary space O(N+1) -> O(N) 
int sumOfN_3(int n) {
    if(!n) return 0;        // base case

    return sumOfN_3(n-1) + n;   // recursive step 
}

// Aux  == Height of the Tree -> recurrence relation
 


// Time O(2^n)  Exponential
// Space O(1)
// Auxiliary Space O(N)
int fib(int n) {
    if(n == 0 || n == 1)
        return n;
return fib(n - 1) + fib(n - 2);
}


//Bottom-Up Approach using Tabulation

// Space O(N)
// Time O(N) 
int fib_array(int n) {
    int arr[n + 1] { }; // space complexity a container
    arr[0] = 0;
    arr[1] = 1;
    for(int i = 2; i <= n; i++) {
            arr[i] = arr[i-1] + arr[i-2];
    }
return arr[n];
}


//Iterative Bottom-Up Approach

// Space O(3) -> O(1)
// Time O(N) 
int fib_optimal_variables(int n) {
        if(n == 0 || n == 1)
         return n;

        int c { };
        int a { } , b {1};
    for(int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }  
return c;      
}


int log_base_2(int n) {
    if(n <= 1)
        return 0;
    return 1 + log_base_2(n/2)   ;    // base 2
}


void decimal_to_binary(int n) {
    if(!n)
        return;
    decimal_to_binary(n/2); // division
 cout << n % 2;  // remainder ... 0 or 1    
}
// right order ... deepest cout call --




// optimization
// tail call elimination -- compilers - recursion
// recursice step-call is at the last in the func.
// the parent has nothing to DO

// less time ... each call = out its result  --- quick sort -- pre-in order trav.
void print_n_to_1(int n) { 
    if(n <= 0)      // stop
        return;
    cout << n << " ";   // body
print_n_to_1(n-1);    // step - recursive call with a change in PARAMETER !
}


// more time -> Save the state ! -- merge sort -- post order
void print_1_to_n(int n) {
    if(n <= 0)      
        return;
    print_1_to_n(n-1);  // 0 -- each parent now will out his result after the base case
cout << n << " ";
}


// by adding an extra parameter
void print_1_to_n_TAIL(int n , int cnt = 1) {   // from 1 to N(cnt++)
    if(n <= 0)      
        return;
     cout << cnt << " "; // Not n
    print_1_to_n_TAIL(n-1 , cnt+1);  
}

// NOT Tail recursive func
int fact(int n) {
    if(!n || n == 1) 
       return 1;

return n * fact(n-1);   // return(result) with recursive call together      
}

// TAIL 
int fact_TAIL(int n , int t = 1) {
  if(!n || n == 1) 
       return t;

    return  fact_TAIL(n - 1 , t*n); // the t is changed with new value as a passed parameter 
}

/*
   returnType func() {

        base caseS 1 or more
    body

    recursive call ->>>>>>>> *step* WITH AT LEAST CHANGE IN THE PARAMETER !!!! 
   }

*/

// 0 1 2 3 4 5 6  7
// 0 1 1 2 3 5 8 13

/*
start with the recursive step-call
    base cases  == no more sub-problems can be done






*/


int n_th_fibonacci(int n) {
    if(!n || n == 1)
        return n;
return n_th_fibonacci(n-1) +  n_th_fibonacci(n-2); 
}


int factorial_n(int n) {
    if(!n || n == 1)
        return 1;
return n * factorial_n(n-1);        
}

int sum_n(int n) {
    if(!n)
        return 0;

return sum_n(n-1) + n;   
}

// Time O(n) size  
// Aux Space Theta(n)
// by reference .. string copy
bool palindrome(string &s , int f , int e) {
     if(e == 0 || e == 1)       // - subtract  also empty or 1 char == palind.
        return true;
     if(s[f] != s[e])
         return false;  // BODY !

return palindrome(s , f+1 , e-1); // Recursive call step -- parameter changed
}


int sum_of_digits(int n) {
    if(!n)
        return 0;
return (n % 10) + sum_of_digits(n/10);  // as a total -- overview top      
} // two sub- problems

/*
dynamic programming

int rope_cutting(int n , int a , int b , int c) {


    if(n == 0)
        return 0;

    if(n < 0)
        return -1;

   
    if(a > 0)
        a = n - a;    
    if(b > 0)
        b = n - b;  
    if(c > 0)
        c = n - c;  


return 1 + rope_cutting(n , a , b , c);            
}
*/

void subsets(string &s , string cur = " " , int i = 0) {

}



int main(void) {  

/*
cout << factorial_n(0) << endl; 
cout << n_th_fibonacci(2) << endl; 
*/

//cout << sum_n(4) << endl; 
/*
 string s = "acbucau";
 int sz = s.size() - 1;

cout << palindrome(s , 0 , sz);
*/

//cout << sum_of_digits(9987);

//cout << rope_cutting(23 , 11 , 9 , 12);










//func(5);
// cout << log_base_2(19);

// decimal_to_binary(11); // 10 5 2 1
                          // 1 0  1 0 

/*
print_n_to_1(10);
cout << endl;
print_1_to_n(10);
cout << endl;
print_1_to_n_TAIL(10);
cout << endl;
*/
/*
cout << fact(6) << endl;
cout << fact_TAIL(6) << endl;
*/

// Auxiliary Space -- extra temporary space  .... recursion calls
// different from SPACE complexity ... (containers to store) ... vs in-place 
// 0 1 2 3 4 5 6 7    8   9
// 0 1 1 2 3 5 8 13  21   34 

//cout << fib(100) << endl; 

/*
cout << fib(10) << endl;   
cout << fib_array(10) << endl; 
cout << fib_optimal_variables(10) << endl; 
*/
cout << "\nBye\n";
    return 0;
} 