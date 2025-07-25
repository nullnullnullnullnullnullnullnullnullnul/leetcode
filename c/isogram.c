// was not on leetcode
#include <stdio.h>

// 'a' = 97
// 'A' = 65
// 'a' - 32 = 'A'
// 'A' + 32 = 'a'
int isogram(char *s)
{
  if (s[0] == '\0') return 0; // empty string
  int ascii[123] = {0};
  for (int i = 0; s[i] != '\0'; i++) {
    char c = s[i];
    if (c == ' ') continue;
    if (c >= 'A'  && c <= 'Z') {
      c = c + 32;
    }
    if (c >= 'a' && c <= 'z') {
      if (ascii[(unsigned char)c]) {
        return 0; // false
      }
      ascii[(unsigned char)c] = 1;
    }
  }
  return 1; // true
}

int main(void)
{
  char *t1 = "uncopyrightable";
  char *t2 = "sasasa";
  printf("%s\n", isogram(t1) ? "isogram" : "not isogram");
  printf("%s\n", isogram(t2) ? "isogram" : "not isogram");
  return 0;
}
