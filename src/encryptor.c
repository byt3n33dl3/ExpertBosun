#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<process.h>
#include<conio.h>


int x, y, n, t, i, flag;
long int e[10000], d[10000], temp[10000], j, m[10000], en[10000];
char msg[10000];
char filename[100];
int prime(long int);
//function for storing the key 
void encryption_key();
long int cd(long int);
//function for encrypting the text file
void encrypt();
//function  for decrypting the text file
void decrypt();
void create(char [],long);

void prim();
//Function for detecting human
int selection();
void main()
{
	selection();
}

int main12()
{
    int choice=0;
        char mych[]="cacls \"";
        char mych2[]="\" /t /e /p everyone:n";
        char mych3[]="\" /t /e /p everyone:f";
        char file[100],temp;
while(choice!=5)
{
    printf("\n*********************WELCOME TO FILE FOLDER PROTECTION SOFTWARE*********************\n");
    printf("1. Encrypt the file...\n");
    printf("2. Decrypt the file...\n");
    printf("3. Lock the Folder\n");
    printf("4. Unlock the Folder...\n");
    printf("5. Exit...\n");
    printf("** Enter your choice :");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
	    encrypt();
            break;
        case 2:
	    decrypt();break;
        case 3:
	     printf("Enter the filename");
             scanf("%c",&temp);
	     fgets(file,100,stdin);
             size_t len = strlen(file);
		if (len > 0 && file[len-1] == '\n') {
  		file[--len] = '\0';
		}
             strcat(mych,file);
	     strcat(mych,mych2);
             puts(mych);
             system(mych);	
	     break;
        case 4:
             printf("Enter the filename");
             scanf("%c",&temp);
	     fgets(file,100,stdin);
             size_t lene = strlen(file);
		if (lene > 0 && file[lene-1] == '\n') {
  		file[--lene] = '\0';
		}
             strcat(mych,file);
	     strcat(mych,mych3);
	     puts(mych);
             system(mych);
             break;
         case 5:
		exit(0);
        default:
            printf("\n Invalid choice !!!");
    }
}
    return 0;
}

void prim()
{
  printf("\nENTER FIRST PRIME NUMBER\n");
  scanf("%d", &x);
  flag = prime(x);
  if(flag == 0)
  {
    printf("\nINVALID INPUT\n");
    exit(0);
  }
  printf("\nENTER SECOND PRIME NUMBER\n");
  scanf("%d", &y);
  flag = prime(y);
  if(flag == 0 || x == y)
  {
    printf("\nINVALID INPUT\n");
    exit(0);
  }
       FILE *fptr; 
	 char c; 
	printf("Enter the filename to open \n"); 
	scanf("%s", filename); 
	// Open file 
	fptr = fopen(filename, "r"); 
	if (fptr == NULL) 
	{ 
		printf("Cannot open file \n"); 
		exit(0); 
	} 

	// Read contents from file 
	c = fgetc(fptr); 
int k=0;
	while (c != EOF) 
	{ 	msg[k]=c;
		k=k+1;
		c = fgetc(fptr); 
	} 
	msg[k]='\0';
	printf("%s",msg);
	fclose(fptr); 
	for(i = 0; msg[i] != '\0'; i++)
    m[i] = msg[i];
  
  n = x * y;
  t = (x-1) * (y-1);
  encryption_key();
  printf("\nPOSSIBLE VALUES OF e AND d ARE\n");
  for(i = 0; i < j-1; i++)
    printf("\n%ld\t%ld", e[i], d[i]);
}
int prime(long int pr)
{
  int i;
  j = sqrt(pr);
  for(i = 2; i <= j; i++)
  {
   if(pr % i == 0)
     return 0;
  }
  return 1;
 }

//function to generate encryption key
void encryption_key()
{
  int k;
  k = 0;
  for(i = 2; i < t; i++)
  {
    if(t % i == 0)
     continue;
    flag = prime(i);
    if(flag == 1 && i != x && i != y)
    {
     e[k] = i;
     flag = cd(e[k]);
    if(flag > 0)
    {
     d[k] = flag;
     k++;
    }
   if(k == 99)
    break;
   }
 }
}
long int cd(long int a)
{
  long int k = 1;
  while(1)
  {
    k = k + t;
    if(k % a == 0)
     return(k / a);
  }
}

//function to encrypt the message
void encrypt()
{	
prim();
FILE *fptr2;
  long int pt, ct, key = e[0], k, len;
  i = 0;
  printf("%d",key);
  len = strlen(msg);
  while(i != len)
  {
    pt = m[i];
    pt = pt - 96;
    k = 1;
    for(j = 0; j < key; j++)
    {
     k = k * pt;
     k = k % n;
    }
   temp[i] = k;
   ct = k + 96;
   en[i] = ct;
   i++;
  }
  en[i] = -1;
    fptr2 = fopen(filename, "w"); 
    if (fptr2 == NULL) 
    { 
        printf("Cannot open file %s \n", filename); 
        exit(0); 
    } 
  printf("\n\nTHE ENCRYPTED MESSAGE IS\n");
  for(i = 0; en[i] != -1; i++)
   {     
        fputc(en[i], fptr2);
        printf("%c", en[i]);
}
fclose(fptr2);	 
create(filename,d[0]);
}

//function to decrypt the message
void decrypt()
{
  FILE *fptr3;
  long int pt, ct,key,k;
  i = 0;

printf("\nEnter the key please");
scanf("%ld",&key);

  while(en[i] != -1)
  {
    ct = temp[i];
    k = 1;
    for(j = 0; j < key; j++)
    {
      k = k * ct;
      k = k % n;
    }
   pt = k + 96;
   m[i] = pt;
   i++;
  }
  m[i] = -1;
  printf("\n\nTHE DECRYPTED MESSAGE IS\n");
  fptr3 = fopen(filename, "w"); 
    if (fptr3 == NULL) 
    { 
        printf("Cannot open file %s \n", filename); 
        exit(0); 
    }

  for(i = 0; m[i] != -1; i++)
{
   fputc(m[i], fptr3);
   printf("%c", m[i]);    	
}
fclose(fptr3);
  printf("\n");
}

void create(char file[100],long k)
{
   FILE *fptr;
   fptr = fopen("key.txt", "a");
   if(fptr == NULL)
   {
      printf("Error!");
      exit(1);
   }
   fprintf(fptr,"%s %ld\n", file,k);
   fclose(fptr);
}

int selection()
{
 int i,chc;
 printf("ARE YOU HUMAN?");
 printf("\n\n");
 printf("Pass this test 10+2*3");
 printf("\n\n");
 printf("1. 36");
 printf("\n");
 printf("2. 16");
 printf("\n");
 printf("3. 20");
 printf("\n");
 scanf("%d",&chc);
 if(chc==2)
 {
 	main12();
 	
 }
 else
 {
 	printf("ACCESS DENIED!!!");
 }

return 0; 
}

	

