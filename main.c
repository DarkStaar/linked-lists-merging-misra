/***
Autor: Milan Kapetanovic RA 184/2018

Opis zadatka:
    Napraviti modul koji predstavlja jednostruko spregnutu listu.
    Modul izvesti kao dinamicku biblioteku koja se povezuje prilikom pokretanja programa.
    Zatim napraviti funkciju koja dve uredjene (sortirane) liste spaja u jednu isto uredjenu
    (sortiranu) listu.
***/

#include "./listhelper/listhelper.h"
#define ARRAY_SIZE 8

int_least8_t main(void);

int_least8_t main(void)
{
    struct ListNode* first = NULL;
    struct ListNode* second = NULL;

    struct ListNode* finalList;

    //Interactive way of creating linked lists.
    //first = listBuilder();
    //second = listBuilder();

    //Not so much interactive way of creating linked lists.


    int_least32_t firstarray[ARRAY_SIZE] = {1, 2, 5, 6, 21313, 52, 0, 9};
    int_least32_t secondarray[ARRAY_SIZE] = {0, -1, 22, 256, 21314, 232, 68, 123};

    int_least16_t i;

    for (i = 0; i < ARRAY_SIZE; i++)
    {
        push(&first, firstarray[i]);
        push(&second, secondarray[i]);
    }

    bubbleSort(first);
    bubbleSort(second);

    printf("Sorted first list: ");
    printList(first);

    printf("Sorted second list: ");
    printList(second);

    finalList = mergeLists(first, second);

    printf("Merged lists: ");
    printList(finalList);

    return 0;
}
