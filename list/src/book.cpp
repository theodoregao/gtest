#include "book.h"

bool lowPriceToHighPrice(Book a, Book b)
{
    return a.price < b.price;
}

bool highPriceTolowPrice(Book a, Book b)
{
    return a.price > b.price;
}