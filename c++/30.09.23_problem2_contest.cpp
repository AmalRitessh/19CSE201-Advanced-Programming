#include <iostream>
using namespace std;

namespace LibraryManagement{
    struct book{
        string title;
        string author;
        int isbn;
    };
}

using namespace LibraryManagement;

namespace UserInterface{
    void  displayBookInfo(book book){
        cout<<"Name   : "<<book.title<<endl;
        cout<<"Author : "<<book.author<<endl;
        cout<<"ISBN   : "<<book.isbn<<endl;
    }
}

namespace Utilities{
    class date{
        int day;
        int month;
        int year;
        
        public:
        
        date(int dy,int mth,int yr){
            day=dy;
            month=mth;
            year=yr;
        }
        
        void isValidDate(date d){
            if (d.year>=1900&&d.year<=2099&&d.month>=1&&d.month<=12){
                if ((d.month==1||d.month==3||d.month==5||d.month==7||d.month== 8||d.month==10||d.month==12) && (d.day>=1&&d.day<=31))
                {
                    cout<<"valid"<<endl;
                    return;
                }
                else if((d.month==4||d.month==6||d.month==9||d.month==11) && (d.day>=1&&d.day<=30))
                {
                    cout<<"valid"<<endl;
                    return;
                }
            }
            cout<<"not valid"<<endl;
            return;
        }
    };
}

using namespace UserInterface;
using namespace Utilities;

int main() {
    //by namespace LibraryManagement we are storing data in book structure
    book book;
    book.title="abc";
    book.author="efg";
    book.isbn =1234;
    
    //by using namespace UserInterface we are displaying info book
    //with the book as ogject parameter
    displayBookInfo(book);
    
    //by using namespace Utilities we are checking valid date with the
    // help of date class
    date d1(30,9,2023);
    d1.isValidDate(d1);
    
    date d2(31,9,2023);
    d2.isValidDate(d2);
    
    date d3(31,10,2023);
    d3.isValidDate(d3);
    
    return 0;
}