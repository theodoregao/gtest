#include "gtest/gtest.h"
#include <book.h>
#include <linkedlist.h>

struct LinkedListTests : public ::testing::Test
{
    LinkedList LinkedList;
    void SetUp() override
    {
        LinkedList.insert(Book{"001", "title1", 0.01});
        LinkedList.insert(Book{"002", "title2", 0.02});
        LinkedList.insert(Book{"003", "title3", 0.03});
    }
    void TearDown() override
    {
        LinkedList.clear();
    }
};

TEST_F(LinkedListTests, initialize_LinkedList_nsert_and_remove_then_size_returns_correct_value)
{
    ASSERT_EQ(LinkedList.isEmpty(), false);
    ASSERT_EQ(LinkedList.size(), 3);

    LinkedList.remove(0);
    LinkedList.remove(0);
    ASSERT_EQ(LinkedList.size(), 1);

    LinkedList.clear();
    ASSERT_EQ(LinkedList.isEmpty(), true);
    ASSERT_EQ(LinkedList.size(), 0);
}

TEST_F(LinkedListTests, check_list_contains_return_correct_result)
{
    ASSERT_FALSE(LinkedList.contains("000"));
    ASSERT_TRUE(LinkedList.contains("001"));
}

TEST_F(LinkedListTests, remove_with_valid_index_then_book_get_removed)
{
    LinkedList.remove(2);
    LinkedList.remove(0);
    ASSERT_EQ(LinkedList.size(), 1);
}

TEST_F(LinkedListTests, remove_with_invalid_isbn_then_nothing_get_removed)
{
    LinkedList.remove("000");
    ASSERT_EQ(LinkedList.size(), 3);
}

TEST_F(LinkedListTests, remove_with_valid_isbn_then_book_get_removed)
{
    LinkedList.remove("001");
    LinkedList.remove("002");
    ASSERT_EQ(LinkedList.size(), 1);
}

TEST_F(LinkedListTests, remove_with_invalid_index_then_throw_exception)
{
    ASSERT_THROW(LinkedList.remove(-1), std::out_of_range);
    ASSERT_THROW(LinkedList.remove(3), std::out_of_range);
}

TEST_F(LinkedListTests, getAt_with_valid_index_then_correct_book_returned)
{
    Book book = LinkedList.getAt(2);
    EXPECT_STREQ(book.isbn, "001");
    EXPECT_STREQ(book.title, "title1");
    EXPECT_EQ(book.price, 0.01);
}

TEST_F(LinkedListTests, getAt_with_invalid_index_then_throw_exception)
{
    ASSERT_THROW(LinkedList.getAt(-1), std::out_of_range);
    ASSERT_THROW(LinkedList.getAt(3), std::out_of_range);
}

TEST_F(LinkedListTests, search_with_valid_isbn_then_correct_book_returns)
{
    Book book = LinkedList.search("001");
    EXPECT_STREQ(book.isbn, "001");
    EXPECT_STREQ(book.title, "title1");
    EXPECT_EQ(book.price, 0.01);
}

TEST_F(LinkedListTests, search_with_invalid_isbn_then_throw_exception)
{
    ASSERT_THROW(LinkedList.search("000"), std::out_of_range);
}

TEST_F(LinkedListTests, update_with_valid_isbn_then_correct_book_get_updated)
{
    LinkedList.update("001", Book{"004", "title4", 0.04});

    ASSERT_THROW(LinkedList.search("001"), std::out_of_range);

    Book book = LinkedList.search("004");
    EXPECT_STREQ(book.isbn, "004");
    EXPECT_STREQ(book.title, "title4");
    EXPECT_EQ(book.price, 0.04);
}

TEST_F(LinkedListTests, update_with_invalid_isbn_then_throw_exception)
{
    ASSERT_THROW(LinkedList.update("000", Book{"000", "title0", 0.005}), std::out_of_range);
}

TEST_F(LinkedListTests, sortByPrice_then_books_get_sorted_by_price)
{
    LinkedList.insert(Book{"004", "title4", 0.01});
    LinkedList.insert(Book{"005", "title5", 1.01});
    LinkedList.insert(Book{"006", "title6", 0.11});

    LinkedList.sortByPrice();
    for (int i = 0; i < LinkedList.size() - 1; i++)
    {
        if (LinkedList.getAt(i).price > LinkedList.getAt(i + 1).price)
        {
            FAIL();
        }
    }
}

TEST_F(LinkedListTests, sortByPriceDescend_then_books_get_sorted_by_price)
{
    LinkedList.insert(Book{"004", "title4", 0.01});
    LinkedList.insert(Book{"005", "title5", 1.01});
    LinkedList.insert(Book{"006", "title6", 0.11});

    LinkedList.sortByPriceDescend();
    for (int i = 0; i < LinkedList.size() - 1; i++)
    {
        if (LinkedList.getAt(i).price < LinkedList.getAt(i + 1).price)
        {
            FAIL();
        }
    }
}
