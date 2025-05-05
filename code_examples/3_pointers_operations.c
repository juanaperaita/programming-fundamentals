// When using relational operators, we compare the
// address of the pointers. Example:

int a;
int b;
int *pa;
int *pb;

a=3;
b=5;
pa=&a;
pb=&b;

if(pa<pb){
    printf("a has a memory address lower than b");
}

// Although we can assure that a<b,
// we dont know if pa is smaller than pb,
// because we dont know the memory addresses so far.

// If we want to sum something to a pointer,
// we'll sum the bytes to the next pointer. Example:

int a[2];
int *p;

p = a;

a[0] = 1;
a[1] = 222;

printf("this is the memory address of first element of a: %p\n", p);
printf("this is the memory address of second element of a: %p\n", p+1);


// If now we do (p+1)-p, we'll obtain 4. 
// Since p+1 is 8(8 bytes since an int is 4 bytes and we're accessing the next memory variable)
// and if we remove p (equivalent to 4 bytes), we obtain 4.

