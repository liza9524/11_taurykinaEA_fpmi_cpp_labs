#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <algorithm>
#include <sstream>

struct Author {
    std::string surname;
    std::string name;
    std::string patronymic;
    Author() {}
    Author(std::string Surname, std::string NAme, std::string Patr) :surname(Surname), name(NAme), patronymic(Patr) {}
    bool operator<(const Author& other) const {
        return surname < other.surname;
    }
    bool operator==(const Author& other) const {
        return surname == other.surname && name == other.name && patronymic == other.patronymic;
    }
};

struct Book {
    int number;
    std::string title;
    std::list<Author> authors;
    int year;
    Book() {}
    Book(int number, std::string title, Author author, int year) :number(number), title(title), year(year) { authors.push_back(author); }
    bool operator<(const Book& other) const {
        return title < other.title;
    }
    bool operator==(const Book& other) const {
        return title == other.title && number == other.number && year == other.year && authors == other.authors;
    }

};

Book ReadDataFromString(const std::string& line) {
    Book book;
    std::istringstream iss(line);

    iss >> book.number;

    iss >> book.title;

    int authorCount;
    iss >> authorCount;

    for (int i = 0; i < authorCount; ++i) {
        Author author;
        iss >> author.surname >> author.name >> author.patronymic;
        book.authors.push_back(author);
    }

    iss >> book.year;

    book.authors.sort();

    return book;
}

std::list<Book> ReadDataFromFile(const std::string& filename) {
    std::list<Book> books;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error!!! File isn't opened " << std::endl;
        return books;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            Book book = ReadDataFromString(line);
            books.push_back(book);
        }
    }

    file.close();

    books.sort();


    return books;
}

void PrintBook(const Book& book) {
    std::cout << "Number: " << book.number << std::endl;
    std::cout << "Title: " << book.title << std::endl;
    std::cout << "Authors: ";

    for (const auto& author : book.authors) {
        std::cout << author.surname << " "
            << author.name << " "
            << author.patronymic << std::endl;
    }
    std::cout << "Year: " << book.year << std::endl;
    std::cout << std::endl;
}


void SearchByTitle(const std::list<Book>& books, const std::string& searchTitle) {

    bool found = false;
    for (const auto& book : books) {
        if (book.title.find(searchTitle) != std::string::npos) {

            std::cout << "Result for Title " << searchTitle << std::endl;

            PrintBook(book);
            found = true;
        }
    }

    if (!found) {
        std::cout << "No books found with this title." << std::endl;
    }
}



void SearchByAuthor(const std::list<Book>& books, const std::string authorSurname) {

    bool found = false;
    for (const auto& book : books) {
        for (const auto& author : book.authors) {
            if (author.surname == authorSurname) {

                std::cout << "Results for author: " << authorSurname << std::endl;
                PrintBook(book);
                found = true;
                break;
            }
        }
    }

    if (!found) {
        std::cout << "No books found for this author." << std::endl;
    }
}

void Add(const Book& b, std::list<Book>& l)
{
    l.push_back(b);
    l.sort();
}
void Add(const Author& a, std::list<Author>& l)
{
    l.push_back(a);
    l.sort();
}
void DeleteBook(const std::string& b, std::list<Book>& l) {
    for (const auto& book : l) {
        if (b == book.title) {
            l.remove(book);
            break;
        }
    }
}
void DeleteAuthor(const Author& a, std::list<Author>& l) {
    for (const auto& auth : l) {
        if (a == auth) {
            l.remove(auth);

        }
    }
}
int main() {
    const std::string File = "input.txt";


    std::list<Book> Library = ReadDataFromFile(File);

    if (Library.empty()) {
        std::cout << "no books in the library" << std::endl;
        return 1;
    }


    SearchByTitle(Library, "Coverage");

    SearchByAuthor(Library, "Bryl");

    for (auto i : Library) {
        PrintBook(i);
    }
    Author Bykau("Bykau", "Vasyl", "Uladzimiravich");
    Book Boo(7, "Sign_Of_trouble", Bykau, 1982);
    Add(Boo, Library);
    PrintBook(Boo);

    DeleteBook("Stained_glass_window", Library);
    for (auto i : Library)
    {
        PrintBook(i);
    }
    return 0;
}