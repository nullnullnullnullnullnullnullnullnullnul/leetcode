// https://leetcode.com/problems/longest-substring-without-repeating-characters
#include <stdio.h>

// lastI is ASCII table making record of chars seen
// using sliding window algorithm
int lengthOfLongestSubstring(char *s)
{
  int count = 0;
  int start = 0;
  int lastI[123];
  for (int i = 0; i < 123; i++) {
    lastI[i] = -1;
  }
  for (int e = 0; s[e] != '\0'; e++) {
    char c = s[e];
    if (lastI[(unsigned char)c] >= start) {
      start = lastI[(unsigned char)c] + 1;
    }
    lastI[(unsigned char)c] = e;
    int windowLen = e - start + 1;
    if (windowLen > count) {
      count = windowLen;
    }
  }
  return count;
}

int main(void)
{
  char *s = " ";
  int count = lengthOfLongestSubstring(s);
  printf("%i", count);
  return 0;
}