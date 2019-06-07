#include <iostream>

int getwdsl(char* s,char p=' ',int a=0){
	if(*s=='\0')
		return a+1;
	if (('a'<=p&&p<='z')||('A'<=p&&p<='Z'))
		if(*s==' '){
			if(*s=='a'||*s=='e'||*s=='i'||*s=='o'||*s=='u'||*s=='y')
				a+=3;
			else
				a+=2;
		}
	return getwdsl(s+1,*s,a+1);
}

void pigl(char* s,char* p,char f=' '){
	if(f==' ')return pigl(s+1,(*p=f,p+1),*s);
	else if(*s==' '){
		if(f=='a'||f=='e'||f=='i'||f=='o'||f=='u'||f=='y')
			*p='w';
		else
			*p=f;
		*(p+1)='a';
		*(p+2)='y';
		return pigl(s+1,p+3,*s);
	}
	return pigl(s+1,p+1,f);
}

void display(char* p){
	if(*p=='\0')
		std::cout<<std::endl;
	else{
		std::cout<<*p;
		display(p+1);
	}

}

int main(int argc, char const *argv[]){
	int maxwlen=200;
	char s[maxwlen];
	std::cout<<"Enter text to convert to Pig-Latin:";
	std::cin.getline(s);
	int w=getwdsl(s)+1;
	char p[w];
	pigl(s,p);
	display(p+1);
	return 0;
}
