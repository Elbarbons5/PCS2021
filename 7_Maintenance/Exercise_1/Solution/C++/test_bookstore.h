#ifndef __TEST_SHOPPING_H
#define __TEST_SHOPPING_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <gmock/gmock-matchers.h>

#include "IBookStoreApp.hpp"

using namespace BookstoreLibrary;

using namespace testing;

namespace BookstoreTesting {

  TEST(TestBookstore, TestAddBook)
  {
    BookStore bookstore;

    try
    {
      EXPECT_EQ(bookstore.AddBook("Life of Pi", "Action and Adventure"), 0);
      EXPECT_EQ(bookstore.AddBook("The Three Musketeers", "Action and Adventure"), 1);
    }
    catch (const exception& exception)
    {
      FAIL();
    }

  }

  TEST(TestBookstore, TestFindBook)
  {
    BookStore bookstore;

    try
    {
      bookstore.AddBook("Life of Pi", "Action and Adventure");
      bookstore.AddBook("The Three Musketeers", "Action and Adventure");

      const Book& book = bookstore.FindBook("Life of Pi");
      EXPECT_EQ(book.Title, "Life of Pi");
      EXPECT_EQ(book.Genre, "Action and Adventure");
    }
    catch (const exception& exception)
    {
      FAIL();
    }

    try
    {
      bookstore.FindBook("To Kill a Mockingbird");
      FAIL();
    }
    catch (const exception& exception)
    {
      EXPECT_THAT(std::string(exception.what()), Eq("Book not found"));
    }
  }

  TEST(TestBookstore, TestAddAuthor)
  {
    BookStore bookstore;

    try
    {
      EXPECT_EQ(bookstore.AddAuthor("Yann", "Martel"), 0);
      EXPECT_EQ(bookstore.AddAuthor("Alexandre", "Dumas"), 1);
    }
    catch (const exception& exception)
    {
      FAIL();
    }
  }

  TEST(TestBookstore, TestFindAuthor)
  {
    BookStore bookstore;

    try
    {
      bookstore.AddAuthor("Yann", "Martel");
      bookstore.AddAuthor("Alexandre", "Dumas");

      const Author& author = bookstore.FindAuthor("Yann", "Martel");
      EXPECT_EQ(author.FirstName, "Yann");
      EXPECT_EQ(author.LastName, "Martel");
    }
    catch (const exception& exception)
    {
      FAIL();
    }

    try
    {
      bookstore.FindAuthor("Harper", "Lee");
      FAIL();
    }
    catch (const exception& exception)
    {
      EXPECT_THAT(std::string(exception.what()), Eq("Author not found"));
    }

  }

  TEST(TestBookstore, TestAddBookAuthor)
  {
    BookStore bookstore;

    try
    {
      bookstore.AddBook("Life of Pi", "Action and Adventure");
      bookstore.AddAuthor("Yann", "Martel");
      const Book& book = bookstore.FindBook("Life of Pi");
      const Author& author = bookstore.FindAuthor("Yann", "Martel");

      EXPECT_EQ(bookstore.AddBookAuthor(author, book), true);
      EXPECT_EQ(bookstore.AddBookAuthor(author, book), true);

      const Author& authorFound = bookstore.FindBookAuthor(book);
      EXPECT_EQ(authorFound.Id, author.Id);
      EXPECT_EQ(authorFound.FirstName, author.FirstName);
      EXPECT_EQ(authorFound.LastName, author.LastName);
    }
    catch (const exception& exception)
    {
      FAIL();
    }

    try
    {
      bookstore.AddBook("The Three Musketeers", "Action and Adventure");
      const Book& book = bookstore.FindBook("The Three Musketeers");

      bookstore.FindBookAuthor(book);
      FAIL();
    }
    catch (const exception& exception)
    {
      EXPECT_THAT(std::string(exception.what()), Eq("Author not found"));
    }
  }
}

#endif // __TEST_SHOPPING_H
