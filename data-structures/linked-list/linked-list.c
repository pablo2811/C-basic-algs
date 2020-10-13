#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10000
#define MAXSTR 500


struct worker
{
	char *name;
	int age;
	int salary;
};

struct node
{
	struct node *prev;
	struct node *next;
	struct worker value;

};

struct ll
{
	struct node *head;
	struct node *tail;
	
};

void print_salaries(struct ll *list)
{
	struct node *current = (*list).head;
	while(current != NULL)
	{
		printf("Employee: %s Salary: %i\n", current->value.name,current->value.salary);
		current = current->next;
	}

}
void add_employee(struct ll *list,char *name,int age,int salary)
{	
	struct worker new_worker = {name,age,salary};
	struct node *new_node = (struct node *) malloc(sizeof(struct node));
	new_node -> next = NULL; // (*new_node).next = NULL
	new_node -> value = new_worker;
	if(list -> head == NULL && list -> tail == NULL)
	{
		list -> head = list -> tail = new_node;
	}else{
		list -> tail -> next = new_node;
		list -> tail = new_node;
	}
	
}


int main()
{
	struct ll *company = (struct ll *)malloc(sizeof(struct ll));
	add_employee(company,"Steve Jobs",100,1);
	add_employee(company,"Kacper Wojtacha",20,200);
	add_employee(company,"Paweł Fijałkowski",12,100);
	add_employee(company,"Królik Bucks",23,300);
	print_salaries(company);

}