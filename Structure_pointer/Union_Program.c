 #include <stdio.h>
 #include<string.h>
union Data{
    int i;
    float f;
    char s[30];
};
int main() {
    union Data d;
    d.i=10;
    printf("data.i %d\n",d.i);
    d.f=22.5;
    printf("data.f %f\n",d.f);
    strcpy(d.s,"C Programming");
    printf("data.i %s\n",d.s);
    return 0;
} 