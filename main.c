#include <unistd.h>
#include <stdint.h>
#include <stdio.h>

typedef struct DataTransmission{
int32_t SendTime, SendInterval;
};

typedef struct ValuesParameters{
    int x;
    int y;
};


typedef struct LinkedList{
    int32_t StoreTime;
    int32_t StoreInterval;
    struct ValuesParameters value;
    struct LinkedList *next;
};
struct LinkedList *head = NULL;

void add(int32_t time,int32_t interval, struct ValuesParameters value){
   struct LinkedList *list, *temp;
   list=malloc(sizeof(struct LinkedList));
   list->StoreTime=time;
   list->StoreInterval=interval;
   list->value=value;

   if(head==NULL){
        head=list;
        head->next=NULL;
        return;
   }
   temp=head;
   while(temp->next !=NULL){
        temp=temp->next;
   }
   temp->next=list;
   list->next=NULL;
}

void print(){
    struct LinkedList *list;
    list=head;
    while(list!=NULL){
        printf("%d  %d %d %d",head->StoreTime,head->StoreInterval,head->value.x,head->value.y);
        list=head->next;
    }
}
int main()
{
    struct ValuesParameters firstparameter;

    firstparameter.x=5;
    firstparameter.y=9;

    add(1004,2345,firstparameter);
    print();
    printf("Hello world!\n");
    return 0;
}


