int readRot(int pos,int rot,int* data,int sidelength=3){
	switch(rot%4){
	case 0:
		//read as is
		return data[pos%sidelength][pos/sidelength];
	case 1:
		//switch left and right then transpose
		return data[sidelength-pos/sidelength][pos%sidelength];
	default:
		//read everyting in reverse order and try again
		return readRot(sidelength*sidelength-pos,rot-2,data,sidelength);
	}
}

auto euRearange(int*data,int*to,const int sidelength=3){
	bool ndone[sidelength*sidelength];
	for(int i=0;i<sidelength*sidelength;i++)ndone[i]=true;
	int tmp;
	for(int d=0;d!=sidelength*sidelength;d++){
		int p=d;
		while(ndone[p]){
			if(not ndone[to[p]])
				tmp=data[p];
			p=to[p];
		}
		while(ndone[p]){
			data[p]=tmp;
			tmp=data[to[p]];
			ndone[p]=false;
			p=to[p];
		}
	}
}

auto euRearange(int*data,int**to,const int dims,const int* sidelengths){
	int v=1;
	for(int i=0;i<dims;i++)v*=sidelengths[i];
	bool ndone[v];
	for(int i=0;i<v;i++)ndone[i]=true;
	int tmp,t;
	for(int d=0;d!=v;d++){
		int p=d;
		while(ndone[p]){
			if(not ndone[to[p]])
				tmp=data[p];
			t=0;
			for(int i=0;i<dims;i++){
				t+=to[d][i];
				t*=sidelengths[i];
			}
			p=t;
		}
		while(ndone[p]){
			data[p]=tmp;
			t=0;
			for(int i=0;i<dims;i++){
				t+=to[d][i];
				t*=sidelengths[i];
			}
			tmp=data[t];
			ndone[p]=false;
			p=t;
		}
	}
}
