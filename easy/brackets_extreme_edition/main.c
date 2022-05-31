#include <stdio.h>

int main() {
  int i = 0;
  int j = -1;
  int s = 1;
  char expression[2049];
  char temp[1025];
  scanf("%s", expression);
  while (expression[i] != '\0' && s && j<1024) {
    if (expression[i] == '(') {
      j++;
      temp[j] = ')';
    } else if (expression[i] == '[') {
      j++;
      temp[j] = ']';
    } else if (expression[i] == '{') {
      j++;
      temp[j] = '}';
    } else if (expression[i] == ')' || expression[i] == ']' ||
               expression[i] == '}') {
      if (expression[i] == temp[j]) {
        j--;
      } else {
        s = 0;
      }
    }
    i++;
  }
  (s && j < 0) ? printf("true") : printf("false");
  return 0;
}
