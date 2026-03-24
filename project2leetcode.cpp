#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <stdexcept>
#include <vector>
using namespace std;

int main(){

//build the matrix 2D grid
int n=0,m=0;
int x;
cout << "hello we have new challenge and we need to overcome " <<endl;
cout << "please enter your following information the number of rows at first and then the number of cols: " << endl;
cin >> n;
cin >> m;
int grid[n][m];
for (int i=0 ; i<n; i++){
    for(int j=0 ; j<m; j++){
        cin >> x;
        grid[i][j] = x;
    }
}
int s=1;
//calcul the product
for(int i=0 ; i<n; i++){
    for(int j=0 ; j<m; j++){
        s*= grid[i][j];
    }
}
//display the vector
vector<vector <int> > p(n, vector<int>(m));
try{
for(int i=0 ; i<n; i++){
    for(int j=0 ; j<m; j++){
        if(grid[i][j]==0){
        throw logic_error("cannot divide by zero");}
        p[i][j] =  s/grid[i][j];//devision by zero
    }
}
}
catch(const logic_error & e){
    cout << e.what () << " we cannot devide by zero " <<endl;
    return 0 ;
}

   cout << "here the product matrix of grid: " <<endl;
   cout << "the grid matrix is: " << endl;
   for(int i=0; i<n; i++ ){
    for(int j=0; j<m; j++){
      cout <<  grid[i][j]  << "  " ;
    }
   }
   cout << "\n" ;
   cout << "the product matrix is: " << endl;
   for(int i=0; i<n; i++){
    for(int j=0; j<m ; j++){
        cout << p[i][j]<< " ";
   }
   }
    return 0;
}

