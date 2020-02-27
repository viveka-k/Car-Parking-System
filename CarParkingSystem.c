#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct vehicle
{
    int num ;
    int row ;
    int col ;
} ;

int parklot[4][10] ;
int vehcount ;
int amount;

void display( ) ;
void counter( );
struct vehicle * add ( int, int, int ) ;
void del ( struct vehicle *v ) ;
void getfreerowcol ( int, int * ) ;
void getrcbyinfo ( int, int, int * ) ;

struct vehicle * add ( int num, int row, int col )
{
    struct vehicle *v ;
    v = ( struct vehicle * ) malloc ( sizeof ( struct vehicle ) ) ;
    v -> row = row ;
    v -> col = col ;
    vehcount++ ;
    parklot[row][col] = num ;
    return v ;
}

void display( )
{
    int r, c, i, j ;
    for ( r = 0 ; r <= 4 ; r++ )
    {
	if ( r == 0)
	{
		for(i=0;i<12;i++)
		printf ( "\xDB\xDB\xDB\xDB\xDB" ) ;
		printf("  EXIT  \xDB\xDB");
	}
	printf("\n");
	if ( r == 2 )
	{
	   	for(i=0;i<12;i++)
	   	printf ( "\xDB\xDB\xDB\xDB\xDB" ) ;
	   	printf("        \xDB\xDB\n");
	}
	if ( r == 4 )
	{
	    	for(i=0;i<12;i++)
	    	printf ( "\xDB\xDB\xDB\xDB\xDB" ) ;
	    	printf("  ENTRY \xDB\xDB");
	}
	if(r<=3)
	{
		for ( c = 0 ; c < 10 ; c++ )
		{		
			printf ( "| %04d", parklot[r][c] ) ;
			if( r<=3 )
				printf("        \xDB\xDB");
			if( r == 0 || r == 2)
				printf("\n\t\t\t\t\t\t\t\t    \xDB\xDB\n\t\t\t\t\t\t\t\t    \xDB\xDB");
		}
	}
    }
}

void way(int row,int col)
{
   system("cls");
   int r, c, i, j , l ;
   printf ( "\n\t\t***PARKING LOT***\n" ) ;
   for ( r = 0 ; r <= 4 ; r++ )
   {
	if ( r == 0)
	{
		for(i=0;i<12;i++)
		printf ( "\xDB\xDB\xDB\xDB\xDB" ) ;
		printf("  EXIT  \xDB\xDB");
	}
	printf("\n");
	if ( r == 2 )
	{
	   for(i=0;i<12;i++)
	   printf ( "\xDB\xDB\xDB\xDB\xDB" ) ;
	   printf("        \xDB\xDB\n");
	}
	if ( r == 4 )
	{
	    for(i=0;i<12;i++)
	    printf ( "\xDB\xDB\xDB\xDB\xDB" ) ;
	    printf("  ENTRY \xDB\xDB");
	}
	if(r<=3)
	{
		 if((r==3&&r==row)||(r==1&&r==row))
		  {
			for(l=0;l<60;l++)
		  	{
		    		if(l<col*6)
		    			printf(" ");
		    		else if(l==((col*6)+1))
		    		{
		    			if(r==3||r==1)
		    				printf("|");
		    			if(r==2)
		    				printf("^");
		    		}
		    		else if(l>col*6&&(l<59))
		    			printf("-");
		  	}
			printf("\n\n");
		  }
		  for ( c = 0 ; c < 10 ; c++ )
		 	printf ( "| %04d", parklot[r][c] ) ;
		  if((r==2&&r==row)||(r==0&&r==row))
		  {
		       printf("\n");
		       for(l=0;l<60;l++)
		       {
		       	    if(l<col*6)
		    	    printf(" ");
		    	    else if(l==((col*6)+1))
		    	    {
		    		if(r==3)
		    			printf("|");
		    		if(r==2||r==0)
		    			printf("^");
		    	    }
		    	    else if(l>col*6&&(l<59))
		   		 printf("-");
		  	}
			printf("\n\n");
		   }

		}
		if( r<=3 );
		{
			if((r==row&&r==2)||(r==row&&r==0))
			{
			}
			else
			    printf("        \xDB\xDB");
			if(  r == 2 ||r == 0 )
				printf("\n\t\t\t\t\t\t\t\t    \xDB\xDB\n\t\t\t\t\t\t\t\t    \xDB\xDB");

		}
}

void counter()
{
	printf ( "\n\nSlots remaining	: %d\t",40-vehcount ) ;
	printf ( "Total amount collected : %d\n", amount ) ;
}

int main( )
{
    int choice, type, number, row = 0, col = 0,count=0, d=0;
    int time,bill=0,pack;
    int i,j,c,tarr[2] ;
    int finish = 1 ;
    struct vehicle *v ;
    struct vehicle *car[4][10] ;
    amount=0;
    while ( finish )
    {
	system("cls");
	printf ( "\n\t\t***PARKING LOT***\n" ) ;
	display();
	counter();
	printf ( "\n\n1. Arrival\n" ) ;
	printf ( "2. Departure\n" ) ;
	printf ( "3. Exit\n" ) ;
	printf ("\n\nEnter your choice : ");
	scanf ( "%d", &choice ) ;

	switch ( choice )
	{
	    case  1 :

		if(vehcount>=40)
		{
		 printf("\nNo more slots available! Parking lot is full!");
		 break;
		}
		else
		{
		printf ( "Enter Vehicle licence number : " ) ;
		scanf ( "%d", &number ) ;

		ti:
		printf ("\n\n1. 10 rupees per hour (1 to 5 hours)");
		printf ("\n   20 rupees per hour (6 to 8 hours)");
		printf ("\n\n2. Full Day( 150 Rs )\n\nEnter your choice : ");
		scanf("%d",&pack);

		switch(pack)
		{
		case 1:
			printf ("No of hours needed (5 hours max) : ");
			scanf("%d",&time);
			switch(time)
			{
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
				bill=time*10;
				amount=amount+bill;
				break;
			case 6:
			case 7:
			case 8:
				bill=time*20;
				amount=amount+bill;
				break;
			}
			break;
		case 2:
				bill=150;
				amount=amount+bill;
				break;
		default:
				printf("Invalid choice! Please enter 1 or 2!\n");
				goto ti;
		}

		printf("Amount to be paid : %d",bill);
		count=0;

			for ( row = 3 ; row >= 0 ; row-- )
			{
			  for ( col = 9 ; col >= 0 ; col-- )
			  {
			   if ( parklot[row][col] == 0 )
			   {
			   parklot[row][col]==number;
			   car[row][col] =  add ( number, row, col ) ;
			   count++;
			   printf("%d    %d",row,col);
			   way(row,col);
			   }
			   if(count>0)
			   break;
			  }
			  if(count>0)
			  break;
			}
		printf ( "\nPress any key to continue..." ) ;
		getch( ) ;
		break ;
		}
		case 2 :
		printf ( "Enter Your car's licence number : " ) ;
		scanf( "%d", &number ) ;
		d=0;
		if(number!=0)
		{
			for ( row = 0 ; row < 4 ; row++ )
			{
			  for ( col = 0 ; col < 10 ; col++ )
			   {
			    if(parklot[row][col]==number)
			     {
				parklot[row][col]=0;
				d++;
				vehcount--;
			     }
			   }
			}
		}
	       if(d==0)
		{
		 printf("\nYour car has not been parked here! (or) You've entered a wrong data");

		}

		printf ( "\nPress any key to continue..." ) ;
		getch( ) ;
		break;

		case 3:
			printf("\nCost Details");
			printf("\n1.10 Rupees per hour (for less than 5hours");
			printf("\n2.15 Rupees per hour (for 5 hours to 8hours");
			printf("\n3.150 rupees for whole day");

		case 4:
			finish = 0;
			break;

		default:
			printf("/nENTER VALID OPTION : ");
	}
	}
}



