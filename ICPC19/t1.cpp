#include <iostream>
#include <string>

using namespace std;

string solution(string T) {
  // Your solution goes here.
  string s=T;
  
  // Hours place
  if(s[1]=='?' && s[0]=='?'){
      s[0]='2';
      s[1]='3';
  }
  else if(s[0]=='?'){
      if(s[1]-'0'>3)s[0]='1';
      else s[0]='2';
  }
  else if(s[1]=='?'){
      if(s[0]=='2')s[1]='3';
      else s[1]='9';
  }

  // Minutes place 

  if(s[3]=='?')s[3]='5';
  if(s[4]=='?')s[4]='9';
  return s;
}

int main() {
  // Read from stdin, solve the problem, write answer to stdout.
  string input;
  cin >> input;
  cout << solution(input);
}
