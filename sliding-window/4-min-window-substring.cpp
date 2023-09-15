/*
https://www.interviewbit.com/problems/window-string/

Problem Description
 
 

Given a string A and a string B, find the window with minimum length in A, which will contain all the characters in B in linear time complexity.
 Note that when the count of a character c in B is x, then the count of c in the minimum window in A should be at least x.

Note:

If there is no such window in A that covers all characters in B, return the empty string.
If there are multiple such windows, return the first occurring minimum window ( with minimum start index and length )


*/

#include<vector>
#include<map>
#include<string>
#include<iostream>
#include<queue>
using namespace std;


string minWindow(string A, string B) {
    
    //return if either string is empty
    if(A.empty() || B.empty())
        return "";
 
    //get freq map from B to get
    //use unordered map (space efficient)
    unordered_map<char,int> char_map;
    
    for(char c: B){
        char_map[c]++;
    }
    
    //positive value in char_map indicates those many occurences are still req for valid window
    //e.g. 2 --> we still need 2
    //negative indicates excess of the given char
    //e.g. -2 means we have this char in excess of 2
    // 0 means we have exact count as required
    
    //window
    int left =0;// right =0;
    
    //matchcount i.e how many char matched till now (should be equal to B.size)   
    int matchcount =0;
    
    //best window found till now
    int minWindowLength =INT_MAX; 
    
    //answer i.e. substring
    string result ="";
    
    for(int right =0;right<A.length();right++){
        
        char currentChar = A[right];
        
        //oonly if it is present in B 
        if(char_map.find(currentChar) != char_map.end()){
            //decrease the freq in map
            char_map[currentChar]--;
            //if we found req occurences (not excess) then reduce matchcount
            if(char_map[currentChar] >= 0){
                matchcount++;
            }
        }
        
        //check if we have found valid window, if so (update ans and) shrink it till it becomes invalid
        while(matchcount == B.length()){
            
            //current win size is right-left+1
            if((right-left+1)<minWindowLength){
                minWindowLength = right-left+1;
                result = A.substr(left,minWindowLength);
                
            }
            
            //shrink
            char leftmostchar = A[left];
            //is the leftmostchar part of B then update map and check validity of win
            if(char_map.find(leftmostchar)!=char_map.end()){
                //update map
                char_map[leftmostchar]++;
                //do we have sufficient of leftmostchar
                if(char_map[leftmostchar] > 0){
                    matchcount--;
                }
            }
            
            //we have updated map and matcount lets shift /shrink window
            left++;
            
        }
        
    }
    
    return result;
}
