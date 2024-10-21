#include<stdio.h>
#include<string.h>
int main(){
	char s1[150],s2[150],c;
	scanf("%s %c %s",s1,&c,s2);
	int len1=strlen(s1);
	int len2=strlen(s2);
	if(s2[0]=='('){
		for(int i=0;i<len2-2;i++){
			s2[i]=s2[i+1];
		}
		len2-=2;
	}
	for(int i=0;i<len1;i++){
		printf("%c",s1[i]);
	}
	printf("\n");
	for(int i=0;i<len2;i++){
		printf("%c",s2[i]);
	}
	printf("\n%c",c);
	return 0;
}