#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

struct list;
typedef struct list* Position;
typedef struct list {
	int br;
	Position next;
}_list;

void push(Position, int);
void pop(Position);
void print(Position);
int createRandom();


int main() {
	_list head;
	_list stogHead;
	head.next = NULL;
	stogHead.next = NULL;
	Position prevToLast = &head;
	char a = ' ';
	char b, temp;
	int broj = 0;

	while (a != '\n') {
		printf("Zelite li urediti stog(S) ili red(R)?\nZa izlaz pritisnite enter\n");
		a = getchar();
		temp = getchar(); //compiler pamti enter kojeg ovdje pohrani da dalje ne smeta

		switch (toupper(a)) {
		case 'S':
			printf("Zelite li dodati(D) ili skinuti(S) element?\n");
			scanf(" %c", &b);
			switch (toupper(b)) {
			case 'D':
				broj = createRandom();
				push(&stogHead, broj);
				break;

			case 'S':
				pop(&stogHead);
				break;

			default:
				printf("Pogresan unos, unesite D ili S!");
				break;
				
				
			}
			break;

		case 'R':
			printf("Zelite li dodati(D) ili skinuti(S) element?\n");
			scanf(" %c", &b);
			switch (toupper(b)) {
			case 'D':
				broj = createRandom();
				push(&head, broj);

				if(prevToLast->next != NULL)
				prevToLast = prevToLast->next;
				
				break;

			case 'S':
				pop(prevToLast);
				break;

			default:
				printf("Pogresan unos, unesite D ili S!");
				break;
			
			}
			break;

		case '\n':
			break;

		default:
			printf("Pogresan unos!");
			break;
		}
		printf("Stog: ");
		print(&stogHead);
		printf("\nRed: ");
		print(&head);
		printf("\n");
		temp = getchar(); //compiler pamti enter kojeg ovdje pohrani da dalje ne smeta
	}
}

void push(Position p, int n) {
	Position q = NULL;
	q = (Position)malloc(sizeof(Position));

	if (q == NULL) {
		printf("Greska pri alokaciji!");
		return -1;
	}

	q->br = n;

	q->next = p->next;
	p->next = q;
}

void pop(Position p) {
	if (p->next == NULL) {
		printf("Lista je vec prazna!");
		return;
	}
	Position temp = p->next;
	p->next = temp->next;
	free(temp);
}

int createRandom() {
	srand(time(0));

	int a = rand() % 91 + 10;

	return a;
}

void print(Position p) {
	p = p->next;

	while (p != NULL) {
		printf("%d ", p->br);
		p = p->next;
	}
}