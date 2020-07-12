#pragma once

#include "book.h"

class ArrayList
{
public:
    ArrayList();
    ~ArrayList();

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
    const int DEFAULT_SIZE = 1;
    int _size;
    int _capacity;
    Book *_books;

    void resize();
    void validIndex(int index);
    int internalSearch(const char *isbn);
    void bobbleSort(bool pFunRightOrder(Book, Book));
    void swap(int i, int j);
};