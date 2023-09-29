#include<vector>
#include<iostream>
#include<iomanip>
using namespace std;

int main(){

    int n =4;

    for(int gap =1; gap < n; gap ++){

        for(int row =0, col =gap; row < n-gap; row++,col++){

            cout<<setw(5)<<row<<","<<col;

        }
            cout<<endl;
    }


}