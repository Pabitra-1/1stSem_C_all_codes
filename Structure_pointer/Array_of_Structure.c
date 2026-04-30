 #include <stdio.h>
struct student{
int id;
float per;
char name[30];
};
int main() {
        int i , j;
  struct student record[3];
  for(i = 0 ; i<3 ; i++){
      printf("\n Enter Record : ");
      printf("\n Enter Id, Name , Percentage :");
 scanf("%d%s%f",&record[i].id,&record[i].name,&record[i].per);
  }
  for(i = 0,j=1 ; i<3 ; i++,j++){
     printf("\n Record of Student");
     printf("\n Id : %d",record[i].id);
     printf("\n Name : %s",record[i].name);
     printf("\n Id : %d",record[i].per);
  }

    return 0;
} 