#include <stdio.h>
#include <stdlib.h>
#define nil NULL

typedef int infotype;
typedef struct tElmtList *address;
typedef struct tElmtList{
	infotype info;
	address next;
}ElmtList;
	
void createNode(address *node);
void insertFirst(address *Head, int nilai);
void insertLast(address *Head, int nilai);
void tampilList(address p);
	


int main(){
	address Head;
	address A, B;
	
	createNode(&A);
	tampilList(&	A);
	
	
	free(&A);
}

void createNode(address *p){
	*p = (address)malloc(sizeof(ElmtList));

	if(*p == NULL) { // Fixed condition check
		printf("GAGAL ALOKASI MEMORI\n"); // Better error message
	}
}

void insertFirst(address *Head, int nilai){
	address Anjay;
	Anjay=(address)malloc(sizeof(ElmtList));
	Anjay->info=nilai;
	Anjay->next=nil;
}

void insertLast(address *Head, int nilai){
	address temp;
	address Baru;
	
	Baru = (address)malloc(sizeof(ElmtList));
	Baru->info=nilai;
	Baru->next=nil;
	
	if (Head==nil){
		*Head=Baru;
	}else{
		temp = (address)malloc(sizeof(ElmtList));
		temp = *Head;
		while (temp->next != nil){
			temp = temp->next;
		}
	}
}

void tampilList(address p) {
// Tujuan : Menampilkan seluruh isi Linked List
// Parameter : p (parameter input)
	if(p == NULL) {
		printf("Linked list kosong\n");
		return; // Added return to avoid printing "NULL" for empty lists
	}
	
	// Pointer temporary untuk iterasi
	address temp = p;
	while(temp != NULL) {
		printf("%d -> ", temp->info);
		temp = temp->next;
	}
	
	printf("NULL\n");
}
