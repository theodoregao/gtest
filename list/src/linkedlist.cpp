#include "linkedlist.h"
#include <cstdlib>
#include <cstring>
#include <stdexcept>

LinkedList::LinkedList()
{
    _head = (Node *)malloc(sizeof(Node));
    _head->next = nullptr;
    _size = 0;
}

LinkedList::~LinkedList()
{
    clear();
    free(_head);
}

void LinkedList::insert(Book book)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->book = book;
    node->next = _head->next;
    _head->next = node;
    _size++;
}

void LinkedList::remove(const char *isbn)
{
    Node *pre = _head;
    Node *p = pre->next;
    while (p != nullptr)
    {
        if (strcmp(p->book.isbn, isbn) == 0)
        {
            pre->next = p->next;
            free(p);
            _size--;
            return;
        }
        pre = p;
        p = pre->next;
    }
}

void LinkedList::remove(int index)
{
    validIndex(index);
    Node *pre = _head;
    Node *p = _head->next;
    for (int i = 0; i < index; i++)
    {
        pre = p;
        p = pre->next;
    }
    pre->next = p->next;
    free(p);
    _size--;
}

Book LinkedList::search(const char *isbn)
{
    Node *p = _head->next;
    while (p != nullptr)
    {
        if (strcmp(p->book.isbn, isbn) == 0)
        {
            return p->book;
        }
        p = p->next;
    }
    throw std::out_of_range("Invalid index");
}

void LinkedList::update(const char *isbn, Book book)
{
    Node *p = _head->next;
    while (p != nullptr)
    {
        if (strcmp(p->book.isbn, isbn) == 0)
        {
            p->book = book;
            return;
        }
        p = p->next;
    }
    throw std::out_of_range("Invalid index");
}

Book LinkedList::getAt(int index)
{
    validIndex(index);
    Node *p = _head->next;
    for (int i = 0; i < index; i++)
    {
        p = p->next;
    }
    return p->book;
}

int LinkedList::size()
{
    return _size;
}

bool LinkedList::isEmpty()
{
    return _head->next == nullptr;
}

bool LinkedList::contains(const char *isbn)
{
    Node *p = _head->next;
    while (p != nullptr)
    {
        if (strcmp(p->book.isbn, isbn) == 0)
        {
            return true;
        }
        p = p->next;
    }
    return false;
}

void LinkedList::clear()
{
    Node *p = _head->next;
    Node *q;
    while (p != nullptr)
    {
        q = p->next;
        free(p);
        p = q;
    }
    _head->next = nullptr;
    _size = 0;
}

void LinkedList::sortByPrice()
{
    bobbleSort(lowPriceToHighPrice);
}

void LinkedList::sortByPriceDescend()
{
    bobbleSort(highPriceTolowPrice);
}

void LinkedList::validIndex(int index)
{
    if (index < 0 || index >= _size)
    {
        throw std::out_of_range("Invalid index");
    }
}

void LinkedList::bobbleSort(bool pFunRightOrder(Book, Book))
{
    Node *pre, *p, *q;
    int i, j;
    for (i = 0; i < _size; i++)
    {
        pre = _head;
        p = pre->next;
        q = p->next;
        for (j = 0; j < _size - i - 1; j++)
        {
            if (!pFunRightOrder(p->book, q->book))
            {
                swap(pre, p, q);
            }
            pre = p;
            p = pre->next;
            q = p->next;
        }
    }
}

void LinkedList::swap(Node *pre, Node *p, Node *q)
{
    pre->next = q;
    p->next = q->next;
    q->next = p;
}
