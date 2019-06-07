#include <iostream>

  /*-------------------------------------------/
 / Calculate the Y value for a Given X Value  /
/-------------------------------------------*/

float f(float x){
	return x*x*x-5*x;
}/**/


  /*------------------------------------------/
 / Estamatie Good Bounds for the Aprximation /
/------------------------------------------*/
void get_bounds(float* l,float* r){
	for(;f(*l)*f(*r)>0;(*r)++){}
}/**/

  /*-------------------------------------------------/
 / Find A Zero of the Funciton to a Given Tolerence /
/-------------------------------------------------*/
float findzero(float tol,float l,float r){
	for(;tol<l-r||l-r<-tol;){
		if(f((l+r)/2)==0)
			break;
		if(f(l)*f((l+r)/2)>0){
			l=(l+r)/2;
		}else{
			r=(l+r)/2;
		}
	}
	return (l+r)/2;
}/**/


  /*--------------------------------------------------/
 / This Program Estimatimates the Zero of a Function /
/--------------------------------------------------*/
int main(){
	float tol=.00001,zerox,l=1,r=2;
	get_bounds(&l,&r);
	zerox=findzero(tol,l,r);
	std::cout<<"final guess: "<<zerox<<std::endl;
	return 0;
}/**/