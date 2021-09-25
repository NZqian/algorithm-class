//no space at each line of output;
#include <iostream>
#include <string>

using namespace std;

void push(string& left, string& right, string& cur, string& ans);
void reverse_push(string& left, string& right, string& cur, string& ans);
void pop(string& left, string& right, string& cur, string& ans);
void reverse_pop(string& left, string& right, string& cur, string& ans);
void search(string in, string out, string& left,
    string& right, string& cur, string& ans);
bool check(string cur, string out);

int main()
{
  string in, out;    
  while(cin>>in>>out)
  {
    cout<<'['<<endl;
    string left, right=in, cur, ans;
    search(in, out, left, right, cur, ans);
    cout<<']'<<endl;
  }
}

void search(string in, string out, string& left,
    string& right, string& cur, string& ans)
{
  if(cur.size()==out.size())
  {
    if(cur==out)
    {
      int i;
      for(i=0; i<ans.size()-1; i++)
        cout<<ans[i]<<' ';
      cout<<ans[i]<<endl;
    }
    return ;
  }
  if(!left.size())
  {
    push(left, right, cur, ans);
    //cout<<"after push "<<left<<' '<<right<<' '<<cur<<' '<<ans<<endl;
    search(in, out, left, right, cur, ans);
    reverse_push(left, right, cur, ans);
  }
  else if(!right.size())
  {
    pop(left, right, cur, ans);
    //cout<<"after pop "<<left<<' '<<right<<' '<<cur<<' '<<ans<<endl;
    if(cur.size()&&check(cur, out))
    {
      search(in, out, left, right, cur, ans);
    }
    reverse_pop(left, right, cur, ans);
  }
  else
  {
    push(left, right, cur, ans);
    //cout<<"after push "<<left<<' '<<right<<' '<<cur<<' '<<ans<<endl;
    search(in, out, left, right, cur, ans);
    reverse_push(left, right, cur, ans);

    pop(left, right, cur, ans);
    //cout<<"after pop "<<left<<' '<<right<<' '<<cur<<' '<<ans<<endl;
    if(cur.size()&&check(cur, out))
    {
      search(in, out, left, right, cur, ans);
    }
    reverse_pop(left, right, cur, ans);
  }
}

void push(string& left, string& right, string& cur, string& ans)
{
  char curchar=right[0];
  right.erase(right.begin());
  left.push_back(curchar);
  ans.push_back('i');
}

void reverse_push(string& left, string& right, string& cur, string& ans)
{
  char curchar = left[left.size()-1];
  left.erase(left.end()-1);
  right.insert(right.begin(),curchar);
  ans.erase(ans.end()-1);
}

void pop(string& left, string& right, string& cur, string& ans)
{
  char curchar = left[left.size()-1];
  left.erase(left.end()-1);
  cur.push_back(curchar);
  ans.push_back('o');
}

void reverse_pop(string& left, string& right, string& cur, string& ans)
{
  char curchar = cur[cur.size()-1];
  left.push_back(curchar);
  cur.erase(cur.end()-1);
  ans.erase(ans.end()-1);
}

bool check(string cur, string out)
{
  for(int i=0; i<cur.size(); i++)
    if(cur[i]!=out[i])
      return false;
  return true;
}
