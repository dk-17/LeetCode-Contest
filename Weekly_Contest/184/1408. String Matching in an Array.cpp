vector<string > ans;
unordered_map<string,int> umap;
using namespace std;
 bool compare(string a,string b)
    {
        return a.length()>b.length();
    }
class Solution {
public:
    void compute_lps(string pattern,int m,int *lps)
{
  lps[0]=0;
  int i=1;
  int j=0;
  while(i<m)
  {
    if(pattern[i]==pattern[j])
    {
      lps[i]=j+1;
      i++;
      j++;
    }
    else if(pattern[i]!=pattern[j])
    {
      if(j!=0)
      {
        j=lps[j-1];
      }
      else
      {
        lps[i]=0;
        i++;
      }
    }
  }
}
    void kmpsearch(string text,string pattern)
{
  int m=pattern.length();
  int n=text.length();
  int lps[m];
  memset(lps,0,sizeof(m));

  compute_lps(pattern,m,lps);
  int j=0;
  int i=0;
  while(i<n)
  {
    if(text[i]==pattern[j])       //i = 3, j = 3///prefer gfg
   {                       //txt[] = "AAAAABAAABA"
       i++;                //pat[] = "AAAA"
      j++;                 //txt[i] and pat[j] match, do i++, j++
    }                      //i = 4, j = 4
    if(j==m)               //Since j == M, print pattern found and reset j, //j = lps[j-1] = lps[3] = 3
    {
        string temp=text.substr(i-j,m);
        if(umap[temp]==0)
        {
            umap[temp]++;
            ans.emplace_back(temp);
        }//i-j beacuse to store the index from the point where paterrn match with text!
      j=lps[j-1];
    }
    else if(pattern[j]!=text[i])
      {
        if(j!=0)
          j=lps[j-1];
          else
          i++;

      }
  }
}
   
    vector<string> stringMatching(vector<string>& words)
    {
        ans.clear();
        umap.clear();
        sort(words.begin(),words.end(),compare);
       /* for(int i=0;i<words.size();i++)
        {
            cout<<words[i]<<" ";
        }*/
        for(int i=0;i<words.size();i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                kmpsearch(words[i],words[j]);
            }
        }
        
        return ans;
        
    }
};
