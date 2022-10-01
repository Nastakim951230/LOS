#include <stdio.h>
#include <malloc.h>

struct list
{
	int a;
	struct list* next;
};

typedef struct list* Los;

Los create(int n)
{
	Los los = calloc(1, sizeof(struct list));
	Los p1 = los;
	Los	p2;
	p1->a = 0;
	for (size_t i = 0; i < n; i++)
	{
		p2 = calloc(1, sizeof(struct list));
		p1->next = p2;
		p2->a = p1->a + 1;
		p1 = p2;
	}
	p1->next = NULL;
	return los;
}

//void deletLosI(Los los,Los i)
//{
//	struct list* temp;
//	temp = i;
//	while (temp->next != los) // просматриваем список начиная с корня
//	{ // пока не найдем узел, предшествующий lst
//		temp = temp->next;
//	}
//	temp->next = los->next; // переставляем указатель
//	free(los); // освобождаем память удаляемого узла
//	return(temp);
//}

void deletLosI(Los los, unsigned  n)
{
	/*Los i;
	while (los)
	{
		i = los->next;
		free(los);
		los = i;
	}*/
}


void addLos(Los los, unsigned  n,int r)
{
	unsigned i = 0;
	struct list* tmp = NULL;
	while (i < n && los->next) {
		los = los->next;
		i++;
	}
	tmp = calloc(1, sizeof(struct list));
	tmp->a = r;
	if (los->next) {
		tmp->next = los->next;
	}
	else {
		tmp->next = NULL;
	}
	los->next = tmp;
}


void showLos(Los los)
{
	while (los)
	{
		printf("%d ", los->a);
		los = los->next;
	}
	printf("\n");
}

void deletLos(Los los)
{
	Los i;
	while(los)
	{
		i = los->next;
		free(los);
		los = i;
	}
}

int main()
{
	
	Los los = create(10);
	showLos(los);

	addLos(los, 5,3);
	showLos(los);
	addLos(los, 9, 5);
	showLos(los);

	/*deletLosI(los,2);
	showLos(los);*/
	//deletLos(los);
	//system("pause");
	return 0;
}