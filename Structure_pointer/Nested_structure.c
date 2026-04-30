 #include <stdio.h>
struct student{
    char name[30];
    int roll;
    struct dob{
        int dd;
        int mm;
        int yy;
    }DOB;
};
int main() {
    struct student s;

printf("\n Enter Name : ");
fgets(s.name,sizeof(s.name),stdin);
printf("\nEnter Roll no.  : ");
scanf("%d",&s.roll);
printf("\nEnter date of birth[mm:dd:yy]format: ");
scanf("%d%d%d",&s.DOB.dd,&s.DOB.mm,&s.DOB.yy);
printf("\nName : %s \n Roll : %d \n Date of birth : %20d/%20d/%20d",s.name,s.roll,s.DOB.dd,s.DOB.mm,s.DOB.yy);

    return 0;
}