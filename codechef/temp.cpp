#include <iostream>
#include <vector>
using namespace std;
 
int main()
{


   // create a vector to store int
    vector<int> vec; 

   int i;

   // // display the original size of vec
   // cout << "vector size = " << vec.size() << endl;

   // // push 5 values into the vector
   for(i = 0; i < 5; i++){
      vec.push_back(i);
   }

   // cout << "vector size = " << vec[2] << endl;
   int a =1, b=2;
   cout << std::max(a,b);
   vec.erase(vec.begin()+2);
   // cout << "vector size = " << vec[2] << endl;
   // cout << "vector size = " << vec.size() << endl;
   // vector<vector<int> > v1;
   // v1.push_back(vec);
   // cout << v1.size() << endl;
   // for (int i = 0; i < v1.size(); ++i)
   // {
   //    for(int j=0; j<v1[0].size();j++){
   //       cout << v1[i][j]<< endl;
   //    }
   //    /* code */
   // }

   // for(vector<int>::iterator i = v1.begin(), i != v1.end(), i++){
      
   // }

   // // display extended size of vec
   // cout << "extended vector size = " << vec.size() << endl;

   // // access 5 values from the vector
   // for(i = 0; i < 5; i++){
   //    cout << "value of vec [" << i << "] = " << vec[i] << endl;
   // }

   // // use iterator to access the values
   // vector<int>::iterator v = vec.begin();
   // while( v != vec.end()) {
   //    cout << "value of v = " << *v << endl;
   //    v++;
   // }

   return 0;
}