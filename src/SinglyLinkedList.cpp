#include "SinglyLinkedList.h"

// 构造函数定义
template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() : head(nullptr), size(0) {}

// 析构函数定义
template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
}

// 插入到链表头部
template <typename T>
void SinglyLinkedList<T>::insertFront(T data) {
    Node<T>* newNode = new Node<T>(data);
    newNode->next = head;
    head = newNode;
    size++;
}

// 插入到链表尾部
template <typename T>
void SinglyLinkedList<T>::insertBack(T data) {
    Node<T>* newNode = new Node<T>(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node<T>* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    size++;
}

// 删除链表中的某个值
template <typename T>
void SinglyLinkedList<T>::remove(T data) {
    if (head == nullptr) {
        throw std::out_of_range("链表为空，无法删除");
    }

    if (head->data == data) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        size--;
        return;
    }

    Node<T>* current = head;
    while (current->next != nullptr) {
        if (current->next->data == data) {
            Node<T>* temp = current->next;
            current->next = current->next->next;
            delete temp;
            size--;
            return;
        }
        current = current->next;
    }
    throw std::invalid_argument("链表中找不到该值");
}

// 打印链表
template <typename T>
void SinglyLinkedList<T>::display() const {
    Node<T>* current = head;
    while (current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

// 获取链表大小
template <typename T>
int SinglyLinkedList<T>::getSize() const {
    return size;
}

// 为模板类编写外部实现时的模板实例化
template class SinglyLinkedList<int>;  
template class SinglyLinkedList<double>;
template class SinglyLinkedList<std::string>;