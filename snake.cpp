#include <stdlib.h>
#include <iostream>
#define top -1
#define left -2
#define bottom 1
#define right 2
using namespace std;

typedef struct Nodo nodo;
typedef struct Snake snake;

snake *s; 
int position = right;

struct Nodo
{
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

void updatePosition(){
	nodo* newHead = GetNode();
	s->tail = s->tail->front;
	s->tail->front->back = s->tail;
	s->tail->back = NULL;
	newHead->x = ((position == left || position == right) ? (s->head->x + position/2) : s->head->x  );
	newHead->y = ((position == top || position == bottom) ? (s->head->y + position) : s->head->y );
	newHead->back = s->head;
		cout<<position<<" "<<newHead->x<<" "<<s->head->x<<(s->head->x + position/2)<<endl;

	s->head->front = newHead;
	s->head = newHead;
}

void PrintSnake(nodo *c){
	if(c != NULL){
		cout<<c->x<<","<<c->y<<endl;
		PrintSnake(c->back);
		
	}
}


int main(){
	s = GetSnake();
	position = right;
	PrintSnake(s->head);
	updatePosition();
	position = bottom;
	updatePosition();
	cout<<"---------------------"<<endl;
	PrintSnake(s->head);
	return 0;
}