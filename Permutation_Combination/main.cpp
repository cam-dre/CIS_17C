/* 
 * File:   main.cpp
 * Author: Cameron Perry
 * Created on March 27, 2018, 5:38 PM
 * Purpose: Compare Combination and Permutation
 */

#include <iostream>
#include <cstdlib>
#include<cmath>
#include <iomanip>
using namespace std;

int permuteNR(int, int); //Permutation without replacement
int combineR(int, int);  //Combination with replacement
int combineNR(int,int);  //Combination without replacement

int main(int argc, char** argv) {
    int nMin = 2, nMax = 9, permR, permNR, combR,combNR ;
    
    
    cout << "  N  M           P Rep          P no Rep          C Rep              C no Rep" << endl
         << "                  N^M           N!/(N-M)!    (N+M-1)!/(N)!(M-1)!    N!/(N-M)!M!" << endl << endl;
    
    for (int n = nMin; n <= nMax; n++) {
        for (int m = 0; m <= n; m++) {
            //Permutation with replacement
            permR = pow(n,m);
            permNR = permuteNR(n,m);
            combR = combineR(n,m);
            combNR = combineNR(n,m);
            
            cout << setw(3) << n << setw(3) << m
                 << setw(15) << permR << setw(15) << permNR
                 << setw(17) << combR << setw(20) << combNR << endl;
        }
        cout << endl << endl;
    }
    return 0;
}

//This function calculates permutation without replacement
int permuteNR(int n, int m) {
    int fact1 = 1;
    int fact2 = 1;
    //N!
    for(int i = 1; i <= n; i++){
        fact1 *= i;
    }
    //(N-M)!
    for(int i = 1; i <= (n-m); i++){
         fact2 *= i;
    }
    //N!/(N-M)!
    return fact1/fact2;
}

//This function calculates combination with replacement
int combineR(int n, int m) {
    int fact1 = 1;
    int fact2= 1;
    int fact3 = 1;
    //(N+M-1)!
    for(int i = 1; i <= (n+m-1); i++){
       fact1 *= i;
    }
    //N!
    for(int i = 1; i <= n; i++){
        fact2 *= i;
    }
    //(M-1)!
    for (int i = 1; i <= (m-1); i++) {
        fact3 *= i;
    }
    //(N+M-1)!/[(N)!(M-1)!]
    return fact1/(fact2 * fact3);
}

//This function calculates combination without replacement
int combineNR(int n, int m) {
    int fact1 = 1;
    int fact2= 1;
    int fact3 = 1;
    //N!
    for(int i = 1; i <= n; i++){
       fact1 *= i;
    }
    //(N-M)!
    for(int i = 1; i <= (n-m); i++){
        fact2 *= i;
    }
    //M!
    for (int i = 1; i <= m; i++) {
        fact3 *= i;
    }
    //N!/[(N-M)!M!]  
    return fact1/(fact2 * fact3);
}

