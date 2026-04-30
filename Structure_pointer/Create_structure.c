#include <stdio.h>
struct employe{
    char name[30];
    int emid;
    float salary;
};
int main() {
struct employe emp = {"Pabitra Pal", 654656465,18000};
printf("\nName : %s",emp.name);
printf("\nId : %d",emp.emid);
printf("\nsalary : %f",emp.salary);

    return 0;
}