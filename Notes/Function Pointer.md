## Function Pointers in Structures

Function pointers can be used within a structure. It allows the structure to point to different functions making it possible to execute functions making it possible to execute  various operations dynamically based on runtime.


### Normal Function Pointer
```
int sum(int a, int b){
return a + b;
}

void main(){
int *ptr(int, int);
}
```

### Struct Function Pointer
```
struct operation{
int *opfn(int, int);
}

int sum(int a, int b){
return a + b;
}

int main(){
struct operation op;
op.opfn = add;
sum = op.opfn(10,15)

}

```

- EX: Write a Code in C to perform a different opertion on Circle using function pointer
