//
// Created by plcla on 4/29/2022.
//

#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList() {
    this->headNode = nullptr;
}

Node& DoublyLinkedList::traverseListToIndex(int32_t index) {
    Node* headCopy = this->headNode;
    uint32_t i = 0;

    while (headCopy && i != index) {
        headCopy = headCopy->nextNode;
        i++;
    }

    return *headCopy;
}

Node& DoublyLinkedList::createNode(int32_t data) {
    Node* newNode = new Node;
    newNode->value = data;
    newNode->nextNode = nullptr;
    newNode->prevNode = nullptr;

    return *newNode;
}

void DoublyLinkedList::insertNode(int32_t data, int32_t index) {
    Node nodeToInsert = createNode(data);
    Node nodeBeforeIndex = traverseListToIndex(index - 1);
    Node nodeAtIndex = *nodeBeforeIndex.nextNode;

    nodeAtIndex.prevNode = &nodeToInsert;
    nodeBeforeIndex.nextNode = &nodeToInsert;
    nodeToInsert.nextNode = &nodeAtIndex;
    nodeToInsert.prevNode = &nodeBeforeIndex;
}

void DoublyLinkedList::deleteNode(int32_t index) {
    Node nodeToDelete = traverseListToIndex(index);

    nodeToDelete.prevNode->nextNode = nodeToDelete.nextNode;
    nodeToDelete.nextNode->prevNode = nodeToDelete.prevNode;

    delete &nodeToDelete;
}
