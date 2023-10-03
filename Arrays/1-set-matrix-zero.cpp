/*
https://leetcode.com/problems/set-matrix-zeroes/

Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

Simple approach is to keep track of which rows and cols had 0's

vector<bool>row0(rows,false);
vector<bool>col0(cols,false);

to reduce space complexity use the first row and column as marker
 i.e. mark the vlaue as 0 if 0 is seen in given row/column

 How can we overwrite? dont we lose value --> no because we have to overwrite it as per ask in question eventually
 so whatever value it was .. was of no use


 martix[0][0] --> for what this value should be used row or column?
 use it for row and use another valriable to track col0

*/

#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int rows  = matrix.size();
        int cols  = matrix[0].size();

        // vector<bool>row0(rows,false);
        // vector<bool>col0(cols,false);
        
        // for(int i=0;i<rows;i++){
        //     for(int j=0;j<cols;j++){
        //         if(matrix[i][j] == 0){
        //             row0[i]=true;
        //             col0[j]=true;
        //         }
        //     }
        // }


        // for(int i=0;i<rows;i++){
        //     for(int j=0;j<cols;j++){
        //         if(row0[i]==true || col0[j]==true){
        //             matrix[i][j] =0;
        //         }
        //     }
        // }

        bool col0 = false;

        //use first row/col value to identify
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){

                if(matrix[i][j] == 0){

                    matrix[i][0] = 0;

                    if(j==0){
                        col0 = true;
                    }

                    else{

                        matrix[0][j] = 0;

                    }

                }

            }

        }


        //first row and col are markers fill them at last
        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){

                if(matrix[i][0] == 0 || matrix[0][j]== 0){
                    matrix[i][j] = 0;
                }
                

            }

        }

        //first row and column remaining
        if (matrix[0][0] == 0) {
            for (int j = 0; j < cols; j++) {
                matrix[0][j] = 0;
            }
        }
        if (col0 == true) {
            for (int i = 0; i < rows; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};