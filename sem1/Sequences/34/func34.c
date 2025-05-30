#include "header34.h"
int func(FILE *f){
	double a,b;
	int cnt=-1,fcount=0;
	while (fscanf(f,"%lf", &a) == 1){
		if (cnt == -1){
			cnt = 1;
			fcount = cnt;
			
		}else if (cnt>0){
			if (a>b){
			fcount = cnt;
			cnt=0;
			}else if (a<b){
				cnt=1;
				fcount=1;
			}else if (a==b){
				cnt+=1;
				fcount = cnt;
			}
		}else if (cnt == 0 && a<b){
			cnt=1;
			fcount = cnt;
			
		}
		
		b=a;
	}
	return fcount;
}