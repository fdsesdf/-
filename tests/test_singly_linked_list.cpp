#include "SinglyLinkedList.h"
#include <iostream>

int main() {
    // 创建一个单链表
    SinglyLinkedList<int> list;

    // 在链表头部插入元素
    list.insertFront(10);
    list.insertFront(20);

    // 在链表尾部插入元素
    list.insertBack(5);
    list.insertBack(1);

    std::cout << "链表内容：";
    list.display(); // 输出: 20 -> 10 -> 5 -> 1 -> nullptr

    // 删除某个元素
    list.remove(10);
    std::cout << "删除10后的链表：";
    list.display(); // 输出: 20 -> 5 -> 1 -> nullptr

    return 0;
}
