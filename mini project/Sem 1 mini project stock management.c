#include <stdio.h>
#include<string.h>
struct stock{
    char name[100];
    int qty,pdt_id;
};
static int x=0,z=0;
struct stock s[100];
void initialise(){
    int i;
    for(i=0;i<100;i++){
        s[i].qty=0;
        s[i].pdt_id=0;
        strcpy(s[i].name,"UNSPECIFIED");
    }
}
void login(){
    int pwd,key=1234;
    printf("Enter login password:");
    scanf("%d",&pwd);
    if(pwd==key)
    printf("ACCESS GRANTED!\n");
    else{
        printf("Wrong password!\n");
        login();
    }
}
void print(){
    int i;
    printf("PRODUCT ID\tNAME\t  QUANTITY\n");
    for(i=0;i<100;i++){
    printf("%d\t     %s\t%d\n",s[i].pdt_id,s[i].name,s[i].qty);
    }
}
int add_item(){
    int i,q;
    printf("Number of items to be added:");
    scanf("%d",&q);
    for(i=x;i<x+q;i++){
        printf("Enter item %d details:\n",i+1);
        printf("Name:");
        scanf("%s",s[i].name);
        printf("Product ID:");
        scanf("%d",&s[i].pdt_id);
        printf("Quantity:");
        scanf("%d",&s[i].qty);
        z++;
    }
    x=z;
}
void del_item(){
    int p,i,j;
    printf("Detail of the product to be deleted:\n");
    printf("Product ID:");
    scanf("%d",&p);
    for(i=0;i<x;i++){
        if(s[i].pdt_id==p){
            for(j=i;j<x;j++){
                s[j].pdt_id=s[j+1].pdt_id;
                strcpy(s[j].name,s[j+1].name);
                s[j].qty=s[j+1].qty;
            }
        }
    }
    x--;
    z=x;
}
void sale(){
    int p,i=0,n,b=0;
    printf("Sale Details:\n");
    printf("Product ID:");
    scanf("%d",&p);
    printf("Number of units sold:");
    scanf("%d",&n);
    while(i<x){
        if(s[i].pdt_id==p){
        if(s[i].qty>=n){
        s[i].qty-=n;
        printf("SALE UPDATED!\n");
        b=1;
        }
        else {
        printf("NOT ENOUGH STOCK TO MAKE THE SALE!\n");
        b=1;
        }
        }
        i++;
    }
    if(b==0){
    printf("ITEM NOT FOUND!\n");
    }
}
void stk_change(){
    int p,a,b,i,op;
    printf("Enter the Product ID:");
    scanf("%d",&p);
    for(i=0;i<x;i++){
        if(s[i].pdt_id==p){
            b=i;
        }
    }
    printf("WHAT DO YOU WANT TO DO?\n(1)MODIFY THE QUANTITY\n(2)ADD STOCK\nENTER YOUR CHOICE:");
    scanf("%d",&op);
    switch(op){
        case 1:
        printf("Enter the new quantity:");
        scanf("%d",&a);
        s[b].qty=a;
        break;
        case 2:
        printf("Enter the quantity to be added:");
        scanf("%d",&a);
        s[b].qty+=a;
        break;
    }
}
int search(){
    int p,i,f=0;
    printf("Enter details of product to search:\n");
    printf("Product ID:");
    scanf("%d",&p);
    for(i=0;i<x;i++){
        if(s[i].pdt_id==p){
        printf("PRODUCT ID\tNAME\t  QUANTITY\n");
        printf("%d      \t%s\t%d\n",s[i].pdt_id,s[i].name,s[i].qty);
        f=1;
        }
        else 
        continue;
    }
    if(f==0){
        printf("ELEMENT NOT FOUND!\n");
    }
}
void prtinfile(){
    int i;
    FILE *fp;
    fp=fopen("stock.txt","w");
    for(i=0;i<x;i++){
        fprintf(fp,"PRODUCT ID     NAME    QUANTITY");
        fprintf(fp,"%d\t%s\t%d\n",s[i].pdt_id,s[i].name,s[i].qty);
    }
    fclose(fp);
}
void main(){
    initialise();
    int op;
    printf("WELCOME TO THE STOCK MANAGEMENT SYSTEM!\n");
    login();
    do{
    printf("MAIN MENU:\n");
    printf("WHAT DO YOU WANT TO DO?\n(1)SHOW THE STOCK DETAILS\n(2)ADD A NEW ITEM\n(3)DELETE AN ITEM\n(4)RECORD A SALE\n(5)UPDATE THE STOCK OF A PRODUCT\n(6)SEARCH A PRODUCT\n(7)PRINT THE STOCK DETAILS IN A FILE\n(8)EXIT\nENTER YOUR CHOICE:");
    scanf("%d",&op);
    switch(op){
        case 1:
        print();
        break;
        case 2:
        add_item();
        printf("PRODUCTS ADDED SUCCESSFULLY!\n");
        break;
        case 3:
        del_item();
        printf("PRODUCTS DELETED SUCCESSFULLY!\n");
        break;
        case 4:
        sale();
        break;
        case 5:
        stk_change();
        printf("STOCK UPDATED SUCCESSFULLY!\n");
        break;
        case 6:
        search();
        break;
        case 7:
        prtinfile();
        printf("STOCK FILE CREATED!\n");
        break;           
    }
    }
    while(op!=8);
}