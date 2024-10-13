#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <iostream>
#include <stdexcept>

// 节点结构
template <typename T>
struct Node {
    T data;
    Node* next;
    Node(T val) : data(val), next(nullptr) {}
};

// 单链表类
template <typename T>
class SinglyLinkedList {
private:
    Node<T>* head;
    int size;

public:
    // 构造函数
    SinglyLinkedList();

    // 析构函数
    ~SinglyLinkedList();

    // 插入元素到链表头部
    void insertFront(T data);

    // 插入元素到链表尾部
    void insertBack(T data);

    // 删除链表中的某个值
    void remove(T data);

    // 打印链表
    void display() const;

    // 获取链表大小
    int getSize() const;
};

#endif
