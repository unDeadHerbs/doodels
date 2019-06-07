#include <stdio.h>

int main(int argc, char *argv[]){
	char *p;
	int i;
	for (i = 0; i < 4; ++i){
		switch(i){
		case 1:
			p="one";
			if(0)
		case 2:
				p="two";
			if(0);
		case 3:
			p="three";
			printf("%s",p);
		}
	}
	return 0;
}
