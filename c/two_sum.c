// https://leetcode.com/problems/two-sum/
#include <stdio.h>
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
  int *r = (int *)malloc(2 * sizeof(int));
  for (r[0] = 0; r[0] < numsSize; ++r[0]) {
    for (r[1] = r[0] + 1; r[1] < numsSize; ++r[1]) {
      if (nums[r[0]] + nums[r[1]] == target) {
        *returnSize = 2;
        return r;
      }
    }
  }
  return r;
}

int main(void)
{
  int nums[] = {2, 7, 11, 15};
  int target = 9;
  int returnSize = 0;
  int *r = twoSum(nums, 4, target, &returnSize);
  if (r != NULL) {
    printf("Found: [%d, %d].", r[0], r[1]);
    free(r);
  }
  return 0;
}
