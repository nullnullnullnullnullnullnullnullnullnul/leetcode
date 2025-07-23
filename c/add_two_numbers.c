#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode
{
  int val;
  struct ListNode *next;
};

struct ListNode* buildList(int size, int *arr)
{
  struct ListNode *h = malloc(sizeof(struct ListNode));
  h->val = arr[0];
  h->next = NULL;
  struct ListNode *cur = h;
  for (int i = 1; i < size; i++) {
    struct ListNode *node = malloc(sizeof(struct ListNode));
    node->val = arr[i];
    node->next = NULL;
    cur->next = node;
    cur = node;
  }
  return h;
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
  struct ListNode *temp = malloc(sizeof(struct ListNode));
  temp->val = 0;
  temp->next = NULL;
  struct ListNode *cur = temp;
  int carry = 0;
  while (l1 != NULL || l2 != NULL || carry > 0) {
    int x = (l1 != NULL) ? l1->val : 0;
    int y = (l2 != NULL) ? l2->val : 0;
    int sum = x + y + carry;
    carry = sum / 10;
    struct ListNode *node = malloc(sizeof(struct ListNode));
    node->val = sum % 10;
    node->next = NULL;
    cur->next = node;
    cur = node;
    if (l1 != NULL) l1 = l1->next;
    if (l2 != NULL) l2 = l2->next;
  }
  struct ListNode *r = temp->next;
  free(temp);
  return r;
}

void printList(struct ListNode *h)
{
  while (h) {
    printf("%d ", h->val);
    h = h->next;
  }
  puts("\n");
}

int main(void)
{
  int arr1[] = {2,4,3};
  int arr2[] = {5,6,4};
  struct ListNode *l1 = buildList(3, arr1);
  struct ListNode *l2 = buildList(3, arr2);
  struct ListNode *r = addTwoNumbers(l1, l2);
  printList(r);
  return 0;
}