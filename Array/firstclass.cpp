// #include <iostream>
// #include <string>
// #include <math.h>

// using namespace std;


// int main() {
//     cout<<"Enter the value of X co-ordinate: ";
//     int x;
//     cin>>x;
//     cout<<"Enter the value of Y co-ordinate: ";
//     int y;
//     cin>>y;
//     int distance;
//     distance = sqrt((x*x)+(y*y));
//     cout<<"The distance between "<<x <<" and "<<y<<" is "<< distance;
//     return 0;
// }


/*A new program to see how pointers work*/
#include <iostream>
using namespace std;

int main(){
    char ch = 'q';
    char* p = &ch;
    cout<<"Initial Values."<<endl;
    cout<<ch<<endl<<*p<<endl;
     ch = 'z';
    cout<<"When ch is changed form q to z"<<endl;
    cout<<ch<<endl<<*p<<endl;
    *p = 'a';
    cout<<"When pointer is changed form z to a"<<endl;
    cout<<ch<<endl<<*p<<endl;
}
