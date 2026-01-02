#include<stdio.h>
#include<conio.h>
struct product
{
   int id;
   char name[30];
   int qty;
   float price;
   float total;
};
void main()
{
   struct product p;
   FILE*fp;
   int i,searchId,found=0;
   float grandTotal=0;
   clrscr();
   fp=fopen("product.txt","w");
   if(fp==NULL)
   {
      printf("File cannot be opened!\n");
      return;
   }
    printf("Enter details of 5 products\n");
    for(i=0;i<5;i++)
{
   printf("\n Product %d\n",i+1);
   printf("Products ID: ");
   scanf("%d",&p.id);
   printf("Product name: ");
   scanf("%s",p.name);
   printf("Quantity: ");
   scanf("%d",&p.qty);
   printf("Price: ");
   scanf("%f",&p.price);

   p.total=p.qty*p.price;
   fprintf(fp,"%d\t%s\t%d\t%.2f\t%.2f\n",p.id,p.name,p.qty,p.price,p.total);
}
 fclose(fp);
 fp=fopen("product.txt","r");
 if(fp==NULL)
 {
    printf("File cannot be opened!\n");
    return;
 }
  printf("\n-----------------Product Details---------------------\n");
  printf("ID\tName\tQty\tTotal\n");
  printf("-------------------------------------------------------\n");
  grandTotal=0;

  while(fscanf(fp,"%d%s%d%f%f",&p.id,p.name,&p.qty,&p.price,&p.total)!=EOF)
  {
     printf("%d\t%s\t%d\t%.2f\t%.2f\n",p.id,p.name,p.qty,p.price,p.total);
     grandTotal +=p.total;
  }
  printf("--------------------------------------------------------\n");
  printf("Total Bill Amount:%.2f\n",grandTotal);

  fclose(fp);
  printf("\n Enter Product ID to serch: ");
  scanf("%d",&searchId);
  fp=fopen("product.txt","r");
  if(fp==NULL)
  {
     printf("File cannot be opened!\n");
     return;
  }
  found=0;
  while(fscanf(fp,"%d%s%d%f%f",&p.id,p.name,&p.qty,&p.price,&p.total)!=EOF)
 {
    if(p.id==searchId)
    {
	printf("\n Product Found\n");
	printf("ID: %d\nName:%s\nQuantity: %d\nPrice: %.2f\nTotal: %.2f\n",p.id,p.name,p.qty,p.price,p.total);
	found=1;
	break;
 }
}
 if(found==0)
 printf("\n Product not found!\n");
 fclose(fp);
 getch();
}



