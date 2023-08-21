#include <iostream>
using namespace std;

class car{
    string error_name;
    int error_code;
    public:
        string modelname;
        float price;
        int yearofmanu;
        
    void getdetails(string m,float p,int y){
        modelname=m;
        price=p;
        yearofmanu=y;
    }
    
    void printdetails(){
        cout<<"model name: "<<modelname<<endl;
        cout<<"price: "<<price<<endl;
        cout<<"year of manufacture: "<<yearofmanu<<endl;
    }
};

int main() {
    
    car c;
    c.getdetails("tesela",20.5,2022);
    c.printdetails();
    
    /*
    car d;
    d.error_name="tyre";
    d.error_code=203;
    */
}