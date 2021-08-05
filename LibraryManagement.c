#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>


/*Count total number of books in the library*/
int count();

void display(int);

/*If the author name is same so the function strcmp returns a zero*/
void giv_author(char*);
void add_book();

/*Appears the title of the specified book*/
void which_book(int);

/*Displays all the books serially accession number*/
void all_book();

struct library
{
	int an;/*Accession number*/
	char title[50];
	char author[80];
	int price;
	int flag;/*flag = 0 : Issued and,flag =  1: not issued*/
}accesslib[50] = { 
    1,"Wings of Fire", "A. P. J. Abdul Kalam and Arun Tiwari", 460, 0,
    2, "The Warren Buffett Way", "Robert G. Hagstrom", 785, 0,
	3, "Let Us C", "Yashavant Kanethkar", 258, 1,
    4,"Data Structure Through C", "Yashavant Kanethkar", 300, 1,
    5, "Let Us C++", "Yashavant Kanethkar", 220, 1,
	6, "Harry Potter : The Philosopher's Stone", "J. K. Rowling", 550, 0, 
	7, "The Hobbit", "J. R. R. Tolkien", 550, 1,	
};

int main()
{
    system("cls");
   
	char auth[30];
    int choice=1,an;
    while (choice != 7)
    {
     system("cls");
     printf("\t\t\t###########################################################################");
     printf("\n\t\t\t############                                                   ############");
     printf("\n\t\t\t############            Library management System              ############");
     printf("\n\t\t\t############                                                   ############");
     printf("\n\t\t\t###########################################################################");
     printf("\n\t\t\t---------------------------------------------------------------------------\n");
     printf("\n\t\t\t\t 1.Add Book Information");
     printf("\n\t\t\t\t 2.Display Book Information");
     printf("\n\t\t\t\t 3.List all the books of given author");
     printf("\n\t\t\t\t 4.List the title of specified book");
     printf("\n\t\t\t\t 5.List the count of books in the library");
     printf("\n\t\t\t\t 6.List the book in the order of accession number");
     printf("\n\t\t\t\t 7.Exit");
     printf("\n\n\t\t\t\t Enter Your Choice=");
     scanf("%d",&choice);

      switch (choice)
      {
		case 1:
			add_book();
			_getch();
			break;
		case 2:
			printf("\nEnter the accession number of the book : ");
			scanf("%d", &an);
			display(an);
			_getch();
			break;
		case 3:
			while (getchar() != '\n');
			printf("Enter the name of the author (case sensitive) : ");
			gets(auth);
			giv_author(auth);
			_getch();
			break;
		case 4:
			printf("\nEnter the accession number of book : ");
			scanf("%d", &an);
			which_book(an);
			_getch();
			break;
		case 5:
			printf("\nTotal Number of books : %d", count());
			_getch();
			break;
		case 6:
			all_book();
			_getch();
			break;
		case 7:
			return 0;
		default:
			printf("\nWrong choice, Try Again!!");
			_getch();
     }
    
    }
   
   _getch();
   return 0;
}
int count()
{
	int i = 0;
	while (accesslib[i].an)
		i++;
	return i;
}

void display(int i)
{
	i--;/*To use i as index*/
	printf("\n\n\n");
	printf("\nAccession Number : %d", accesslib[i].an);
	printf("\nTitle : %s", accesslib[i].title);
	printf("\nAuthor : %s", accesslib[i].author);
	printf("\nPrice : %d", accesslib[i].price);
	if (accesslib[i].flag)/*Flag : 0*/
		printf("\nStatus : Issued");
	else
		printf("\nStatus : Available");/*Flag : 1*/
}

void giv_author(char *author)
{
	int i = 0;
	printf("\nBooks of \"%s\" are following : \n\n", author);
	while (accesslib[i].an)
	{
		if (!(strcmp(author, accesslib[i].author)))
			display(accesslib[i].an);
		i++;
	}
}

void add_book()
{
	int next = count();
	accesslib[next].an = next + 1;

	/*fflush(stdin) or while(getch() != '\n'); to clear the buffer*/
	while (getchar() != '\n');
	printf("\nEnter the title of the book : ");
	gets(accesslib[next].title);
	printf("\nEnter the author name of the book : ");
	gets(accesslib[next].author);
	printf("\nEnter the price of the book : ");
	scanf("%d", &accesslib[next].price);
	accesslib[next].flag = 1;
	system("cls");
}

void which_book(int an)
{
	int i = 0;
	while (accesslib[i].an)
	{
		if (accesslib[i].an == an)
		{
			printf("\n\nTitle of the book : %s\n", accesslib[i].title);
			return;
		}
	}
	printf("No any book found found\n");
}

void all_book()
{
	int i = 0;
	while (accesslib[i].an)
	{
		display(i + 1);
		i++;
	}
}