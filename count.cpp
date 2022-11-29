using namespace std;
#include<math.h>
#include<vector>
#include<iostream>
#include<algorithm>

    void countSort(vector<int> &v , int sz ,int f_sz) {

        //{ 5 , 6 , 5 , 2}
           
        vector<int> cnt(f_sz,0);
        // {0 , 1 , 2 , 3 , 4 , 5 ,6}
        // {0 , 0 , 1 , 0 , 0 , 2 ,1}    
        for(int i = 0; i < sz; i++) // frequency
            cnt[v[i]]++;


       
        
        // num of elements PRESENTED smaller or equal  i // to be added - actual array
        //   0   1   2   3
         //{ 5 , 6 , 5 , 2}

         //  0   1   2   3   
         //  2   5   5   6


        // {0 , 1 , 2 , 3 , 4 , 5 ,6}

        // {0 , 0 , 1 , 0 , 0 , 2 ,1}   

        // 5    6    5    2   << from back
    // position 1-indexed    
        // {0 , 0 , 1 , 1 , 1 , 3 ,4}            
         for(int i = 1; i < f_sz; i++) 
            cnt[i] = cnt[i] + cnt[i-1];  // cumulatice sum

        vector<int> result(sz,0);

        for(int i = sz-1; i >= 0; i--) {
            result[ cnt[v[i]] - 1] =  v[i]; 
            cnt[v[i]]--;
        }    

       for(int i = 0; i < sz; i++)  
                v[i] = result[i];
            
    }







int main() {

// count sort
    vector<int> v;
    v.push_back(1);
    v.push_back(4);
    v.push_back(4);
    v.push_back(1);
    v.push_back(0);
    v.push_back(1);
   // v.push_back(1);

/*
    vector<int> cnt(5);

    for(int &n : v)
        cnt[n]++;

*/

    for(int &n : v)
        cout << n << " ";

    
    cout << endl;

    countSort(v,6,5);

  for(int &n : v)
        cout << n << " ";


/*
    for(int &n : cnt) {
        if(n == 0) continue;
     cout << n << " ";
    }
*/
    

    // O(N + K) n + freq
/*
     int index { };   
     for(int i = 0; i < v.size(); i++) {

            for(int j = 0; j < cnt[i]; j++) {
                    v[index] = i;
                    index++;
            }
     }


*/



/*
int c = 5;

if(c == 4) cout << "es";

else if(c == 5) cout << " ess ";

*/

    cout << "\nBye \n";

    return 0;
}