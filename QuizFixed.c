#include <stdio.h>
#include <stdlib.h>

#define nil NULL

typedef int infotype;
typedef struct tElmtList *address;
typedef struct tElmtList {
    infotype info;
    address next;
} ElmtList;

void createNode(address *node, int nilai);
void insertFirst(address *Head, int nilai);
void insertLast(address *Head, int nilai);
void insertAfter(address *Head, int nilai, int nilaiAfter);
void deleteFirst(address *Head);
void deleteLast(address *Head);
void deleteTarget(address *Head, int target);
void deleteAll(address *Head);


void tampilList(address p);

int main() {
    address Head = nil;
    address A;

    // Membuat node A dan mengisi dengan nilai 10
    createNode(&A, 7);
    tampilList(Head);
        
    insertFirst(&Head, 7);
    tampilList(Head);
        
    insertLast(&Head, 11);
    tampilList(Head);
        
    insertAfter(&Head, 9, 7);
    tampilList(Head);
        
    insertFirst(&Head, 5);
    tampilList(Head);
    
    insertLast(&Head, 13);
    tampilList(Head);
    
    deleteLast(&Head);
    tampilList(Head);
        
    deleteTarget(&Head, 7);
    tampilList(Head);
        
    deleteFirst(&Head);
    tampilList(Head);
    
    deleteAll(&Head);
    tampilList(Head);


    // Bebaskan memori yang telah dialokasikan
    free(A);

    return 0;
}

void createNode(address *p, int nilai) {
    *p = (address)malloc(sizeof(ElmtList));

    if (*p == nil) 
	{
        printf("GAGAL ALOKASI MEMORI\n");
        return;
    }

    (*p)->info = nilai;
    (*p)->next = nil;
}

void insertFirst(address *Head, int nilai) {
    address newNode = (address)malloc(sizeof(ElmtList));

    if (newNode == nil) 
	{
        printf("GAGAL ALOKASI MEMORI\n");
        return;
    }

    newNode->info = nilai;
    newNode->next = *Head;
    *Head = newNode;
}

void insertLast(address *Head, int nilai) {
    address newNode = (address)malloc(sizeof(ElmtList));

    if (newNode == nil) 
	{
        printf("GAGAL ALOKASI MEMORI\n");
        return;
    }

    newNode->info = nilai;
    newNode->next = nil;

    if (*Head == nil) 
	{
        *Head = newNode;
    } else 
	{
        address temp = *Head;
        while (temp->next != nil) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAfter(address *Head, int nilai, int nilaiAfter){
	address newNode = (address)malloc(sizeof(ElmtList));
	newNode->info = nilai;
	
	address temp = *Head;
	
	while (temp != nil &&  temp->info != nilaiAfter)
	{
		temp=temp->next;
	}
	
	if (temp != nil)
	{
		newNode->next=temp->next;
		temp->next=newNode;
	}
}

void deleteFirst(address *Head) {
    if (*Head != nil)
	{ 
        address temp = *Head;   
        *Head = (*Head)->next;  
        free(temp);             
    }
}


void deleteLast(address *Head) {
    if (*Head == nil) { // Jika linked list kosong, langsung return
        return;
    }

    if ((*Head)->next == nil) { // Jika hanya ada satu node
        free(*Head);
        *Head = nil;
        return;
    }

    // Traversal untuk menemukan node sebelum yang terakhir
    address temp = *Head;
    while (temp->next->next != nil) {
        temp = temp->next;
    }

    free(temp->next); // Hapus node terakhir
    temp->next = nil; // Set node sebelumnya agar menjadi node terakhir
}


void deleteTarget(address *Head, int target){
	if(*Head == nil){
		return;
	}
	
	if ((*Head)->info == target){
		deleteFirst(Head);
		return;
	}
	
	address temp = *Head;
	while(temp->next != nil && temp->next->info != target){
		temp=temp->next;
	}
	
	if(temp->next != nil){
		address toDelete = temp->next;
		temp->next = toDelete->next;
		free(toDelete);
	}
}

void deleteAll(address *Head) {
    address temp;

    while (*Head != nil) {
        temp = *Head;    // Simpan alamat node saat ini
        *Head = (*Head)->next;  // Geser Head ke node berikutnya
        free(temp);      // Hapus node lama
    }

    *Head = nil; // Pastikan Head menjadi NULL setelah semua elemen dihapus
}


void tampilList(address p) {
    if (p == nil) 
	{
        printf("Linked list kosong\n");
        return;
    }

    while (p != nil) 
	{
        printf("%d -> ", p->info);
        p = p->next;
    }

    printf("NULL\n");
}

