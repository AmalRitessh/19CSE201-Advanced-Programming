#include <iostream>
using namespace std;

class Book{
    string title;
    string author;
    string ISBN;
    bool isAvilable;
    public:
    Book(){
        cout<<""<<endl;
    }
    Book(string t,string a,string id,bool avil){
        title=t;
        author=a;
        ISBN=id;
        isAvilable=avil;
    }
    
    void displaybook(Book b){
        string temp;
        if (b.isAvilable==1){
            temp="avilable";
        }
        else{
            temp="not avilable";
        }
        cout<<b.title<<" | "<<b.author<<" | "<<b.ISBN<<" | "<<temp<<endl;
    }
    
    int check(int no,string isbn,Book book){
        if(no==1)/*remove book*/{
            if(isbn==book.ISBN){
                return 1;
            }
        }
        else if(no==2)/*check out book*/{
            if(isbn==book.ISBN){
                if(book.isAvilable==1){
                    return 1;
                }
                else{
                    return 0;
                }
            }
        }
        else if(no==3)/*return book*/{
            if(isbn==book.ISBN){
                if(book.isAvilable==0){
                    return 1;
                }
                else{
                    return 0;
                }
            }
        }
        else if(no==4)/*search book*/{
            if(isbn==book.title){
                return 1;
            }
        }
    }
    
    string value(int a,Book book){
        if(a==1){
            return book.title;
        }
        else if(a==2){
            return book.author;
        }
        else if(a==3){
            return book.ISBN;
        }
    }
};

class Library : protected Book{
    Book b[50];
    int i=0,j;
    
    public:
    
    void addBook(Book book){
        b[i]=book;
        i++;
    }
    void removeBook(string ISBN){
        Book b2;
        for(j=0;j<i;j++){
            int k=b2.check(1,ISBN,b[j]);
            if (k==1){
                for(int k=j;k<i;k++){
                    b[k]=b[k+1];
                }
                i--;
                cout<<ISBN<<" Book has been removed"<<endl;
                break;
            }
        }
    }
    void checkoutBook(string ISBN){
        Book b2;
        int k;
        for(j=0;j<i;j++){
            k=b2.check(2,ISBN,b[j]);
            if (k==1){
                cout<<ISBN<<" Book has been checked out"<<endl;
                update(0,j);
                break;
            }
        }
        if(k==0){
            cout<<"The book is not avilable for you to checkout"<<endl;
        }
    }
    void returnBook(string ISBN){
        Book b2;
        int k;
        for(j=0;j<i;j++){
            k=b2.check(3,ISBN,b[j]);
            if (k==1){
                cout<<ISBN<<" Book has been returned"<<endl;
                update(1,j);
                break;
            }
        }
        if(k==0){
            cout<<"Yo bro that book is avilabe, than aint library's book"<<endl;
        }
    }
    void searchBook(string title){
        Book b2;
        cout<<"TITLE | AUTHOR | ISBN | AVILABLITY"<<endl;
        for(j=0;j<i;j++){
            int k=b2.check(4,title,b[j]);
            if (k==1){
                displaybook(b[j]);
                break;
            }
        } 
    }
    void displayCatalog(){
        cout<<"TITLE | AUTHOR | ISBN | AVILABLITY"<<endl;
        for(j=0;j<i;j++){
            displaybook(b[j]);
        }
    }
    
    void update(int a,int c){
        Book bt;
        
        string temp_title=bt.value(1,b[c]);
        string temp_author=bt.value(2,b[c]);
        string temp_ISBN=bt.value(3,b[c]);
        bool temp_isAvilable=a;
        
        Book bt1(temp_title,temp_author,temp_ISBN,temp_isAvilable);
        b[c]=bt1;
    }
};

int main(){
    //default books in library.
    Book b1("avatar-1","amal","10-1",true);
    Book b2("avatar-2","ritessh","10-2",true);
    Book b3("avatar-3","ananth","10-3",true);
    Book b4("avatar-4","shravan","10-4",true);
    Library l;
    l.addBook(b1);
    l.addBook(b2);
    l.addBook(b3);
    l.addBook(b4);

    cout<<"1.Add a new book to the library."<<endl;
    cout<<"2.Remove a book from the library."<<endl;
    cout<<"3.Check out a book."<<endl;
    cout<<"4.Return a book."<<endl;
    cout<<"5.Search for a book by title."<<endl;
    cout<<"6.Display the library's catalog."<<endl;
    cout<<"7.Exit the program."<<endl;
    
    int loop=1;
    while(loop=1){
        int a;
        string isbn,title,author;
        bool avil;
        cout<<"Enter choice: ";
        cin>>a;
        if(a==1)/*add book*/{
            cout<<"Title: ";
            cin>>title;
            cout<<"Author: ";
            cin>>author;
            cout<<"ISBN: ";
            cin>>isbn;
            cout<<"Avilability(0 or 1): ";
            cin>>avil;
            Book b5(title,author,isbn,avil);
            l.addBook(b5);
        }
        else if(a==2)/*remove book*/{
            cout<<"Enter ISBN of the book: ";
            cin>>isbn;
            l.removeBook(isbn);
        }
        else if(a==3)/*check out book*/{
            cout<<"Enter ISBN of the book: ";
            cin>>isbn;
            l.checkoutBook(isbn);
        }
        else if(a==4)/*return book*/{
            cout<<"Enter ISBN of the book: ";
            cin>>isbn;
            l.returnBook(isbn);
        }
        else if(a==5)/*search book*/{
            cout<<"Enter title of book: ";
            cin>>title;
            l.searchBook(title);
        }
        else if(a==6)/*display catlog*/{
            l.displayCatalog();
        }
        else if(a==7)/*exit*/{
            cout<<"exit"<<endl;
            break;
        }
        else/*error message*/{
            cout<<"realy nigga ?, there are only 7 options."<<endl;
        }
    }
}
