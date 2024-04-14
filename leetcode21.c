/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    //判斷是否有空集合
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }
    if (list1 == NULL && list2 == NULL) {
        return NULL;
    }
    //先判斷兩個list第一個的大小
    struct ListNode* mergehead = NULL;
    if (list1->val < list2->val) {
        mergehead = list1;
        list1 = list1->next;
    }
    else{
        mergehead = list2;
        list2 = list2->next;
    }
    //創建一個新的link list 並判斷後放進
    struct ListNode* map = mergehead;
    while(list1 && list2) {
        if (list1->val < list2->val) {
            map->next = list1;
            list1 = list1->next ;
        }
        else {
            map->next = list2;
            list2 = list2->next ;
        }
        map=map->next;
    }
    if (list1 != NULL) {
        map->next = list1;
    }
    if (list2 != NULL) {
        map->next = list2;
    }
    return mergehead;
}