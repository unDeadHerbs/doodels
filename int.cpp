float f(float x){return /*function*/;}

float trap(int a, int b,int n){
	float val=0;
	for (float i=a; i<=b; i+=(b-a)/n){
		val+=f(i)*2;
	}
	val=val-f(a)-f(b);
	val=val*(a-b)/(2*n);
	return val;
}

float simp(int a,int b,int n){
	n%2?:n*=2;
	float val=0,d=(a-b)/n;
	for (int i=0; i<=n; i++){
		val+=f(a+i)*(d*n);
	}
}