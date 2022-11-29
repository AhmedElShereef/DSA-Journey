using namespace std;
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

bool isLessAbs(int a, int b){
  return std::abs(a) < std::abs(b);

} 
int main() {

  std::cout << std::boolalpha << std::endl;

  vector<int> vec{-3, 0, -3, 2, -3, 5, -3, 7, -0, 6, -3, 5, -6, 8, 9, 0, 8, 7, -7, 8, 9, -6, 3, -3, 2};
 
sort(vec.begin(), vec.end() , isLessAbs);

  for (const int& v: vec ) std::cout << v << " ";

    cout << endl;
   cout << binary_search(vec.begin(),vec.end(), 2 , isLessAbs); 
    cout << endl;
   auto it = lower_bound(vec.begin(),vec.end(),3,isLessAbs);
   auto itt = upper_bound(vec.begin(),vec.end(),3,isLessAbs);


     cout << distance(vec.begin() , it) << endl;;
     cout << distance(vec.begin() , itt)-1;

 //  cout << "\nfirst occurance  "<< it ;
 //  cout << "\nlast occurance  "<< itt;

    auto pair = equal_range(vec.begin(),vec.end(),8,isLessAbs);
   cout << "\nfirst occurance  "<< pair.first - vec.begin();
   cout << "\nlast occurance  "<< pair.second - vec.begin()-1;

    return 0;
}