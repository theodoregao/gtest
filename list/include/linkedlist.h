#pragma once

#include "book.h"

struct Node
{
    Book book;
    Node *next;
};

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();

    void insert(Book book);
    void remove(const char *isbn);
    void remove(int index);
    Book search(const char *isbn);
    void update(const char *isbn, Book book);
    Book getAt(int index);
    int size();
    bool isEmpty();
    bool contains(const char *isbn);
    void clear();
    void sortByPrice();
    void sortByPriceDescend();

private:
    int _size;
    Node *_head;

    void validIndex(int index);
    void bobbleSort(bool pFunRightOrder(Book, Book));
    void swap(Node *pre, Node *p, Node *q);
};