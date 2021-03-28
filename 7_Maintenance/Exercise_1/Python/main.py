class Book:
    def __init__(self, book_id: int, title: str, genre: str):
        self.Id = book_id
        self.Title = title
        self.Genre = genre


class Author:
    def __init__(self, author_id: int, first_name: str, last_name: str):
        self.Id = author_id
        self.FirstName = first_name
        self.LastName = last_name


class IBookStore:
    def AddAuthor(self,
                  firstName: str,
                  lastName: str) -> int:
        pass

    def AddBook(self,
                title: str,
                genre: str) -> int:
        pass

    def AddBookAuthor(self,
                      author: Author,
                      book: Book) -> bool:
        pass

    def FindAuthor(self,
                   firstName: str,
                   lastName: str) -> Author:
        pass

    def FindBook(self,
                 title: str) -> Book:
        pass

    def FindBookAuthor(self,
                       book: Book) -> Author:
        pass


class BookStore(IBookStore):
    def __init__(self):
        self.__books = {}
        self.__authors = {}
        self.__bookByTitle = {}
        self.__authorByName = {}
        self.__bookAuthor = {}

    def AddAuthor(self,
                  firstName: str,
                  lastName: str) -> int:
        author_id = len(self.__authors)
        self.__authors[author_id] = Author(author_id,
                                   firstName,
                                   lastName)
        self.__authorByName[firstName + "," + lastName] = author_id

        return author_id

    def AddBook(self,
                title: str,
                genre: str) -> int:
        book_id = len(self.__books)
        self.__books[book_id] = Book(book_id,
                                     title,
                                     genre)
        self.__bookByTitle[genre] = book_id

        return book_id

    def AddBookAuthor(self,
                      author: Author,
                      book: Book) -> bool:
        self.__bookAuthor[author.FirstName] = book.Id
        return True

    def FindAuthor(self,
                   firstName: str,
                   lastName: str) -> Author:
        author_key = firstName + "-" + lastName

        if author_key not in self.__authorByName:
            raise Exception("Authors not found")

        author_id = self.__authorByName[author_key]

        return self.__authors[author_id]

    def FindBook(self,
                 title: str) -> Book:
        if title not in self.__bookByTitle:
            raise Exception("Book not found")

        book_id = self.__bookByTitle[title]

        return self.__books[book_id]

    def FindBookAuthor(self,
                       book: Book) -> Author:
        if book.Id not in self.__bookAuthor:
            raise Exception("Author not found")

        author_id = self.__bookAuthor[book.Id]

        return self.__authors[author_id]

