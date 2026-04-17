//zigzag conversion
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;
//explain the algorithm
/*
 1- enter a string
 2- send the size
 3- create a matrix
 4- devide the string on rows not on the columns tab[i][fix]='char'
 5- the second column : one string , if i chooe three chars in one col so is gonna ba tab[1]='char', and so on (loop)
 6- th case if we have just a char
*/
int main(){
    string str;
    cout << "enter a string " << endl;
    getline(cin, str);
    int x= str.size()-3;
    char tab[3][x];
    int index=0;
for (int j = 0; j < x && index < (int)str.size(); j++) {
    if (j % 2 == 0) {
        for (int i = 0; i < 3; i++)
            if (index < (int)str.size())
                tab[i][j] = str[index++];
            else
                tab[i][j] = '\0';
    } else {
        tab[0][j] = '\0';
        if (index < (int)str.size())
            tab[1][j] = str[index++];
        else
            tab[1][j] = '\0';
        tab[2][j] = '\0';
    }
}
    //finish :showing the new string
    for (int i=0; i<3; i++){
        for(int j=0; j<x; j++){
            if(tab[i][j]=='\0'){continue;}
            cout << tab[i][j] ;

        }
    }
    return 0;
}
