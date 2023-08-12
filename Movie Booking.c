#include <stdio.h>
#include <conio.h>
#include <malloc.h>

struct ticket{
    struct ticket *next;
    char movie[20];
    char daydate[10];
    char Time[5];
    int seatno;
    int total;
};
int sum;
void display();
struct ticket *start=NULL;
struct ticket *create(struct ticket *);
struct ticket *displaylist(struct ticket *);
struct ticket *cancel(struct ticket *);
// MENU DISPLAY
void main()
{
    int ch;
    do
    {
      printf("\n--------------------------------------------------------------------------------------------");
      printf("\n");
      printf("\n!!!!!!!!!!!!!!!!!!!!!!!   Welcome to Cinematic Suite   !!!!!!!!!!!!!!!!!!!!!!");
      printf("\n------------ Cinematic Suite is a movie ticket booking system --------------------");
      printf("\n");
      printf("\n--------------------------------------------------------------------------------------------");
      printf("\n");
      printf("\n*******************************");
      printf("\n");
      printf("\n* MENU--------------->OPTIONS *");
      printf("\n* To book the ticket:------>1 *");
      printf("\n* To cancel the ticket----->2 *");
      printf("\n* To display the ticket---->3 *");
      printf("\n* Exit -------------------->4 *");
      printf("\n");
      printf("\n*******************************");
      printf("\n\t");
      printf("\n-------------------------------");
      printf("\nEnter your choice:\t");
      scanf("%d",&ch);
    
    switch(ch)
    {
        case 1: start=create(start);
                break;
        case 2: start=cancel(start);
                break;
        case 3: start=displaylist(start);
                break;
    }
    }while(ch!=4);
}
// TICKET PURCHASING
void display()
{
     int opt;
     char ch[50];
     printf("\n");
     printf("\n**********************************");
     printf("\n*   \t   MOVIE LIST              *");
     printf("\n*   \t                           *");
     printf("\n*   \t     3-IDIOTS              *");
     printf("\n*   \t     DANGAL                *");
     printf("\n*   \t       83                  *");
     printf("\n*   \t      URI                  *");
     printf("\n*   \t     TAMASHA               *");
     printf("\n*   \t                           *");
     printf("\n**********************************");
     
}
void seats()
{
     int opt;
     printf("\n-------------------------------------------------");
     printf("\nSelect Seats----> Prices---> Choices");
     printf("\nExecutive ------> ₹230----->    1");
     printf("\nPremium---------> ₹250----->    2");
     printf("\nVIP-------------> ₹450----->    3");
     printf("\n-------------------------------------------------");
     printf("\nEnter your choice:");
     scanf("%d",&opt);
     switch(opt)
     {
         case 1: sum=230;
                 break;
         case 2: sum=250;
                 break;
         case 3: sum=450;
                 break;
     }
     
}

struct ticket *create(struct ticket *start )
{
    display();
    struct ticket *booking,*ptr;
    
    booking=(struct ticket*)malloc(sizeof(struct ticket));
    printf("\nEnter the Movie Name : ");
    scanf("%s",booking->movie);
    printf("-----------------------------------------------");
    printf("\nChoose Your Date: ");
    printf("\n23 April-------->1");
    printf("\n24 April-------->2");
    printf("\n25 April-------->3");
    printf("\n---------------------------------------------");
    printf("\nEnter Date : ");
    scanf("%s",booking->daydate);
    printf("\n---------------------------------------------");
    printf("\nChoose your time: ");
    printf("\n3:00 PM--->1");
    printf("\n6:00 PM--->2");
    printf("\n9:00 PM--->3");
    printf("\n---------------------------------------------");
    printf("\nEnter Time : ");
    scanf("%s",booking->Time);
    seats();
    printf("\nEnter your seat number  between 1 to 10: ");
    scanf("%d",&booking->seatno);
    if (booking->seatno < 1 || booking->seatno>10)
    {
        printf("Invalid Seat No please enter again");
        main();
    }
    booking->total=sum;
    booking->next=NULL;
    ptr->seatno=booking->seatno;
    
    if (start==NULL)
    {
        start=booking;
    }
    else
    {
        ptr=start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=booking;
    }
    printf("Booking is done");
    return start;
    
}

struct ticket *cancel(struct ticket *start)
{
    int n,f=0;
    struct ticket *ptr,*preptr;
    ptr=start;
    printf("Enter the seat number which is to be deleted:");
    scanf("%d",&n);
    if (start==NULL)
    {
      printf("THE LIST IS EMPTY");
    }
    else
    { 
        while(ptr!=NULL)
        {
          if (ptr->seatno==n)
          {
            f++;
            break;
          }
          ptr=ptr->next;
        }
        
        if (f==1)
        {
            if (start->seatno==n)
            {
               ptr=start;
               start=start->next;
               free(ptr);
               printf("Booking cancelled");
            }
            else
            {
                ptr=start;
                while(ptr->seatno!=n)
                {
                    preptr=ptr;
                    ptr=ptr->next;
                }
                preptr->next=ptr->next;
                free(ptr);
                printf("Booking cancelled");
            }
        }
        else
        {
            printf("Seat Number not found");
        }
    }
    return start;
}


struct ticket *displaylist(struct ticket *start)
{
    
    if (start==NULL)
    {
        printf("The list is empty.");
    }
    else
    {
    struct ticket *ptr;
    ptr=start;
    printf("---------------------------------------------------------");
    printf("\nMovie Name\t Date \t Time \tSeat Number \t Total Cost  ");
    while(ptr!=NULL)
    {
        printf("\n %s\t\t",ptr->movie);
        printf(" %s\t",ptr->daydate);
        printf("%s\t",ptr->Time);
        printf(" %d\t\t",ptr->seatno);
        printf(" %d\t",ptr->total);
        ptr=ptr->next;
    }
    printf("\n------------------------------------------------------");
    }
    return start;
}















