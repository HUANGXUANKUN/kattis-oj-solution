#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  //freopen("in.txt", "r", stdin);
  string temp_log;
  int period_count = 0;
  vector<string> print;
  
    while (!cin.eof())
    {
	 getline(cin,temp_log);
	 if (temp_log == "")
	 {
	 	print.push_back("");
	 	period_count = 0;
 	 }
	 else
	 {				   			  	 	
   	 int temp_count = 0;
	 for (int x = 0; x < temp_log.size(); x ++)
	  {
	  	if (temp_log.at(x) == '*')
	  	{
	  		temp_count = temp_count + 1;
			period_count = period_count + 1;	  		
		}
	  }
	 string temp_string;
	 for (int a = 0; a < temp_log.size() - period_count; a++)
	  {
	  	temp_string.push_back('.');
	  }
	 for (int b = 0; b < temp_count; b++)
	  {
	  	temp_string.push_back('*');
	  }
	 for (int c = 0; c < period_count - temp_count; c++)
	  {
	  	temp_string.push_back('.');
	  }
	 print.push_back(temp_string);
     }
   }  
    
    for (int d = 0; d < print.size(); d++)
    {
   	    cout << print.at(d) << endl;
    }

}
