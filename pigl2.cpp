#include <iostream>

bool vowl(char c){
	if(c=='a') return true;
	if(c=='e') return true;
	if(c=='i') return true;
	if(c=='o') return true;
	if(c=='u') return true;
	if(c=='y') return true;
	if(c=='A') return true;
	if(c=='E') return true;
	if(c=='I') return true;
	if(c=='O') return true;
	if(c=='U') return true;
	if(c=='Y') return true;
	return false;
}

bool alpha(char c){
	//just use c in [a,z]union[A,Z]
	if(vowl(c)) return true;
	if(c=='q')return true;
	if(c=='w')return true;
	if(c=='r')return true;
	if(c=='t')return true;
	if(c=='p')return true;
	if(c=='s')return true;
	if(c=='d')return true;
	if(c=='f')return true;
	if(c=='g')return true;
	if(c=='h')return true;
	if(c=='j')return true;
	if(c=='k')return true;
	if(c=='l')return true;
	if(c=='z')return true;
	if(c=='x')return true;
	if(c=='c')return true;
	if(c=='v')return true;
	if(c=='n')return true;
	if(c=='m')return true;
	if(c=='Q')return true;
	if(c=='W')return true;
	if(c=='R')return true;
	if(c=='T')return true;
	if(c=='P')return true;
	if(c=='S')return true;
	if(c=='D')return true;
	if(c=='F')return true;
	if(c=='G')return true;
	if(c=='H')return true;
	if(c=='J')return true;
	if(c=='K')return true;
	if(c=='L')return true;
	if(c=='Z')return true;
	if(c=='X')return true;
	if(c=='C')return true;
	if(c=='V')return true;
	if(c=='N')return true;
	if(c=='M')return true;
	return false;
}

int getwdsl(char* s,char p=' ',int a=0){
	if(*s=='\0')
		return a+1;
	if (alpha(p))
		if(*s==' '){
			if(vowl(*s))
				a+=3;
			else
				a+=2;
		}
	return getwdsl(s+1,*s,a+1);
}

int cn(char*s,int a=0){
	if(vowl(*s)) return a;
	return cn(s+1,a+1);
}

void pigl(char* s,char* p,char *f=0){
	if(f==0) return pigl(s+1,p,s);
	if(*f=='\0') return;
	if(*f==' ') return pigl(s+cn(s),(*p=*f,p+1),s);
	else if(*s==' '){
		if(vowl(*f))
			*p='w';
		else
			for (;vowl(*f)==false;)
				*(p++)=*(f++);
		*(p++)='a';
		*(p++)='y';
		return pigl(s+1,p+3,s);
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
	std::cin.getline(s,maxwlen);
	int w=getwdsl(s);
	char p[w];
	pigl(s,p);
	display(p);
	return 0;
}
