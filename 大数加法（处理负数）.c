#include<stdio.h>
#include<string.h>
char s1[150],s2[150];
int a1[150],a2[150],anss[150];
int flag,len1,len2,len; 
void tui1(){
	for(int i=0;i<len1-1;i++){
		s1[i]=s1[i+1];
	}
	if(len==len1&&len>len2) len--;
	len1--;
}
void tui2(){
	for(int i=0;i<len2-1;i++){
		s2[i]=s2[i+1];
	}
	if(len==len2&&len>len1) len--;
	len2--;
}
int pan(){
	if(len1>len2) return 1;
	if(len1<len2) return 2;
	if(len1==len2){
		for(int i=0;i<len;i++){
			if(s1[i]-s2[i]>0){
				return 1;
				break;
			}
			if(s1[i]-s2[i]<0){
				return 2;
				break;
			}
		}
	}
	return 0;
}
void Plus(){
	for(int i=0;i<len1;i++)
		a1[len1-1-i]=s1[i]-'0';
	for(int i=0;i<len2;i++)
		a2[len2-1-i]=s2[i]-'0';
	for(int i=0;i<len;i++){
		anss[i]+=a1[i]+a2[i];
		if(anss[i]>=10){
			anss[i+1]+=anss[i]/10;
			anss[i]=anss[i]%10;
		}
	}
	if(anss[len]!=0) len++;
}
void Alter(){
	char tmp[150]={0};
	for(int i=0;i<len1;i++) tmp[i]=s1[i];
	for(int i=0;i<len2;i++){
		s1[i]=s2[i];
		if(len1>len2){
			for(int j=len2;j<len1;j++) s1[j]='0';
		}
	}
	for(int i=0;i<len1;i++){
		s2[i]=tmp[i];
		if(len1<len2){
			for(int j=len1;j<len2;j++) s2[j]='0';
		}
	}
	int tmplen;
	tmplen=len1;len1=len2;len2=tmplen;
}
void Minus(int k){
	if(k==2) Alter();
	for(int i=0;i<len1;i++)
	    a1[len1-1-i]=s1[i]-'0';
	for(int i=0;i<len2;i++)
	    a2[len2-1-i]=s2[i]-'0';
	for(int i=0;i<len;i++){
		anss[i]+=a1[i]-a2[i];
		if(anss[i]<0){
			anss[i]+=10;
			anss[i+1]--;
		}
	}
	for(int i=len-1;i>=0;i--){
		if(anss[i]==0) len--;
		else break;
	}
}
int main(){
	scanf("%s",s1);
	getchar();
	scanf("%s",s2);
	len1=strlen(s1);len2=strlen(s2);
	if(len1>len2) len=len1;
	else len=len2;
	if(s1[0]!='-'&&s2[0]!='-'){
		flag=1;
		Plus();
	}
	if(s1[0]=='-'&&s2[0]=='-'){
		flag=-1;
		tui1();tui2();
		Plus();
	}
	if(s1[0]!='-'&&s2[0]=='-'){
		tui2();
		if(pan()==0){
			printf("0");
			return 0;
		}
		if(pan()==1){
			flag=1;
			Minus(1);
		}
		if(pan()==2){
			flag=-1;
			Minus(2);
		}
	}
	if(s1[0]=='-'&&s2[0]!='-'){
		tui1();
		if(pan()==0){
			printf("0");
			return 0;
		}
		if(pan()==1){
			flag=-1;
			Minus(1);
		}
		if(pan()==2){
			flag=1;
			Minus(2);
		}
	}
	if(flag==-1) printf("-");
	for(int i=len-1;i>=0;i--){
		printf("%d",anss[i]);
	}
	return 0;
}