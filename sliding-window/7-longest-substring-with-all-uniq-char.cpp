#include<vector>
#include<iostream>
#include<map>
#include<string>
using namespace std;

int lengthOfLongestSubstring(string s) {

    unordered_map<char,int> char_map;

    int i=0, j=0;
    int maxlen=0;

    //same as earlier only diff is k is wondow size i.e. j-i+1
    while(j<s.size()){

        char current_char = s[j];

        char_map[current_char]++;

        //comapre with win size
        if(char_map.size()==(j-i+1)){
            if(maxlen < (j-i+1)){
                maxlen = (j-i+1);
            }
            
        }
        if(char_map.size()<(j-i+1)){
            //there is some duplicate char

            while(char_map.size()<(j-i+1)){

                char_map[s[i]]--;
                if(char_map[s[i]]==0){
                    char_map.erase(s[i]);
                }

                i++;

            }



        }

        j++;

    }
    
    return maxlen;
}