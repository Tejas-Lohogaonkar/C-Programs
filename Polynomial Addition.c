//MIS NO. 111807022 POLYOMIAL ADDITION
#include<stdio.h>

struct poly                                                                     
{
  int e;
  float c;
};
struct poly p1[15], p2[15], p3[15];                                             
void readpoly(struct poly[], int);
int polyadd(struct poly[], struct poly[], int, int, struct poly[]);             
void display(struct poly[], int);
int main()                                                                      
{
	int n1,n2,n3;
 printf("\nEnter non zero coeffs for poly 1\n");                                     
 scanf("%d",&n1);
 printf("Enter the coefficients of polynomial 1 in decsending order");
 readpoly(p1,n1);                                                                    
  printf("\nPoly 1 is : ");
 display(p1,n1);
printf("\nEnter non zero coeffs for poly 2\n");                                   
 scanf("%d",&n2);
 printf("Enter the coefficients of polynomial 2 in decsending order\n");
 readpoly(p2,n2);
 printf("\nPoly 2 is : ");
 display(p2,n2);
 n3=polyadd(p1,p2,n1,n2,p3);                                                      
 printf("\nThe resultant polynomial is : ");
 display(p3,n3);                                                                 
 return 0; 
 }
void readpoly(struct poly p[15], int n)                                         
{  
	int i;
 for(i=0;i<n;i++)                                                               
 { 
	printf("\nEnter exponent : ");
	scanf("%d",&p[i].e);
    printf("\nEnter coeff : ");
	scanf("%f",&p[i].c);
 }
}
int polyadd(struct poly p1[15],struct poly p2[15],int n1,int n2,struct poly p3[15])
{
  int i,j,k;
  i=0;j=0;k=0;
  while(i<n1 && j<n2)                                                               
  {
     if(p1[i].e==p2[j].e)
	 {
	   p3[k].c=p1[i].c+p2[j].c;
	   p3[k].e=p1[i].e;
	   i++; j++; k++;	 
	 }
	 else if(p1[i].e>p2[j].e)
	 {
	   p3[k].c=p1[i].c;
	   p3[k].e=p1[i].e;
	   i++;
	   k++;
	 }
         else if(p2[j].e>p1[i].e)
	 {
	   p3[k].c=p2[j].c;
	   p3[k].e=p2[j].e;
	   j++;
	   k++;
	 }
 }
while(i<n1)
  {
    p3[k].c=p1[i].c;
	p3[k].e=p1[i].e;
	i++;
	k++;
  }
  while(j<n2)
  {
    p3[k].c=p2[j].c;
	p3[k].e=p2[j].e;
	j++;
	k++;
   }
 return k;
}

void display(struct poly p[15], int n)                                                       
{
	int i;
	for(i=0;i<n;i++)
    printf(" %.1fx^%d +",p[i].c,p[i].e);
	printf("\b");
}

