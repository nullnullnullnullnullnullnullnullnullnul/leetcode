// https://leetcode.com/problems/longest-palindromic-substring/
//#include <stdio.h>
#include <stdlib.h>

char* longestPalindrome(char *s)
{
  size_t len = 0;
  while (s[len]!= '\0')len++;
  if (len == 0) {
    char *empty = malloc(1);
    empty[0] = '\0';
    return empty;
  }
  size_t maxStart = 0;
  size_t maxLen = 1;
  for (size_t c = 0; c < len; c++) {
    if ((len - c) * 2 <= maxLen) break;
    int l = (int)c;
    size_t r = c;
    // odd length
    while (l >= 0 && r < len && s[l] == s[r]) {
      size_t currLen = r - l + 1;
      if (currLen > maxLen) {
        maxStart = l;
        maxLen = currLen;
      }
      l--;
      r++;
    }
    // even length
    l = (int)c;
    r = c + 1;
    while (l >= 0 && r < len && s[l]== s[r]){
      size_t currLen = r - l + 1;
      if (currLen > maxLen){
        maxStart = l;
        maxLen = currLen;
      }
      l--;
      r++;
    }
  }
  char *result = malloc(maxLen+1);
  for (size_t i = 0; i < maxLen;i++) {
    result[i] = s[maxStart+i];
  }
  result[maxLen] = '\0';
  return result;
}

int main(void)
{
  char *test = "babad";
  char *result = longestPalindrome(test);
  //printf("%s", result);
  return 0;
}