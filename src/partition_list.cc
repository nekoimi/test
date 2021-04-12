//
// Created by nekoimi on 2021/4/12.
//
#include <stdio.h>
#include "partition_list.h"

/**
 * 找到第一个大于 x 的节点 a, 把 x 后面所有小于 x 的节点全部挪到 a 的前面
 */
struct ListNode* partition(struct ListNode* head, int x){
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode* p = head;
    while (p != NULL) {
        if (p->val >= x) {
            printf("pv: %d \n", p->val);
            p = head;
            break;
        }
        p = p->next;
    }
    return head;
}

void runPartitionList() {
    struct ListNode* head = newLinkedList(1);
    struct ListNode* node = insert(head, 4);
    node = insert(node, 3);
    node = insert(node, 2);
    node = insert(node, 5);
    node = insert(node, 2);
    printLinkedList(head);

    head = partition(head, 3);
    printLinkedList(head);
}
