#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <stdexcept>
#include <algorithm>  // for max_element
using namespace std;

// Move function outside main
void isAllNegatif(vector<vector<int>>& p, int n, int m) {
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(p[i][j] > 0){  // If any positive number found
                return;  // Not all negative
            }
        }
    }
    cout << -1 << endl;  // All numbers are negative
}

int main() {
    int n, m, x;
    cout << "enter please how many cols and rows you want to have within the matrix, n rows and m cols: " << endl;
    cin >> n; //rows
    cin >> m; //cols

    // Use vector instead of VLA for better portability
    vector<vector<int>> p(n, vector<int>(m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << "enter an element: " << endl;
            cin >> x;
            p[i][j] = x;
        }
    }

    // Check if all negative
    isAllNegatif(p, n, m);

    // Fix: initialize with 1 for multiplication
    int s = 1;
    int k = 1;

    // Fix: use j++ not i++
    for(int j=0; j<m; j++){
        s *= p[0][j];
    }

    for(int i=0; i<n; i++){
        k *= p[i][m-1];
    }
    k *= s;

    vector<int> T;
    T.push_back(k);

    // Fix loop bounds and logic
    for(int j=m-1; j>=1; j--){  // Decrement, not increment
        for(int i=0; i<=n-2; i++){
            if(i < T.size() && j >= 0) {  // Add bounds checking
                T.push_back((T[i] / p[i][j]) * p[i+1][j-1]);
                p[i][j] = p[i+1][j-1];
            }
        }
    }

    cout << T.size() << endl;  // size of the vector

    for (size_t i=0; i<T.size(); i++){
        cout << T[i] << endl;
    }

    // Use a different variable name to avoid conflict
    int maxVal = T[0];
    for(size_t i=0; i<T.size(); i++){
        if(maxVal <= T[i]){
            maxVal = T[i];
        }
    }

    // Alternative using algorithm
    // int maxVal = *max_element(T.begin(), T.end());

    return 0;
}
