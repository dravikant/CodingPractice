// https://leetcode.com/problems/find-all-anagrams-in-a-string
// Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 



#include<vector>
#include<map>
#include<string>
#include<iostream>
using namespace std;
vector<int> findAnagrams(string s, string p) {

    vector<int> ans;

    int win_size = p.length();

    int str_len = s.length();

    if(win_size > str_len){
        return ans;
    }

    //map size: uniq char count as keys
    //value : freq of each char
    //+value -- how many req
    //-value -- how many in excess
    //0 -- req count match
    unordered_map<char,int> char_map;

    //get freq of each char from pattern
    for(int i=0;i<win_size;i++){
        char_map[p[i]]++;
    }
    // how many matches found
    // increment only when map value reached 0
    //condition match_count == char_map.size()
    int match_count =0;

    for(int i=0;i<win_size;i++){
        //check if it is in pattern
        if(char_map.find(s[i])!=char_map.end()){
            char_map[s[i]]--;

            //req freq count met Increase match count
            if(char_map[s[i]] == 0){
                match_count++;
            }
        }
        
    }
    //for first window
      if(match_count == char_map.size()){
            ans.push_back(0);
        }
    
    //debugging
    unordered_map<char,int>::iterator it;

    for(it=char_map.begin();it!=char_map.end();it++){
                std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;

    }

    //expand win.. i is end pointer should iterate till end

    for(int i=win_size;i<str_len ;i++){

        cout<<s[i]<<endl;

        //remove first char
        int first_char_idx = i - win_size;
        if(char_map.find(s[first_char_idx])!=char_map.end()){

                //if req was satisfied, decrease match count as we are removing it
            if(char_map[s[first_char_idx]] == 0){
                match_count--;
            }
            
            char_map[s[i-win_size]]++;

            
        }

        //add next xhar
        if(char_map.find(s[i])!=char_map.end()){
            
            
            char_map[s[i]]--;
            //check if req met
            if(char_map[s[i]] == 0){
                match_count++;
            }
            
        }

        //debug
        unordered_map<char,int>::iterator it;

        for(it=char_map.begin();it!=char_map.end();it++){
                    std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;

        }

        //check if match
         if(match_count == char_map.size()){
                ans.push_back(i-win_size+1);
            }
        
    }

    
    return ans;
}

int main(){
   vector<int> result = findAnagrams("baa", "aa");
    for (int idx : result) {
        cout << idx << " ";
    }
    cout << endl;
    return 0;
}