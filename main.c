#include <stdio.h>

/*Global Variables and typdefs*/

int head=0; 
int tail=0;

/*Function Prototype*/

void Write(char, char *);
void Read(char *);
void PrintBuffer(char *);

int main(){

    char Buffer[3];
    int Choice = 0;
    char data;

    while(Choice != 4){
        printf("Please Enter an Option:\n1=Write\n2=Read\n3=PrintBuffer\n4=Exit\n");
        scanf(" %d", &Choice);
        switch(Choice)
        {
            case 1:
            {
            printf("Please Enter your data:\n");
            scanf(" %c", &data);
            Write(data, Buffer);
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

void Write(char data, char *Buffer){
    
    int flag=0;
    if((head +1) % 4 == 0)
    {
        printf("inside\n");
        tail = head-1;
        head = 0;
        Buffer[head] = data;
        flag = 1;
             
    }
    if(flag == 1) 
    {
        head++;
    }
   
    if(flag == 0 && (head +1) % 4 != 0)
        {
            Buffer[head] = data;
            head++;
        }

    

        
    
    
    printf("Buffer[ %d ] is  : %c\n", head-1,Buffer[head-1] );
    
}

void Read(char *Buffer){

    printf("Last data is:%c\n", Buffer[head-1]);

}

void PrintBuffer(char *Buffer){
    



        if(tail ==2)
        {
            for(int i = 0; i <= tail; i++)
            {
                printf("%c ", Buffer[i]);
            }
        }
        else if(tail ==0)
        {
            for(int i = tail; i < head; i++)
            {
                printf("%c ", Buffer[i]);
            }
        }


        
    
}