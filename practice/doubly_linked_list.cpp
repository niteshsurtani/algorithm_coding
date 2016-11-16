#include <iostream>
using namespace std;

struct dll
{
	int num;
	dll *prev;
	dll *next;

	dll(int num1): num{num1}, prev{nullptr}, next{nullptr} {}

};

// dll* insertFront(dll *l, int num){
// 	dll *t= new dll();
// 	t->num = num;
// 	t->prev = NULL;
// 	t->next = l;

// 	if(l) l->prev = t;
// 	return t;
// }


// dll* insertEnd(dll *l, int num){
// 	dll *t= new dll();
// 	t->num = num;
// 	t->prev = NULL;
// 	t->next = NULL;

// 	if(!l) return t;

// 	while(l->next) l=l->next;

// 	t->prev = l;
// 	l->next = t;
// 	return l;
// }


// dll* insertElement(dll *l, int num){
// 	dll *t= new dll();
// 	t->num = num;
// 	t->prev = NULL;
// 	t->next = NULL;

// 	if(!l) return t;

// 	while(l->next && l->num < num) l=l->next;
// 	t->next = l->next;
// 	t->prev = l;

	
// 	if(l->next) l->next->prev = t;
// 	l->next = t;
// 	return l;
// }

// dll* deleteFront(dll *l, int num){
// 	return NULL;
// }


// dll* deleteEnd(dll *l, int num){
// 	return NULL;
// }


// dll* deleteElement(dll *l, int num){
// 	return NULL;
// }

// void print(dll *l){
// 	while(l!=NULL){
// 		cout << l->num << " -> ";
// 		l = l->next;
// 	}
// 	cout << endl;
// }

int main(){
	// dll *l;
	// l=NULL;
	// l = insertFront(l, 2);
	// l = insertFront(l, 1);
	// print (l);
	// l = insertEnd(l, 3);
	// l = insertEnd(l, 5);
	// cout << "here" << endl;
	// l = insertElement(l, 4);
	// print (l);

	return 0;
}