#include<stdio.h>
#include<string.h>
int a[150],b[150],c[150],f1=1,f2=1,flag,len,m='0';
char s[150],s1[150],s2[150];
void pan();
void init();
void multy();
void plus();
void numcpy(int p[],int q[],int det);
int compare(int p[],int q[]);
void sub(int p[],int q[]);
void div(int a[],int b[],int c[]);
void print(int p[]);
int main(){
	scanf("%s",s);
	len=strlen(s);
	for(int i=1;i<=len;i++){
		if(m=='0'&&s[i-1]!='+'&&s[i-1]!='-'&&s[i-1]!='*'&&s[i-1]!='/'){
			s1[i]=s[i-1];
			a[0]++;
		}
		else if(m!='0') s2[i-a[0]-1]=s[i-1];
		else m=s[i-1];
	}
	b[0]=len-1-a[0];
	pan();
	init();
	if(m=='+'){
		if(f1*f2==1){
			plus();
			if(f1==-1) flag=-1;
			else flag=1;
			print(c);
			return 0;
		}
		if(f1*f2==-1){
			int k=compare(a,b);
			if(k==0){
				printf("0");
				return 0;
			}
			if(f1==-1){
				if(k==1){
					flag=-1;
					sub(a,b);
					print(a);
					return 0;
				}
				if(k==-1){
					flag=1;
					sub(b,a);
					print(b);
					return 0;
				}
			}
			if(f2==-1){
				if(k==1){
					flag=1;
					sub(a,b); 
					print(a);
					return 0;
				}
				if(k==-1){
					flag=-1;
					sub(b,a);
					print(b);
					return 0;
				}
			}
		}
	}
	if(m=='-'){
		if(f1*f2==-1){
			plus();
			if(f1==-1) flag=-1;
			else flag=1;
			print(c);
			return 0;
		}
		if(f1*f2==1){
			int k=compare(a,b);
			if(k==0){
				printf("0");
				return 0;
			}
			if(f1==-1){
				if(k==1){
					flag=-1;
					sub(a,b);
					print(a);
					return 0;
				}
				if(k==-1){
					flag=1;
					sub(b,a);
					print(b);
					return 0;
				}
			}
			if(f1==1){
				if(k==1){
					flag=1;
					sub(a,b);
					print(a);
					return 0;
				}
				if(k==-1){
					flag=-1;
					sub(b,a);
					print(b);
					return 0;
				}
			}
		}
	}
	if(m=='*'){
		flag=f1*f2;
		multy();
		print(c);
		return 0;
	}
	if(m=='/'){
		flag=f1*f2;
		div(a,b,c);
		print(c);
		return 0;
	}
}
void init(){
	for(int i=1;i<=a[0];i++)
		a[i]=s1[a[0]+1-i]-'0';
	for(int i=1;i<=b[0];i++)
		b[i]=s2[b[0]+1-i]-'0';
}
void pan(){
	if(s1[1]=='('){
		for(int i=1;i<a[0]-2;i++){
			s1[i]=s1[i+2];
		}
		a[0]-=3;f1=-1;
	}
	if(s2[1]=='('){
		for(int i=1;i<b[0]-2;i++){
			s2[i]=s2[i+2];
		}
		b[0]-=3;f2=-1;
	}
}
void numcpy(int p[],int q[],int det){
	for(int i=1;i<=p[0];i++)q[i+det-1]=p[i];
	q[0]=p[0]+det-1;
}
int compare(int p[],int q[]){
	if(p[0]>q[0]) return 1;
	if(p[0]<q[0]) return -1;
	for(int i=p[0];i>0;i--){
		if(p[i]>q[i]) return 1;
		if(p[i]<q[i]) return -1;
	}
	return 0;
}
void sub(int p[],int q[]){
	int ret;
	ret=compare(p,q);
	if(ret==0){
		p[0]=0;
		return;
	}
	if(ret==1){
		for(int i=1;i<=p[0];i++){
			if(p[i]<q[i]){
				p[i+1]--;
				p[i]+=10;
			}
			if(p[i]>=q[i]) p[i]-=q[i];
		}
		while((p[p[0]]==0)&&(p[0]>0)) p[0]--;
		return;
	}
}
void plus(){
	if(a[0]>=b[0]) c[0]=a[0];
	else c[0]=b[0];
	for(int i=1;i<=c[0];i++){
		c[i]+=a[i]+b[i];
		if(c[i]>=10){
			c[i+1]+=c[i]/10;
			c[i]=c[i]%10;
		}
	}
	if(c[c[0]+1]!=0) c[0]++;
}
void multy(){
	for(int i=1;i<=a[0];i++){
		for(int j=1;j<=b[0];j++){
			c[i+j]+=a[i]*b[j];
			c[i+j+1]+=c[i+j]/10;
			c[i+j]=c[i+j]%10;
		}
	}
	c[0]=a[0]+b[0];
	for(int i=c[0];i>=1;i++){
		if(c[i]==0) c[0]--;
		else break;
	}
	for(int i=1;i<c[0];i++){
		c[i]=c[i+1];
	}
	c[0]--;
	return;
}
void div(int a[],int b[],int c[]){
	int tmp[101];
	c[0]=a[0]-b[0]+1;
	for(int i=c[0];i>=1;i--){
		memset(tmp,0,sizeof(tmp));
		numcpy(b,tmp,i);
		while(compare(a,tmp)>=0){
			c[i]++;
			sub(a,tmp);
		}
		while((c[c[0]]==0)&&(c[0]>=1))
			c[0]--;
	}
}
void print(int p[]){
	if(p[0]==0){
		printf("0");
		return;
	}
	if(flag==-1)printf("-");
	for(int i=p[0];i>=1;i--)
		printf("%d",p[i]);
	return;
}