 #include <stdio.h>
struct iteam{
    char iname[30];
    int qty;
    float price;
    float amount;
};
int main() {
 struct iteam i1;
 struct iteam *ptritm;
 ptritm=&i1;
 printf("\n Enter Product name : ");
 fgets(ptritm->iname,sizeof(ptritm->iname),stdin);
  printf("\n Enter Price : ");
  scanf("%f",&ptritm->price);
  printf("\n Enter amount : ");
  scanf("%d",&ptritm->qty);
  printf("\n Name : %s",ptritm->iname);
  printf("\n price : %f",ptritm->price);
  printf("\n Quantity : d",ptritm->qty);
  printf("\n Total amount : %f",(float)(ptritm->qty*ptritm->price));
  

    return 0;
}  