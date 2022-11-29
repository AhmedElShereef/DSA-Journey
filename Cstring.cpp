using namespace std;
#include<math.h>
#include<vector>
#include<iostream>

#include<cstring>




#include<string>    


int main() {


// #include<cstring>
// C-Style String 
// Cstring          array of chars
    char str [ ] = "zgh";
    int i = 0;
    int sz { };
        while(str[i] != '\0') {
            i++;
            sz++;

        }
  //  cout << sz << endl;
 //   cout << sizeof(str) << endl; // for the \0


cout << "---------------------------\n";

    char str_single_quotes [ ] {'a','h','m' , '\0'}; // we must put it here 
    int ii = 0;
    int szz { };
        while(str_single_quotes[ii] != '\0') {
            ii++;
            szz++;

        }
 //   cout << szz << endl;
//    cout << sizeof(str_single_quotes) << endl; // for the \0

//-----------------------------------------------------

// #include<cstring>

// length-size   
//cout << strlen(str_single_quotes)<< endl; 

    char a[] = "aya", b []= "abv";
    int res = strcmp(a , b);

if( res > 0)
 cout << "Greater "<< endl;
else if(res  == 0)
         cout << "Same "<< endl;
else    // -1
        cout << "Smaller "<< endl;




// copy -- assign a string to array of chars
char arr[15];
strcpy(arr,"kokowawa");

//cout << arr[5]; // the string is assign-ed to the array










        cout << "\nBYE";
    return 0;
}


/*
    string s =  "geeksforgeeks";

    int freq[26] = {0};

    // 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 
    // a b c d e f g h j k l m n o p q.....
    for(int i = 0; i < s.size(); i++) {
        freq[s[i] - 'a']++;
    }

/*
    for(int i = 0; i < 26; i++) {
       cout << freq[i] << " ";
    }
*/

/*
  for(int i = 0; i < 26; i++) {
       if(freq[i] > 0) {
        cout << (char)(i + 97) << " " << freq[i];
           cout << endl;}

    }
*/

/*

string s {"ahmed"};
string b  {"med"};


    cout << (int)s[0] << endl;

    */

/*
int i = s.find(b);

cout<<i<<endl;
    */

// string c = b + s;

// cout << c << endl;
//getline(cin,s);


//cout << s << endl; 
//cout << s << " " << b << endl; 

/*

char arr [50];
cin >> arr ;

for(char &c : arr)
    cout << c ;
*/