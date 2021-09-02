//
// Created by nekoimi on 2021/9/1.
//
#include <stdio.h>
#include <stdlib.h>
#include "tree_struct.h"


void stack_push(stack *s, binaryTreeNode *tree) {
    ++s->index;
    s->data[s->index] = tree;
}

void stack_push_tag(tagStack *s, tagNode tgn) {
    ++s->index;
    s->data[s->index] = tgn;
}

void stack_pop(stack *s) {
    --s->index;
}

void stack_pop_tag(tagStack *s) {
    --s->index;
}

binaryTreeNode *stack_top(stack *s) {
    return s->data[s->index];
}

tagNode stack_top_tag(tagStack *s) {
    return s->data[s->index];
}

void queue_put(queue *q, binaryTreeNode *node) {
    q->rear++;
    q->data[q->rear] = node;
}

binaryTreeNode *queue_get(queue *q) {
    q->front++;
    binaryTreeNode *result = q->data[q->front];
    if (q->front == q->rear) {
        // ����֮�����Ϊ��, ��ն���
        q->rear = -1;
        q->front = -1;
    }
    return result;
}

int queue_is_empty(queue *q) {
    if (q->front < q->rear) {
        // ��Ϊ��
        return 0;
    }
    return 1;
}

void show_node(struct BinaryTreeNode *tree) {
    printf("%d, ", tree->data);
}

void each_one(struct BinaryTreeNode *tree) {
    if (!tree) {
        return; // Ignore
    }
    show_node(tree);
    each_one(tree->leftChild);
    each_one(tree->rightChild);
}

void each_one_by_stack(struct BinaryTreeNode *tree) {
    stack *s = (stack *) malloc(sizeof(stack));
    s->index = -1;
    // ���ڵ�����ջ
    stack_push(s, tree);
    // ����ջ�����ҽڵ㱣��
    while (s->index > -1) {
        // ȡ��ջ��Ԫ��
        binaryTreeNode *node = stack_top(s);
        // ����Ԫ��
        stack_pop(s);
        while (node) {
            printf("%d, ", node->data);
            if (node->rightChild) {
                stack_push(s, node->rightChild);
            }
            node = node->leftChild;
        }
    }
}

void each_two(struct BinaryTreeNode *tree) {
    if (!tree) {
        return; // Ignore
    }
    each_two(tree->leftChild);
    show_node(tree);
    each_two(tree->rightChild);
}

void each_two_by_stack(struct BinaryTreeNode *tree) {
    stack *s = (stack *) malloc(sizeof(stack));
    s->index = -1;
    // �������Դ���ڵ�
    binaryTreeNode *p = tree;
    while (p != NULL || s->index > -1) {
        if (p != NULL) {
            stack_push(s, p);
            p = p->leftChild;
        } else {
            p = stack_top(s);
            stack_pop(s);
            printf("%d, ", p->data);
            p = p->rightChild;
        }
    }
}

void each_three(struct BinaryTreeNode *tree) {
    if (!tree) {
        return; // Ignore
    }
    each_three(tree->leftChild);
    each_three(tree->rightChild);
    show_node(tree);
}

void each_three_by_stack(struct BinaryTreeNode *tree) {
    tagStack *s = (tagStack *) malloc(sizeof(tagStack));
    s->index = -1;

    int tag;
    tagNode tgn;
    binaryTreeNode *p = tree;
    while (p != NULL || s->index > -1) {
        while (p != NULL) {
            tgn.node = p;
            tgn.tag = 0;
            stack_push_tag(s, tgn);
            p = p->leftChild;
        }
        tgn = stack_top_tag(s);
        stack_pop_tag(s);
        p = tgn.node;
        tag = tgn.tag;
        // ��� tag == 0, ˵���ýڵ㻹û�б��������ҽڵ�
        if (tag == 0) {
            tgn.node = p;
            tgn.tag = 1; // ���ı��
            stack_push_tag(s, tgn);
            p = p->rightChild;
        }

            // tag Ϊ 1, �ڵ�������
        else {
            printf("%d, ", p->data);
            p = NULL;
        }
    }
}

void each_tree_by_arrangement(binaryTreeNode *node) {
    queue *q = (queue *) malloc(sizeof(queue));
    q->front = -1;
    q->rear = -1;

    binaryTreeNode *p = node;
    // ���ڵ����
    queue_put(q, p);
    // ���в�Ϊ��һֱ���²����
    while (!queue_is_empty(q)) {
        p = queue_get(q);
        printf("%d, ", p->data);
        // ����
        if (p->leftChild != NULL) {
            queue_put(q, p->leftChild);
        }
        // �Һ���
        if (p->rightChild != NULL) {
            queue_put(q, p->rightChild);
        }
    }
}

void binary_tree_node() {
    binaryTreeNode *binTree = malloc(sizeof(binaryTreeNode));
    binTree->data = 1;
    binTree->leftChild = malloc(sizeof(binaryTreeNode));
    binTree->leftChild->data = 2;

    binTree->leftChild->leftChild = malloc(sizeof(binaryTreeNode));
    binTree->leftChild->leftChild->data = 4;
    binTree->leftChild->leftChild->leftChild = NULL;
    binTree->leftChild->leftChild->rightChild = NULL;

    binTree->leftChild->rightChild = malloc(sizeof(binaryTreeNode));
    binTree->leftChild->rightChild->data = 5;
    binTree->leftChild->rightChild->leftChild = NULL;
    binTree->leftChild->rightChild->rightChild = NULL;

    binTree->rightChild = malloc(sizeof(binaryTreeNode));
    binTree->rightChild->data = 3;
    binTree->rightChild->leftChild = malloc(sizeof(binaryTreeNode));
    binTree->rightChild->leftChild->data = 6;
    binTree->rightChild->leftChild->leftChild = NULL;
    binTree->rightChild->leftChild->rightChild = NULL;

    binTree->rightChild->rightChild = malloc(sizeof(binaryTreeNode));
    binTree->rightChild->rightChild->data = 7;
    binTree->rightChild->rightChild->leftChild = NULL;
    binTree->rightChild->rightChild->rightChild = NULL;

    printf("ǰ����� - �ݹ�: ");
    each_one(binTree);
    printf("\n");

    printf("ǰ����� - �ǵݹ�: ");
    each_one_by_stack(binTree);
    printf("\n----------------------------------\n");

    printf("������� - �ݹ�: ");
    each_two(binTree);
    printf("\n");

    printf("������� - �ǵݹ�: ");
    each_two_by_stack(binTree);
    printf("\n----------------------------------\n");

    printf("������� - �ݹ�: ");
    each_three(binTree);
    printf("\n");

    printf("������� - �ǵݹ�: ");
    each_three_by_stack(binTree);
    printf("\n----------------------------------\n");

    printf("�������: ");
    each_tree_by_arrangement(binTree);
    printf("\n");
}
