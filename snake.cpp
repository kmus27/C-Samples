#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct position position;
typedef struct Nodo nodo;
typedef struct Snake snake;

struct position
{
	int x;
	int y;	
};

struct Nodo
{
	 position *pos;
	 nodo *front;
	 nodo *back;
	 int x;
	 int y;
};

struct Snake
{
	 nodo *head;
	 nodo *tail;
};


nodo* GetNode(){
	nodo *n =  (nodo*)(malloc(sizeof(nodo)));
	n->front = NULL;
	n->back = NULL;
	n->x = 0;
	n->y = 0;
	return n;
}

snake* GetSnake(){
	snake *s = (snake*)(malloc(sizeof(snake)));
	nodo *head = GetNode();
	nodo *tail = GetNode();
	nodo *body = GetNode();
	head->x = 2;
	head->y = 0;
	tail->x = 0;
	tail->y = 0;
	body->x = 1;
	body->y = 0;
	body->front = head;
	body->back = tail;
	head->back = body;
	tail->front = body;
	s->head = head;
	s->tail = tail;

}


void PrintSnake(nodo *c){
	if(c != NULL){
		cout<<c->x<<","<<c->y<<endl;
		PrintSnake(c->back);
	}
}
snake *s; 

int main(){
	s = GetSnake();
	PrintSnake(s->head);
	return 0;
}