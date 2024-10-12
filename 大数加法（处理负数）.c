#include<stdio.h>
#include<string.h>
int main(){
	char s1[210],s2[210];
	scanf("%s",s1);
	getchar();
	scanf("%s",s2);
	int size_1=strlen(s1);
	int size_2=strlen(s2);
	int a1[210]={0},a2[210]={0},a3[210]={0};
	if(s1[0]=='-'&&s2[0]=='-'){
		int len=size_1;
		if(size_2>size_1) len=size_2;
		for(int i=1;i<size_1;i++){
			a1[i]=s1[size_1-i]-'0';
		}
		for(int i=1;i<size_2;i++){
			a2[i]=s2[size_2-i]-'0';
		}
		for(int i=1;i<len;i++){
			a3[i]=a1[i]+a2[i];
		}
		for(int i=1;i<len;i++){
			if(a3[i]>=10){
				a3[i+1]+=a3[i]/10;
				a3[i]=a3[i]%10;
			}
		}
		if(a3[len]>0) len++;
		printf("-"); 
		for(int i=1;i<=len-1;i++){
			printf("%d",a3[len-i]);
		}
		return 0;
	}
	if(s1[0]!='-'&&s2[0]!='-'){
		int len=size_1;
		if(size_2>size_1) len=size_2;
		for(int i=0;i<size_1;i++){
			a1[i]=s1[size_1-i-1]-'0';
		}
		for(int i=0;i<size_2;i++){
			a2[i]=s2[size_2-i-1]-'0';
		}
		for(int i=0;i<len;i++){
			a3[i]=a1[i]+a2[i];
		}
		for(int i=0;i<len;i++){
			if(a3[i]>=10){
				a3[i+1]+=a3[i]/10;
				a3[i]=a3[i]%10;
			}
		}
		if(a3[len]>0) len++;
		for(int i=1;i<=len;i++){
			printf("%d",a3[len-i]);
		}
		return 0;
	}
}