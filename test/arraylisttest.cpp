#include "gtest/gtest.h"
#include <book.h>
#include <arraylist.h>

struct ArrayListTests : public ::testing::Test
{
    ArrayList arrayList;
    void SetUp() override
    {
        arrayList.insert(Book{"001", "title1", 0.01});
        arrayList.insert(Book{"002", "title2", 0.02});
        arrayList.insert(Book{"003", "title3", 0.03});
    }
    void TearDown() override
    {
        arrayList.clear();
    }
};

TEST_F(ArrayListTests, initialize_ArrayList_nsert_and_remove_then_size_returns_correct_value)
{
    ASSERT_EQ(arrayList.isEmpty(), false);
    ASSERT_EQ(arrayList.size(), 3);

    arrayList.remove(0);
    arrayList.remove(0);
    ASSERT_EQ(arrayList.size(), 1);

    arrayList.clear();
    ASSERT_EQ(arrayList.isEmpty(), true);
    ASSERT_EQ(arrayList.size(), 0);
}

TEST_F(ArrayListTests, check_list_contains_return_correct_result)
{
    ASSERT_FALSE(arrayList.contains("000"));
    ASSERT_TRUE(arrayList.contains("001"));
}

TEST_F(ArrayListTests, remove_with_valid_index_then_book_get_removed)
{
    arrayList.remove(2);
    arrayList.remove(0);
    ASSERT_EQ(arrayList.size(), 1);
}

TEST_F(ArrayListTests, remove_with_invalid_isbn_then_nothing_get_removed)
{
    arrayList.remove("000");
    ASSERT_EQ(arrayList.size(), 3);
}

TEST_F(ArrayListTests, remove_with_valid_isbn_then_book_get_removed)
{
    arrayList.remove("001");
    arrayList.remove("002");
    ASSERT_EQ(arrayList.size(), 1);
}

TEST_F(ArrayListTests, remove_with_invalid_index_then_throw_exception)
{
    ASSERT_THROW(arrayList.remove(-1), std::out_of_range);
    ASSERT_THROW(arrayList.remove(3), std::out_of_range);
}

TEST_F(ArrayListTests, getAt_with_valid_index_then_correct_book_returned)
{
    Book book = arrayList.getAt(2);
    EXPECT_STREQ(book.isbn, "003");
    EXPECT_STREQ(book.title, "title3");
    EXPECT_EQ(book.price, 0.03);
}

TEST_F(ArrayListTests, getAt_with_invalid_index_then_throw_exception)
{
    ASSERT_THROW(arrayList.getAt(-1), std::out_of_range);
    ASSERT_THROW(arrayList.getAt(3), std::out_of_range);
}

TEST_F(ArrayListTests, search_with_valid_isbn_then_correct_book_returns)
{
    Book book = arrayList.search("001");
    EXPECT_STREQ(book.isbn, "001");
    EXPECT_STREQ(book.title, "title1");
    EXPECT_EQ(book.price, 0.01);
}

TEST_F(ArrayListTests, search_with_invalid_isbn_then_throw_exception)
{
    ASSERT_THROW(arrayList.search("000"), std::out_of_range);
}

TEST_F(ArrayListTests, update_with_valid_isbn_then_correct_book_get_updated)
{
    arrayList.update("001", Book{"004", "title4", 0.04});

    ASSERT_THROW(arrayList.search("001"), std::out_of_range);

    Book book = arrayList.search("004");
    EXPECT_STREQ(book.isbn, "004");
    EXPECT_STREQ(book.title, "title4");
    EXPECT_EQ(book.price, 0.04);
}

TEST_F(ArrayListTests, update_with_invalid_isbn_then_throw_exception)
{
    ASSERT_THROW(arrayList.update("000", Book{"000", "title0", 0.005}), std::out_of_range);
}

TEST_F(ArrayListTests, sortByPrice_then_books_get_sorted_by_price)
{
    arrayList.insert(Book{"004", "title4", 0.01});
    arrayList.insert(Book{"005", "title5", 1.01});
    arrayList.insert(Book{"006", "title6", 0.11});

    arrayList.sortByPrice();
    for (int i = 0; i < arrayList.size() - 1; i++)
    {
        if (arrayList.getAt(i).price > arrayList.getAt(i + 1).price)
        {
            FAIL();
        }
    }
}

TEST_F(ArrayListTests, sortByPriceDescend_then_books_get_sorted_by_price)
{
    arrayList.insert(Book{"004", "title4", 0.01});
    arrayList.insert(Book{"005", "title5", 1.01});
    arrayList.insert(Book{"006", "title6", 0.11});

    arrayList.sortByPriceDescend();
    for (int i = 0; i < arrayList.size() - 1; i++)
    {
        if (arrayList.getAt(i).price < arrayList.getAt(i + 1).price)
        {
            FAIL();
        }
    }
}
