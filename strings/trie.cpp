#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
 
using namespace std;
 
int sz;
 
//char alphabet[27];
map<int, char> pr;
 
struct node 
{
 int next[26];
 bool end;
 int counter;
 int G;
}t[1000];
 
 
void add_str(string &s)
{
 int cur = 0;
 //cerr<<s<<endl;
 for(int i = 0; i < s.size(); i++)
 {
  int c = pr[s[i]];//s[i] - 97;
   
  if(t[cur].next[c] == -1)
  {
   sz++;
   memset(t[sz].next,-1,sizeof(t[sz].next));
   t[cur].next[c] = sz;
   t[sz].G = i + 1;
  }
   
  cur = t[cur].next[c];
  t[cur].counter++;
 }
 t[cur].end = true;
}
 
void printf()
{
 int cur = 0;
 for(cur = 0; cur < sz; cur++) 
 {
  for(int i = 0; i < t[cur].G; i++)
  {
   cout<<t[i].next + 97;
  }
  cout<<endl;
 }
}
 
 
int main()
{
 freopen("input.txt","r",stdin);
 freopen("output.txt","w",stdout);
 for(int i = 0; i < 26; i++)
 {                
  pr[char(i + 97)] = i; 
//  pr[i] = i + 97;
 }
 int n;
 cin>>n;
  
 memset(t[0].next,-1,sizeof(t[0].next));
  
 for(int i = 0; i < n; i++)
 {
  string s;
  cin>>s;
  add_str(s);
 }
 printf();
 
 return 0;
}