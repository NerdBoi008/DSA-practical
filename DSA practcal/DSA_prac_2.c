#include<stdio.h>

struct student
{
  char *name;
  int eno;
};

int main(void)
{
  struct student s1;
  s1.name = "moin malek";
  s1.eno = 001;
  printf("Name: %s\n", s1.name);
  printf("Eno No: %d\n",s1.eno );
  return 0;
}
