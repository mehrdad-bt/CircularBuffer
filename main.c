#include <stdio.h>
#define SIZE 8
/*Global Variables and typdefs*/

int head=0; 
int tail=0;
int count=0;

/*Function Prototype*/

void Write(char *);
void Read(char *);
void PrintBuffer(char *);

int main(){

    char Buffer[8];
    int Choice = 0;
    char data;

    while(Choice != 4){
        printf("\nPlease Enter an Option:\n1=Write\n2=Read\n3=PrintBuffer\n4=Exit\n");
        scanf(" %d", &Choice);
        switch(Choice)
        {
            case 1:
            {
            Write(Buffer);
            break;
            }
            
            case 2:
            {
                Read(Buffer);
                break;
            }

            case 3:
            {
                PrintBuffer(Buffer);
                break;
            }
        }
    }

    return 0;
}




void Write(char *Buffer){

    
    char data;


    if(count == SIZE)
    {
        printf("Buffer is full!\n");
        return;
    }

    printf("Please Enter your data:\n");
    scanf(" %c", &data);
    Buffer[head] = data;
    head = (head + 1) % 8;
    count++;

}


void Read(char *Buffer){

    if(count==0)
    {
        printf("Buffer is Empty !\n");
        return;
    }
    printf("Reading:%c\n", Buffer[tail]);
    Buffer[tail] = '\0';
    tail = (tail + 1) % 8;
    count--;
    

    

}

void PrintBuffer(char *Buffer){
    

    if(count==0)
    {
        printf("Buffer is Empty !\n");
        return;
    }

    for(int i = 0; i < 8; i++)
    {
        if(Buffer[i] == '\0')
        {
            continue;
        }
        printf(" %c", Buffer[i]);
    }
   
}