#include "listhelper.h"

/**
    Using recursion check which element of list is smaller and put him before other.
    list1: First sorted list.
    list2: Second sorted list.
**/
struct ListNode* mergeLists(struct ListNode* list1, struct ListNode* list2)
{
    if (list1 == NULL)
    {
        return list2;
    }

    if (list2 == NULL)
    {
        return list1;
    }

    if (list1->value <= list2->value)
    {
        list1->next = mergeLists(list1->next, list2);
        return list1;
    }
    else
    {
        list2->next = mergeLists(list1, list2->next);
        return list2;
    }
}


/**
    Prints list for user convenience and for testing purposes.
    list: List that we want to print.
**/
void printList(struct ListNode* list)
{
    struct ListNode* tempList = list;

    while (tempList != NULL)
    {
        printf("%"PRIdLEAST32" -> ", tempList->value);
        tempList = tempList->next;
    }

    printf("NULL \n");
}

/**
    Push provided value to the head of the linked list.
    head: Head of linked list.
    data: Integer value that we want to insert.
**/
void push(struct ListNode** head, int_least32_t data)
{
    struct ListNode* newListNode = (struct ListNode*)malloc(sizeof(struct ListNode*));
    newListNode->value = data;
    newListNode->next = *head;
    *head = newListNode;
}

/**
    Swap values from List Node provided, used for bubble sort where we compare current Node value with next Node value.
    a: List Node.
    b: a -> next.
**/
void swap(struct ListNode* a, struct ListNode* b)
{
    int_least32_t temp = a->value;
    a->value = b->value;
    b->value = temp;
}

/**
    Sort given linked list using bubble sort.
    start: Linked list that we want to iterate through and sort.
**/
void bubbleSort(struct ListNode* start)
{
    int_least8_t swapped;

    struct ListNode* firstList;
    struct ListNode* lptr = NULL;

    assert(start != NULL);

    do
    {
        swapped = 0;
        firstList = start;

        while (firstList->next != lptr)
        {
            if (firstList->value > firstList->next->value)
            {
                swap(firstList, firstList->next);
                swapped = 1;
            }
            firstList = firstList->next;
        }
        lptr = firstList;
    }
    while (swapped);
}

/**
    Helper function used for creating 2 linked lists with user input.
    After taking all given values, use bubbleSort to automatically sort given list.
**/
struct ListNode* listBuilder(void)
{
    struct ListNode* builtList = NULL;

    int_least32_t i;
    int_least32_t n = 0;
    int_least32_t element;

    printf("Enter number of elements you want for the list: ");
    scanf("%"SCNdLEAST32"", &n);

    for (i = 0; i < n; i++)
    {
        printf("%"PRIdLEAST32": ", i);
        scanf("%"SCNdLEAST32"", &element);
        push(&builtList, element);
    }

    bubbleSort(builtList);

    return builtList;
}
