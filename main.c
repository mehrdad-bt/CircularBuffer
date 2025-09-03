#include <stdio.h>

/*Global Variables and typdefs*/

int head=0; 
int tail=0;
int flag =0;

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

    if(head == 0 && tail == 0)
    {        
        printf("Please Enter your data:\n");
        scanf(" %c", &data);
        Buffer[head] = data;
        head++;

        return;
    }

        printf("Please Enter your data:\n");
        scanf(" %c", &data);
        
        if((head+1) % 8 == 0)
        {  
            Buffer[head] = data;
            tail++;
            head = 0;
            flag = 1;
            return;
        }

        Buffer[head] = data;
        if(flag == 0)
        {
            tail = head;
        }
        flag = 0;
        
        head++;
 

}


void Read(char *Buffer){


    if(tail == 0 || ((flag == 0) && (tail == 7)))
    {
        printf("Last data is:%c\n", Buffer[tail]);
    }
    else
    {
        printf("Last data is:%c\n", Buffer[tail-1]);
    }
    

}

void PrintBuffer(char *Buffer){
    

    for(int i = 0; i < 8; i++)
    {
        printf(" %c", Buffer[i]);
    }
   
}