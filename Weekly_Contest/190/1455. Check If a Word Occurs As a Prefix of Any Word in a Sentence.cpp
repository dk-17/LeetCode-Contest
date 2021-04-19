class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream s(sentence);
        string word;
        int count = 0;
        while(s >> word){
            count++;
            int index = word.find(searchWord);
            if( index == 0 ){
                return count;
            }
        }
        return -1;
        
    }
};

// another way to implement!
#include<bits/stdc++.h>
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchword) 
    {
        stringstream s(sentence);
        string word;
        int count=0;
        int len=0;
        int flag=0;
        while(s>>word)
        {
            count++;
            int i=0;
            len=0;
            while(i<searchword.length())
            {
                if(word[i]==searchword[i])
                    len++;
                else {
                    flag=1;
                    break;
                }
                i++;
            }
            
            if(len==searchword.length())
                return count;
        }
        
        return -1;
        
    }
};
