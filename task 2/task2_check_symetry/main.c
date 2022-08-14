#include <stdio.h>
#include <stdlib.h>

   typedef struct node {
   struct node *nxt;

   char c;

} node;

   typedef struct stack{
   struct node *top;

   }stack;


struct stack stack_push( struct stack s,char x  ){
    struct node *n;
 n=( struct node *) malloc (sizeof (struct node));
      n->c=x;
    if (s.top==NULL){
        n->nxt= NULL;
        char b = n->c;
       // printf ("%c\n",n->c);

    }
    else {
        n->nxt=s.top ;


 }
    s.top=n;
    //printf ("%c\n",s.top->c);
    return s;

}
struct stack construct_stack (){

    struct stack*s;
    s= (struct stack *) malloc(sizeof(struct stack));
    s->top= NULL;
    return *s;
}
 struct stack stack_pop (struct stack s){
     if (s.top==NULL){
        printf("no elements to pop in this stack \n\n") ;

     }
     else {
        struct node * n;
     n=s.top;
     char x = n->c;
     printf ("char is%c\n",x);
     s.top=n->nxt;
     free(n);

     }
     return s;
 }
 void display (struct stack s){
     struct node *n;
     n=s.top;
    if (n!=NULL){
 while (n!=NULL){
   printf("%c\n" ,n->c);
        n=n->nxt;

        }
    }
 }
  void check_symetry (struct stack s){
  struct node *n;
   struct node *m;
     n=s.top;
     struct stack s1=construct_stack();
     printf("______________________________________\n");
  display(s);
  printf("_______________________________________\n");
  while (n!=NULL){
        m=s1.top;

        if ( n->c=='}'|| n->c==']'||n->c==')' ){
            s1=stack_push(s1,n->c);
        }
        else if (n->c=='{'||n->c=='['||n->c=='('){
                   printf("______________________________________\n");
                    display(s1);
                    printf("_______________________________________\n");
            if (m!=NULL){
            if ((m->c=='}'&&n->c=='{')||(m->c==']'&&n->c=='[')||(m->c==')'&&n->c=='(')){
                 s1=stack_pop(s1);
                 }

              else {
                break;
              }
            }
            else {
                break;
            }
  }
  n=n->nxt;
  }
  if (s1.top==NULL){
  if (n==NULL){
    printf("symetric\n");
  }
  else{
        if (m==NULL){
            printf("not symetry\n");
        }
  }
  }
        else {

    printf("not symetry\n");
  }


  }
int main()
{
    printf("Hello world!\n");
    struct stack s = construct_stack();
  /* s= stack_push(s,'x');

    s=stack_push(s,'c');
  //  printf ("%c\n",s.top->c);
    display(s);

    s=stack_pop (s);

    s=stack_pop (s);
    s=stack_pop(s);
   /* s= stack_push(s,'{');
    s= stack_push(s,'[');
    s= stack_push(s,']');
    s= stack_push(s,'{');
    s= stack_push(s,'{');
    s= stack_push(s,'}');
    s= stack_push(s,'[');
    s= stack_push(s,'[');
    s= stack_push(s,']');
    s= stack_push(s,']');
    s= stack_push(s,'}');
    s= stack_push(s,'[');
    s= stack_push(s,']');
    s= stack_push(s,'}');*/
    printf("Hello world!\n\n");
  /*  s= stack_push(s,'}');
    s= stack_push(s,'}');
    s= stack_push(s,'}');
    s= stack_push(s,'}');
    */
     s= stack_push(s,')');
    s= stack_push(s,')');
    s= stack_push(s,')');
    s= stack_push(s,'}');
    check_symetry(s);

    return 0;
}
