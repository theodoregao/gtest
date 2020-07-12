#include <arraylist.h>
#include <stdexcept>
#include <cstdlib>
#include <cstring>

ArrayList::ArrayList()
{
   _size = 0;
   _capacity = DEFAULT_SIZE;
   _books = (Book *)malloc(_capacity * sizeof(Book));
}
ArrayList::~ArrayList()
{
   free(_books);
}

void ArrayList::insert(Book book)
{
   if (_size >= _capacity)
   {
      resize();
   }
   _books[_size++] = book;
}

void ArrayList::remove(const char *isbn)
{
   try
   {
      remove(internalSearch(isbn));
   }
   catch (std::exception e)
   {
   }
}

void ArrayList::remove(int index)
{
   validIndex(index);
   _books[index] = _books[--_size];
}

Book ArrayList::search(const char *isbn)
{
   return getAt(internalSearch(isbn));
}

void ArrayList::update(const char *isbn, Book book)
{
   int index = internalSearch(isbn);
   validIndex(index);
   _books[index] = book;
}

Book ArrayList::getAt(int index)
{
   validIndex(index);
   return _books[index];
}

int ArrayList::size()
{
   return _size;
}

bool ArrayList::isEmpty()
{
   return _size == 0;
}

bool ArrayList::contains(const char *isbn)
{
   return internalSearch(isbn) >= 0;
}

void ArrayList::clear()
{
   free(_books);
   _size = 0;
   _capacity = DEFAULT_SIZE;
   _books = (Book *)malloc(_capacity * sizeof(Book));
}

void ArrayList::sortByPrice()
{
   bobbleSort(lowPriceToHighPrice);
}

void ArrayList::sortByPriceDescend()
{
   bobbleSort(highPriceTolowPrice);
}

void ArrayList::resize()
{
   _books = (Book *)realloc(_books, _capacity * 2 * sizeof(Book));
   _capacity *= 2;
}

void ArrayList::validIndex(int index)
{
   if (index < 0 || index >= _size)
   {
      throw std::out_of_range("Invalid index");
   }
}

int ArrayList::internalSearch(const char *isbn)
{
   for (int i = 0; i < _size; i++)
   {
      if (strcmp(_books[i].isbn, isbn) == 0)
      {
         return i;
      }
   }
   return -1;
}

void ArrayList::bobbleSort(bool pFunRightOrder(Book, Book))
{
   for (int i = 0; i < _size; i++)
   {
      for (int j = 0; j < _size - i - 1; j++)
      {
         if (!pFunRightOrder(_books[j], _books[j + 1]))
         {
            swap(j, j + 1);
         }
      }
   }
}

void ArrayList::swap(int i, int j)
{
   Book temp = _books[i];
   _books[i] = _books[j];
   _books[j] = temp;
}
