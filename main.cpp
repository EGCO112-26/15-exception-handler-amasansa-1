#include <iostream>
#include <exception>
using namespace std;

class div0:public exception{ //class จัดการ ตัวหารเป็น0
    public:
    virtual const char* what() const throw(){
        return "Divide by zero";
    }
};
class fail:public exception{ //class จัดการ cin.fail()
    public:
    virtual const char* what() const throw(){
        cin.clear();
        cin.ignore(50,'\n');
        return "Error: Incorrect input format!";
    }
};
class rangeFail:public exception{
    public:
    virtual const char* what() const throw(){ 
        return "Value out of range"; 
    }
};
void check0(int x){
	if(x==0) throw div0();
}
int main(){
    int x,y;
	double d;	
	int a=1;
    do{
        try{
            cout <<"Enter 2 numbers: ";
            cin >>x >>y;

            if(cin.fail()) throw fail(); 
            if(abs(x)>1000||abs(y)>1000) throw rangeFail(); 
            check0(y);
            a=0;
            d=(double) x/y;
            cout <<"The result is " <<d <<endl; 
            int i;
            double * myarray;
            for(i=0; i<100000; i++) {
                cout <<"Allocating memory .... " <<i <<endl;
                myarray=new double[5000000000ULL]; 
            }
            a=0;
        }
        // catch(const char *error){
        //     cerr <<error <<endl;
        // }
        // catch(const int e){
        //     switch(e){
        //         case 101: cerr <<"Incorrect numbers " <<endl; break;
        //         case 0: cerr <<"Divided by zero" <<endl; break;
        //     }
        //     cin.clear();
        //     cin.ignore(50,'\n');
        // }
        catch(exception &e){
            cerr <<e.what() <<endl;
            string msg=e.what();
            if(msg=="std::bad_alloc" || msg=="Divided by zero"){
                a=0; 
            }else{
                a=1;
            }
        }
    }
    while(a);
    return 0;
}