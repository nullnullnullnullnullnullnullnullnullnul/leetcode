// https://leetcode.com/problems/median-of-two-sorted-arrays/
#include <stdio.h>
#include <stdlib.h>

// would be better if i made n+m instead of end1+end2 i forgot
// and i wont change what i already uploaded to leetcode for
// consistency 
double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
  int count = 0;
  int totalSize = nums1Size + nums2Size;
  int *merged = calloc(totalSize, sizeof(int));
  int *p1 = nums1;
  int *p2 = nums2;
  int *end1 = nums1 + nums1Size;
  int *end2 = nums2 + nums2Size;
  while (p1 < end1 && p2 < end2) {
    if (*p1 <= *p2) {
      merged[count++] = *p1++;
    } else {
      merged[count++] = *p2++;
    }
  }
  while (p1 < end1) {
    merged[count++] = *p1++;
  }
  while (p2 < end2) {
    merged[count++] = *p2++;
  }
  double median;
  if (totalSize % 2 != 0) {
    median = merged[(int)totalSize / 2];
  } else {
    int mid = totalSize / 2;
    median = (merged[mid - 1] + merged[mid]) / 2.0;
  }
  free(merged);
  return median;
}

int main(void)
{
  int nums1[] = {1,2};
  int nums2[] = {3,4};
  double result = findMedianSortedArrays(nums1, 2, nums2, 2);
  printf("\n%f", result);
  return 0;
}