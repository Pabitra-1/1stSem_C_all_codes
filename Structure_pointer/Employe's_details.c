 #include <stdio.h>
struct employe{
    char name[30];
    int emid;
    float salary;
};
int main() {
    struct employe emp;

printf("\n Enter details : \n");
printf("\nName  : \n");
fgets(emp.name,sizeof(emp.name),stdin);
printf("\nId  : \n");
scanf("%d",&emp.emid);
printf("\nSalary : \n");
scanf("%f",&emp.salary);
printf("\nName : %s",emp.name);
printf("\nId : %d",emp.emid);
printf("\nsalary : %f",emp.salary);

    return 0;
}
