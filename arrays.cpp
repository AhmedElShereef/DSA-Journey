using namespace std;
#include<math.h>
#include<vector>
#include<iostream>
#include<algorithm>



void one_left_rotate(vector<int> &arr) {
    int sz = (int) arr.size();

    int f = arr[0];
    for(int i = 1; i < sz; i++)
        arr[i-1] = arr[i];

    arr[sz - 1] = f;
}

// O(n*d) // Space O(1)   
void d_left_rotations(vector<int> &arr , int d) {

    while(d--)
        one_left_rotate(arr);

}

// rotations <= size
// effective rotations == rotations % size
void d_left_rotations_extra_space(vector<int> &arr , int d) {


int sz = (int) arr.size() ;
int effective_d = d % sz;

vector<int> rotated_arr;

for(int i = effective_d; i < sz ;i++) 
    rotated_arr.push_back(arr[i]);


for(int i = 0; i < effective_d; i++)
    rotated_arr.push_back(arr[i]);



for(int i = 0; i < sz; i++)
    arr[i] = rotated_arr[i];

}


int main() {


vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(-50);

    sort(vec.begin() , vec.end());

        
/*
    cout << "Before rotation \n";
    for(auto s : vec) 
        cout << s << " ";



    //one_left_rotate(vec);

   // d_left_rotations(vec , 3);

     cout << "\n-------------------------\n";

    d_left_rotations_extra_space(vec , 77);

   // cout << "-------------------------";


    cout << "After rotation \n";
    for(auto s : vec) 
        cout << s << " ";

*/
/*
    int s = 6.0;
    double c = 2.0;

    cout <<  c / s;

*/

/*
vector<int> freqArr(7,0);
    freqArr[1] = 888;
 for(auto s : freqArr) 
        cout << s << " ";

    auto x =  max_element(freqArr.begin() , freqArr.end());
    cout << *x;

*/
    /*
    string s = "ahmed";
    string f = "ahmd";
    //sort(s.begin() , s.end() );


    int s_total { } , f_total{ };

   for(auto &x : s)
            s_total += (int)x;

    for(auto &x : f)
            f_total += (int)x;       

          cout << (char) (s_total-f_total)<< endl;   

*/

/*
    cout << (int)"++X" << endl;
    cout << (int)"--X";
*/


/*
    if(4 == 4 && 4 == 4)
        cout << "yes";
*/


/*
vector<int> arr(10);
cout << arr.size();
*/



/*


vector<int> v;
v.push_back(10);
v.push_back(20);
v.push_back(30);


    for(int s : v)
        cout << s << " ";



    v.insert(v.begin(),555);

for(int s : v)  
        cout << s << " ";
*/
   // cout << abs(5-10);
    
    

    vector<int> v;
    
v.push_back(10);
v.push_back(20);
v.push_back(30);



    cout << v.size() << endl;

    auto  it = max_element(v.begin(),v.end());

     v.erase(it);

  for(auto & s : v)
    cout << s << " ";


    cout << *it << endl;


    return 0;
}       