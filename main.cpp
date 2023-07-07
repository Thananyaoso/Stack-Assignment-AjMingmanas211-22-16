#include <iostream>
#include <iomanip>

using namespace std;

#include "stack.h"
#include <cstring>

int main(int argc, char *argv[]) {
  Stack s;
  int match;
  char c;
  for(int i = 1; i < argc; i++){
    match = 0;
    for(int j = 0; j < strlen(argv[i]); j++){
    switch(argv[i][j]){
      case '{' :
        s.push(argv[i][j]);
        match++;
        break;
      case '[' :
        s.push(argv[i][j]);
        match++;
        break;
      case '}' :
        c = s.pop();
        match--;
        break;
      case ']' :
        c = s.pop();
        match--;
        break;
    }
  }
      cout << ((argv[i][strlen(argv[i]) - 1] == '[' 
      || argv[i][strlen(argv[i]) - 1] == '{') ? "Not matched :(" :
      (match == 0) ? "Matched!!" :
      (match > 0) ? "Too many opens!!" : "Too many closes!!") << "\n";
  }
    return 0;
}