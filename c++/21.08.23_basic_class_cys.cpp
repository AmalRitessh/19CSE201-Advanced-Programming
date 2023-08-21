#include <iostream>
using namespace std;

class cys{
    int rollno;
    string name;
    float cgpa;
    
    public:
        void adddetails(int r,string n,float c){
            rollno=r;
            name=n;
            cgpa=c;
        }
        
        void printdetails(){
            cout<<"roll number: "<<rollno<<endl;
            cout<<"name: "<<name<<endl;
            cout<<"cgpa: "<<cgpa<<endl;
        }
};

int main() {
    cys c;
    c.adddetails(44,"amal",7.1);
    c.printdetails();
}