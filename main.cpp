#include <iostream>
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
			for(i=0;i<100000;i++)
			{
				cout << "Allocating memory .... " << i <<endl;
				myarray=new double[500000000];
			}
			cout << "Enter 2 number:";
			cin>>x>>y;
			if(cin.fail()){
				// cerr<<"Incorrect type entered"; return 1;
				throw "Incorrect type entered";
			}
			if(abs(x)>1000 ||abs(y)>1000){
				// cerr<<"Value out of range"; return 1;
				throw "Value out of range";
			}
			check0(y);
			// if(y==0){
			// 	// cerr<< "Error divide by zero"; return 1;
			// 	throw "Error divide by zero";
			// }
			a=0;
			d=(double) x/y;
			cout<< "The result is" <<d <<endl;
		}
		catch(const char* error){//catch มีได้หลายอัน
			cerr << error <<endl;
		}
		catch(int e){
			switch(e){
				case 101: cerr<<"Incorrect numbers" <<endl; break;
				case 0: cerr<<"Divide by zero" <<endl; break;
			}
			cin.clear();
			cin.ignore(50,'\n');
		}
		catch(...){
			cout << "Memory leak!!!!!"<<endl;
			a=0;
		}
	}
	while(a);
	return 0;
}

void check0(int x){
	if(x==0) throw x;
}