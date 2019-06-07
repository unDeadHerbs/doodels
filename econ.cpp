#include <iostream>
#include <iomanip>

void S(int v,float p,int& n,int& t){
	if(v<1)return;
	std::cout
		<<std::fixed<<std::setw(20)<<std::setprecision(2)<<v/100.
		<<std::fixed<<std::setw(20)<<std::setprecision(2)<<((int)(v-v*p+1))/100.
		<<std::fixed<<std::setw(20)<<std::setprecision(2)<<((int)(v*p))/100.
		<<std::endl;
	S(v*p,p,++n,t+=v);
}

int main(){
	int v,n(0),t(0);
	float p;
	std::cout<<"Please enter initial value and percent expenditure:";
	std::cin>>v>>p;
	std::cout<<std::setw(20)<<"Amount of moneys recived"<<std::setw(20)<<"amount saved"<<std::setw(20)<<"amount spent"<<std::endl;
	S(v*100,p/100,n,t);
	std::cout<<"The money went though "<<n<<" people and a total of $"
					 <<std::fixed<<std::setprecision(2)<<t/100.<<" was spent."<<std::endl;
	std::cin.ignore();
	std::cout<<"Press enter to exit..."<<std::endl;
	std::cin.get();
	return 0;
}
