#include "LinkedList.h"
#include "stdio.h"
#include "stdlib.h"

linkedList *initList() {
    linkedList *list;

    list = (linkedList *)malloc(sizeof(linkedList));

    if(list == NULL) {
        printf("メモリの取得エラー\n");
        return NULL;
    }

    list->topCell = NULL;
    // list->endCell = NULL;
    list->size = 0;

    printf("Linked List was Created.\n");
    return list;
}

void freeList(linkedList *list) {
    cell *Cell = NULL;
    cell *preCell = NULL;

    if(list == NULL) {
        printf("リストがNULLです\n");
        return;
    }

    Cell = list->topCell;
    while(Cell != NULL) {
        preCell = Cell;
        Cell = preCell->nextCell;
        freeCell(preCell);
    }
    
    printf("リストの開放の完了\n");
    free(list);
}

void freeCell(cell *cell) {
    free(cell);
    printf("セルの開放が完了\n");
}

void printList(linkedList *list) {
    if(list == NULL) {
        printf("リストが定義されていません");
        return;
    }
    if(list->size == 0) {
        printf("リストは空です\n");
        return;
    }
    
    printf("LinkedList size is %d\n", list->size);
    cell *Cell = list->topCell;
    while(Cell != NULL) {
        printf("%d ", Cell->num);
        Cell = Cell->nextCell;
    }
    putchar('\n');
}

cell *initCell() {
    cell *newCell = NULL;
    newCell = (cell *)malloc(sizeof(cell));

    if(newCell == NULL) {
        printf("メモリの取得に失敗\n");
        return NULL;
    }
    return newCell;
}

void pushFront(linkedList *list, int data) {
    if(list == NULL) {
        printf("リストが定義されていません\n");
        return;
    }
    cell *newCell = initCell(data);
    if(newCell == NULL) {
        printf("リストの追加に失敗\n");
        return;
    }

    if(list->size == 0)
    {
        newCell->nextCell = NULL;
        newCell->preCell = NULL;
    }
    else if(list->size > 0)
    {
        cell *nextCell = list->topCell;
        newCell->nextCell = nextCell;
        newCell->preCell = NULL;
        nextCell->preCell = newCell;
    }

    newCell->num = data;
    list->size++;
    list->topCell = newCell;
}

// linkedList insertList(linkedList *list, int data, int pos) {
//     cell *newCellNode;

//     initCell(&newCellNode, data);
//     list->size++;

//     // リストが初期状態のときは先頭に代入
//     if (list->size == 0) {
//         pushFront(list, newCellNode, data);
//     } else if(list->size <= pos) { // 指定範囲がsizeより大きいときは最後に挿入
//         pushBack(list, newCellNode, data);
//     } else if(0 > pos) { // 指定範囲が0より小さいとき先頭に代入
//         pushFront(list, newCellNode, data);
//     } /* else { // 指定位置が1以上sizeより小さいとき
//         cell *node = list->topCell;
//         for(int i = 1; i < pos; i++) {
//             node = node->nextCell;
//         }

//         node = &newCellNode;
//         node->preCell = &newCellNode;
//     } */
// }

// linkedList pushBack(linkedList *list, cell *newCell,int data) {
//     newCell->nextCell = NULL;
//     newCell->preCell  = list->endCell;
//     list->endCell = &newCell;
// }

// linkedList push(linkedList *list, cell *newCell, int data, int pos) {

// }
