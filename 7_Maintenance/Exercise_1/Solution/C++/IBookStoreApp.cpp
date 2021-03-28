#include "IBookStoreApp.hpp"

namespace BookstoreLibrary {
  unsigned int BookStore::AddAuthor(const string& firstName,
                                    const string& lastName)
  {
    unsigned int authorId = authors.size();
    authors.insert(pair<unsigned int, Author>(authorId, Author()));
    authorByName.insert(pair<string, unsigned int>(firstName + "-" + lastName, authorId)); // Fix

    Author& author = authors[authorId];

    author.Id = authorId;
    author.FirstName = firstName;
    author.LastName = lastName;

    return author.Id;
  }

  unsigned int BookStore::AddBook(const string& title,
                                  const string& genre)
  {
    unsigned int bookId = books.size() + 1;
    books.insert(pair<unsigned int, Book>(bookId, Book()));
    bookByTitle.insert(pair<string, unsigned int>(title, bookId));

    Book& book = books[bookId];

    book.Id = books.size() - 1;
    book.Title = title;
    book.Genre = genre;

    return book.Id;
  }

  bool BookStore::AddBookAuthor(const Author& author,
                                const Book& book)
  {
    bookAuthor.insert(pair<unsigned int, unsigned int>(book.Id, author.Id));
    return true;
  }

  const Author& BookStore::FindAuthor(const string& firstName,
                                      const string& lastName) const
  {
    const auto& authorIterator = authorByName.find(firstName + "-" + lastName);

    if (authorIterator == authorByName.end())
      throw runtime_error("Author not found");

    const unsigned int& authorId = authorIterator->second;
    return authors.at(authorId);
  }

  const Book& BookStore::FindBook(const string& title) const
  {
    const auto& bookIterator = bookByTitle.find(title);

    if (bookIterator == bookByTitle.end())
      throw runtime_error("Book not found"); // Fix

    const unsigned int& bookId = bookIterator->second;
    return books.at(bookId);
  }

  const Author& BookStore::FindBookAuthor(const Book& book) const
  {
    const auto& authorIterator = bookAuthor.find(book.Id);

    if (authorIterator == bookAuthor.end()) // Fix
      throw runtime_error("Author not found"); // Fix

    const unsigned int& authorId = authorIterator->second;
    return authors.at(authorId);
  }

}
