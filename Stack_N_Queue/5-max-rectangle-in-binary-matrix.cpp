/*
Given a 2D binary matrix filled with 0’s and 1’s, find the largest rectangle containing all ones and return its area.

Bonus if you can solve it in O(n^2) or less.

Example :

A : [  1 1 1
       0 1 1
       1 0 0 
    ]

Output : 4 

As the max area rectangle is created by the 2x2 rectangle created by (0,1), (0,2), (1,1) and (1,2)

--> reduce the 2d array to m 1d arrays where m =  no of rows

e.g. solve for  [1 1 1]then [0 2 2] and [1 0 0]


also check 2d kadane
*/