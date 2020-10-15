#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 5000


int len(char *tab)
{	
	int i;
	for(i = 0; *tab != '\0';i++);
	return(i);
}

int ppow(int a, int b)
{
	int res = 1;
	for(int x = 0; x < b; x++)
	{
		res *= a;
	}
	return(res);
}


int char_to_int(char *tab)
{
	int l = len(tab);
	int res = 0, iter = 0;
	int mult = ppow(10,l-1);
	while(*tab != '\0')
	{
		res += (int)(*tab) * mult;
		mult /= 10;
		iter++;
		tab++;
	}
	return(res);
}
int compare(char *tab1, char *tab2)
{
	if (len(tab1) != len(tab2))
	{
		return(0);
	}
	while(*tab1 == *tab2 && *tab1 != '\0')
	{
		tab1++;
		tab2++;
	}
	if(*tab1 == '\0')
	{
		return(1);
	}
	return(0);

}
int get_line(char* line)
{
	char current = getchar();
	int x;
	for(x = 0; current != EOF && current != '\n' && x < MAXLINE;x++,line++)
	{
		*line = current;
		current = getchar();
	}
	if(x == MAXLINE){
		return(-1);
	}else if(current == EOF || x == 1)
	{
		return(-2);

	}else
	{
		*line = '\0';
		return(x);
	}
}

void execute(char *lines[],int N)
{
	for(int x = 0; x < N; x++)
	{
		lines[x] = (char *) malloc(sizeof(char)*MAXLINE);
	}
	int i = 0;
	while(1)
	{
		if(i == N)
		{
			lines -= N;
			i = 0;
		}
		int z = get_line(*lines);
		switch(z)
		{
			case(-1):
				printf("String is too long to process\n");
			case(-2):
				break;
		}
		i++;
		lines++; 
	}
	for(int x = 0; x < N; x++,lines++){
		if(i + x == N)
		{
			lines -= N;
		}
		printf("%s\n",*lines);
	}

}




int main(int argc,char *argv[])
{
	int N = 5;
	argv++;
	if (argc == 1 || argc == 3)
	{
		if(argc == 3)
		{
			if(compare(*argv,"-n"))
			{
				N = char_to_int(*(argv++));
			}
			else
			{
				printf("Improper usage tail [-n].\n");
			}
		}
	}
	else
	{
		printf("Improper usage tail [-n].\n");
	}
	char *lines[N];
	execute(lines,N);


}

