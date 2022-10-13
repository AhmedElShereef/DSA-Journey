#include <iostream>
#include <cassert>

#include <vector>
#include <queue>
#include <stack>

#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;





int sum(int num) {  // 1-num    power-ed 3
    int result { };

    for(int i = 1; i <= num; i++)
        result+= i * i * i;
    return result;
}

long fib(int n) {

    if(n <= 2)
        return 1;
    else
        return fib(n-1) + fib(n-2);    
}

int maxSubSum1(const vector<int> &a) {
    int maxSum { };

        for(int i = 0; i < a.size(); i++) 

            for(int j = i; j < a.size(); j++) {
                int currSum { };

                for(int k = i; k <= j; k++)
                    currSum += a[k];

                if(currSum > maxSum)
                    maxSum = currSum;    
            }



    return maxSum;
        
}

int maxSubSum2(const vector<int> &a) {
    int maxSum { };

        for(int i = 0; i < a.size(); i++) {
            int currSum { };

            for(int j = i; j < a.size(); j++) {

              currSum += a[j];
              if(currSum > maxSum)
                    maxSum = currSum;         
            }
    }

    return maxSum;
        
}

int maxSubSum3(const vector<int> &a) {
    int maxSum { }, currSum { };


        for(int j = 0; j < a.size(); j++) {
                currSum += a[j];
            
                if(currSum > maxSum)
                    maxSum = currSum;
                else if(currSum < 0)
                    currSum = 0;    

            }
    

    return maxSum;
        
}

int binarySearch(const vector<int> &a , const int &item) {  // O(LogN)
    int low = 0 , high = a.size() - 1;

        while (low <= high)
        {
            int mid = (low + high) /2;

            if(a[mid] < item)
                low = mid + 1;
            else if(a[mid] > item)
                high = mid - 1;
            else
                return mid;    
        }

        return  -1;
        
}


long long gcd(int m , int n) {
        
    while(n != 0) {

        long long rem = m % n;
        m = n;
        n = rem;
    }

    return m;
}

void selection_sort(vector<int>& items) {
    int siz = (int)items.size();
    int min { };
    for(int i = 0; i < siz; i++) {
        	min = i;
            for(int j = i+1; j < siz; j++) {
                if(items[min] > items[j])
                    min = j;
            }
        swap(items[i],items[min]);    
    }
}
void insertion_sort(vector<int>& items) {
   int siz = (int)items.size();
    int j { };
    int i { };
    for( i = 1; i < siz; i++) {
        j = i;

        while (j > 0 && items[j] < items[j - 1])
        {   
                swap(items[j] ,items[j - 1]);
                j = j - 1;
        }
        
    }

}

int findMatch(string article , string name) {
    int i ,j;
    int aLen = article.length() , nLen = name.length();

    for(i = 0; i <=(aLen - nLen); i++){
        j = 0;
            while((j < nLen) && name[j] == article[i + j]) 
                j = j + 1;
            
            if(j == nLen)
                return i;
    }
    return -1;
}

int main() {

   // cout << sum(3) << endl;

   //  cout << fib(2) << endl;

    vector<int> nums {-4,-3,5,-2,-1,2,6,-2};
/*
    cout << maxSubSum1(nums) << endl;
   
    cout << maxSubSum2(nums) << endl;

    cout << maxSubSum3(nums) << endl;
*/
    
 //   sort(nums.begin() , nums.end());
 //   cout << binarySearch(nums , 6);
   
//   cout << gcd(1989,1590) << endl;

   
   
//    cout << pow(2,3);

 //   cout << "\n bye \n";
/*
    vector<int> x {1000,7,5,3,6,0,-8,2};
   // selection_sort(x);
    insertion_sort(x);

        for(auto num : x) 
            cout << num << " ";
*/

/*
    string art = "ahmedibrahassan" , me = "ibra";
    int index = findMatch(art , me);

 
    cout << art[index];
    cout << art[index+1];
    cout << art[index+2];
    cout << art[index+3];


   // int sz = me.length();

    for(int i = index; i < art.length() - index - 1; i++) 
        cout << art[i];
    
*/


return -1;
}