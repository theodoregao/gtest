#pragma once

struct Book
{
    char isbn[64];
    char title[128];
    double price;
};

bool lowPriceToHighPrice(Book a, Book b);
bool highPriceTolowPrice(Book a, Book b);
