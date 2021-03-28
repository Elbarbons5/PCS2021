#ifndef BOOKSTORE_H
#define BOOKSTORE_H

#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

namespace BookstoreLibrary {

  class Book {
    public:
      unsigned int Id;
      string Title;
      string Genre;
  };

  class Author {
    public:
      unsigned int Id;
      string FirstName;
      string LastName;
  };

  class IBookStore {
    public:
      virtual unsigned int AddAuthor(const string& firstName,
                                     const string& lastName) = 0;
      virtual unsigned int AddBook(const string& title,
                                   const string& genre) = 0;
      virtual bool AddBookAuthor(const Author& author,
                                 const Book& book) = 0;
      virtual const Author& FindAuthor(const string& firstName,
                                       const string& lastName) const = 0;
      virtual const Book& FindBook(const string& title) const = 0;
      virtual const Author& FindBookAuthor(const Book& book) const = 0;
  };

  class BookStore : public IBookStore {
    private:
      unordered_map<unsigned int, Book> books;
      unordered_map<unsigned int, Author> authors;
      unordered_map<string, unsigned int> bookByTitle;
      unordered_map<string, unsigned int> authorByName;
      unordered_map<unsigned int, unsigned int> bookAuthor;

    public:
      unsigned int AddAuthor(const string& firstName,
                             const string& lastName);
      unsigned int AddBook(const string& title,
                           const string& genre);
      bool AddBookAuthor(const Author& author,
                         const Book& book);
      const Author& FindAuthor(const string& firstName,
                               const string& lastName) const;
      const Book& FindBook(const string& title) const;
      const Author& FindBookAuthor(const Book& book) const;
  };
}

#endif // BOOKSTORE_H
