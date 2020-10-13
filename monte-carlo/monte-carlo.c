#include <stdio.h>
#include <math.h>
#include <stdlib.h>
struct point
{
	double x;
	double y;
};

double distance(struct point p1,struct point p2)
{
	return pow(pow(p1.x-p2.x,2) + pow(p1.y-p2.y,2),0.5);
}

double monte_carlo_pi(int n)
{
	int counter = 0;
	double x,y;
	struct point mid = {0.5,0.5};
	for(int x = 0; x < n; x++)
	{
		x = (double)rand() / (double)RAND_MAX;
		y = (double)rand() / (double)RAND_MAX;
		struct point temp = {x,y};
		if(distance(mid,temp) <= 0.5){
			counter++;
		}

	}
	return (double)(counter) / (double)(n);
}


int main(int argc, char const *argv[])
{
	printf("%f\n",monte_carlo_pi(10000));
	return 0;
}