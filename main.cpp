#include <iostream>
#include <cstring>
#include "stack.h"

int main(int argc, char* argv[]) {
  if (argc > 1) {
    for (int i = 1; i < argc; i++) {
      int copen = 0;
      int cclose = 0;
      std::string expression = argv[i];
      bool equal = false;
      Stack stack;

      for (char c : expression) {
        if (c == '(' || c == '[' || c == '{') {
          stack.push(c);
          copen++;
        } else if (c == ')' || c == ']' || c == '}') {
          char open = stack.get_top();
          if (stack.empt()) {
            if ((open == '(' && c == ')') ||
                (open == '[' && c == ']') ||
                (open == '{' && c == '}')) {
              cclose++; 
              
              continue;
            }
          }
          stack.pop();
          copen--;
        }
      }

      if (stack.empt() && copen == 0 && cclose == 0) {
        equal = true;
      }

      if (equal) {
        std::cout << "Match" << std::endl;
      } else if (copen > cclose) {
        std::cout << "Too many open" << std::endl;
      } else if (cclose > copen) {
        std::cout << "Too many close" << std::endl;
      } else {
      }
    }
  }

  return 0;
}
