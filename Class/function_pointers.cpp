#include <stdio.h>

struct operation{
int (*opfn)(int, int);
};

int add(int a, int b){
return a + b;
}

int main(){
struct operation op;
op.opfn = add;
int sum = op.opfn(10,15);
printf("%d",sum);
  return 0;
}
