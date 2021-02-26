class Solution {
public:
    bool halvesAreAlike(string a) {
        int left_vowel=0,right_vowel=0;
        for(int i=0;i<a.length()/2;i++){
            if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')
                left_vowel++;
            if(a[i]=='A'||a[i]=='E'||a[i]=='I'||a[i]=='O'||a[i]=='U')
                left_vowel++;
        }
        
        for(int i=a.length()/2;i<a.length();i++){
            if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')
                right_vowel++;
            if(a[i]=='A'||a[i]=='E'||a[i]=='I'||a[i]=='O'||a[i]=='U')
                right_vowel++;
        }
        if(left_vowel==right_vowel)
            return true;
        return false;
        
    }
};
