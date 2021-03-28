from unittest import TestCase

import main as bookStoreLibrary

class TestBookStoreApp(TestCase):
    def test_add_book(self):
        bookstore = bookStoreLibrary.BookStore()

        try:
            self.assertEqual(bookstore.AddBook("Life of Pi", "Action and Adventure"), 0)
            self.assertEqual(bookstore.AddBook("The Three Musketeers", "Action and Adventure"), 1)
        except Exception as ex:
            self.fail()

    def test_find_book(self):
        bookstore = bookStoreLibrary.BookStore()

        try:
            bookstore.AddBook("Life of Pi", "Action and Adventure")
            bookstore.AddBook("The Three Musketeers", "Action and Adventure")

            book = bookstore.FindBook("Life of Pi")
            self.assertEqual(book.Title, "Life of Pi")
            self.assertEqual(book.Genre, "Action and Adventure")
        except Exception as ex:
            self.fail()

        try:
            bookstore.FindBook("To Kill a Mockingbird")
            self.fail()
        except Exception as ex:
            self.assertEqual(str(ex), "Book not found")

    def test_add_author(self):
        bookstore = bookStoreLibrary.BookStore()

        try:
            self.assertEqual(bookstore.AddAuthor("Yann", "Martel"), 0)
            self.assertEqual(bookstore.AddAuthor("Alexandre", "Dumas"), 1)
        except Exception as ex:
            self.fail()

    def test_find_author(self):
        bookstore = bookStoreLibrary.BookStore()

        try:
            bookstore.AddAuthor("Yann", "Martel")
            bookstore.AddAuthor("Alexandre", "Dumas")

            author = bookstore.FindAuthor("Yann", "Martel")
            self.assertEqual(author.FirstName, "Yann")
            self.assertEqual(author.LastName, "Martel")
        except Exception as ex:
            self.fail()

        try:
            bookstore.FindAuthor("Harper", "Lee")
            self.fail()
        except Exception as ex:
            self.assertEqual(str(ex), "Author not found")

    def test_add_book_author(self):
        bookstore = bookStoreLibrary.BookStore();

        try:
            bookstore.AddBook("Life of Pi", "Action and Adventure")
            bookstore.AddAuthor("Yann", "Martel")
            book = bookstore.FindBook("Life of Pi")
            author = bookstore.FindAuthor("Yann", "Martel")

            self.assertEqual(bookstore.AddBookAuthor(author, book), True)
            self.assertEqual(bookstore.AddBookAuthor(author, book), True)

            authorFound = bookstore.FindBookAuthor(book)
            self.assertEqual(authorFound.Id, author.Id)
            self.assertEqual(authorFound.FirstName, author.FirstName)
            self.assertEqual(authorFound.LastName, author.LastName)
        except Exception as ex:
            self.fail()

        try:
            bookstore.AddBook("The Three Musketeers", "Action and Adventure")
            book = bookstore.FindBook("The Three Musketeers")

            bookstore.FindBookAuthor(book)
            self.fail()
        except Exception as ex:
            self.assertEqual(str(ex), "Author not found")

