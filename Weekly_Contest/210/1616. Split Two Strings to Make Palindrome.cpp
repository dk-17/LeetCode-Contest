class Solution {
public:
    
    bool ispalindrome(string& s,int i,int j){
        while(i<j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    bool check(string& a,string& b){
        for(int i =0, j = b.length() - 1 ; i<j ;i++,j--){
            if(a[i] != b[j])
                return ispalindrome(a,i,j) || ispalindrome(b,i,j);
        }
        return true;
    }
    
    bool checkPalindromeFormation(string a, string b) {
        return check(a,b) || check(b,a);
        
    }
};
