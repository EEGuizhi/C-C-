
#include <iostream>
#include <string>
using namespace std;
int main() 
{
  int length;
  string s;
  string D;
  cout<<"��J�øѱK:";
  while (cin >> s)
  {
    length=s.length();
    for(int i=0;i<length;i++)
	{
      cout << char(s.at(i) - 2 );        
    }
    cout << endl;
	break;          
  }
  cout<<"��J�å[�K:";
  while (cin >> D)
  {
    length=D.length();
    for(int i=0;i<length;i++)
	{
      cout << char(D.at(i) + 2 );        
    }
    cout << endl;
	break;          
  }
  system("PAUSE");
  return 0;
}
	 

