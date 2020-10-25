#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100000
int checker(char *p)
{
	char *q = p;
	int type_1,type_2,type_3;
	type_1 = type_2 = type_3 = 0;
	while(*q){
		if(type_1 < 0 || type_2 < 0 || type_3 < 0){
			return(0);
		}
		switch(*q){
			case '(':
				type_1++;
				break;
			case ')':
				type_1--;
				break;
			case '{':
				type_2++;
				break;
			case '}':
				type_2--;
				break;
			case '[':
				type_3++;
				break;
			case ']':
				type_3--;
				break;

		}
		q++;
	}
	if(!type_1 && !type_2 && !type_3)
	{
		return(1);
	}
	return(0);
}




int main(int argc, char const *argv[])
{
	int n;
	scanf("%i",&n);
	while(n--){
		char *par = (char*)malloc(MAXSIZE);
		scanf("%s",par);
		if(checker(par)){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}