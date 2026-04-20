#include<iostream>
using namespace std;
void check0(int);


int main(){
    int x,y;
	double d;	
	int a=1;
 do{

    try{
		int i;
		double * myarray;
		for(i=0;i<100000;i++){
			cout<<"Allocating memory .... "<<i<<endl;
			myarray= new double[500000000];

		}
		
		cout<<"Enter 2 numbers: ";
		cin>>x>>y;

		/* Curated Exception Handling */
		if(cin.fail()) throw 101 ; 
		if(abs(x)>1000 ||abs(y)>1000) throw "Value out of range"; 
		check0(y);
		a=0;
		/* Normal Code*/
		d=(double) x/y;
		cout<< "The result is " <<d<<endl;
		
		
   }
   catch(const char *error){
	 cerr<< error<<endl;

	
   }
  catch(const int e ){
		switch(e){
			case 101: cerr<<"Incorrect numbers "<<endl; break;
			case 0: cerr<<"Divided by zero"<<endl; break;
		}
		
		cin.clear();
        cin.ignore(50,'\n');
  }
  catch(...){
  	cout<<"Memory leak!!!!!"<<endl;
	a=0;

  }


 }while(a);
	return 0;
}



void check0(int x){

	if(x==0) throw(x);
}