FIBO
} TypeTag;

Node* makeFunc(TypeTag type) {
Node* node = (Node*)malloc(sizeof(Node));
node->type = type;
node->value = NULL;
return node;
}


Node* makeNum(int value) {
Node* node = (Node*)malloc(sizeof(Node));
node->type = FIBO;
node->value = (int*)malloc(sizeof(int));
*(int*)(node->value) = value;
return node;
}


void calc(Node* node) {
switch (node->type) {
case ADD:
node->value = (int*)malloc(sizeof(int));
*(int*)(node->value) = *(int*)(node->left->value) + *(int*)(node->right->value);
break;
case SUB:
node->value = (int*)malloc(sizeof(int));
*(int*)(node->value) = *(int*)(node->left->value) - *(int*)(node->right->value);
break;
case MUL:
node->value = (int*)malloc(sizeof(int));
*(int*)(node->value) = *(int*)(node->left->value) * *(int*)(node->right->value);
break;
case DIV:
node->value = (int*)malloc(sizeof(int));
*(int*)(node->value) = *(int*)(node->left->value) / *(int*)(node->right->value);
break;
case FIBO:
node->value = (int*)malloc(sizeof(int));
*(int*)(node->value) = fibonacci(*(int*)(node->left->value));
free(add->left->value);
free(add->left);
freebreak;
}
}


int fibonacci(int n) {
if (n <= 1)
return n;
int* fib = (int*)malloc((n + 1) * sizeof(int));
fib[0] = 0;
fib[1] = 1;


for (int i = 2; i <= n; i++)
fib[i] = fib[i - 1] + fib[i - 2];


int result = fib[n];
free(fib);
return result;
}


int main() {
Node* add = (*makeFunc(ADD));
add->left = makeNum(10);
add->right = makeNum(6);
calc(add);
printf("add: %d\n", *(int*)(add->value));


Node* mul = (*makeFunc(MUL));
mul->left = makeNum(5);
mul->right = makeNum(4);
calc(mul);
printf("mul: %d\n", *(int*)(mul->value));


Node* sub = (*makeFunc(SUB));
sub->left = mul;
sub->right = add;
calc(sub);
printf("sub: %d\n", *(int*)(sub->value));


Node* fibo = (*makeFunc(FIBO));
fibo->left = sub;
fibo->right = NULL;
calc(fibo);
printf("fibo: %d\n", *(int*)(fibo->value));(add->right->value);
free(add->right);
free(add->value);
free(add);


free(mul->left->value);
free(mul->left);
free(mul->right->value);
free(mul->right);
free(mul->value);
free(mul);


free(sub->left->value);
free(sub->left);
free(sub->right->value);
free(sub->right);
free(sub->value);
free(sub);


free(fibo->left->value);
free(fibo->left);
free(fibo->value);
free(fibo);


return 0;
}
