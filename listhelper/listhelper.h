#ifndef _LISTHELPER
#define _LISTHELPER

#pragma CHECK_MISRA("none")
#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#pragma CHECK_MISRA("-20.9")

struct ListNode
{
    int_least32_t value;
    struct ListNode* next;
};

struct ListNode* mergeLists(struct ListNode* list1, struct ListNode* list2);

void printList(struct ListNode* list);

void push(struct ListNode** head, int_least32_t data);

struct ListNode* listBuilder(void);

//Uncomment if you use automatic input
void bubbleSort(struct ListNode* start);

#endif
