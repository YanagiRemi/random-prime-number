#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int power(int o,int l,int n){
	int j,q=1;
	o=o%n;
	if(o==0){
		return 0;
	}
	if(l==0){
		return q%n;
	}
	for(j=0;j<l;j++){
		q*=o;
		if(q>=n){
			q%=n;
		}
	}
	return q;
}

int Mirrer(int p,int S){
	int i,k,a;
	int x,y;
	if(p>2&&p%2==0){
		return 0;
	}
	else{
		int v=p-1;
		int u=0;
		while(v%2==0){
			v=v/2;
			u++;
		}
		for(i=1;i<=S;i++){
			a=rand()%(p-1)+1;
			if(power(a,p-1,p)!=1){
				return 0;
			}
			for(k=1;k<=u;k++){
				x=v*(int)pow(2,k);
				y=v*(int)pow(2,k-1);
				if(power(a,x,p)==1 && power(a,y,p)!=1 && (power(a,y,p)-p)!=-1){
					return 0;
				}
			}
			if(i==S){
				return 1;
			}
		}
	}
}
void main(){
	int n,z;
	printf("ビット数を入力: ");
	scanf("%d",&n);
	srand((unsigned int)time(NULL));
	for(int i=1;i<=3*pow(n,2);i++){
		z=rand()%(int)pow(2,n-1);
		z=z+(int)pow(2,n-1);
		if(Mirrer(z,n)==1){
			printf("素数: %d",z);
			break;
		}
	}
}
