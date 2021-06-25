#include "stack.h"

int     recursive_check(/* add parameter */)
{
        int     recursive_check(int p, char* word)
{
        if (word == '\0')
        {
            if (p == 0)
            return 1;
            else 
            return 0;
        }
    else
    {
        int i=0;
        if(word[1] == ')' && p == 0)
         return 0;                  
        else if (word[i] == '(')
         return recursive_check(p+1,word[i+1]);
        else if (word[i] == ')')
         return recursive_check(p-1,word[i+1]);
        else
         return recursive_check(p,word[i+1]);
    }
}
}

int     iterative_check(/* add parameter */)
{
{
    t_stack * B=NULL;
    t_stack * F=NULL;
    t_stack * P=NULL;
    int a;
    
    int i=0;
    while(word[i]!='0')
    {
        if (word[i]=='['  )
            push(&B,1);
        if (word[i]=='{')
            push(&F,1);
        if (word[i]=='(')
            push(&P,1);

        if (word[i]==']')
            if(B!=NULL)
                a=pop(&B);
        if(word[i]=='}')
            if(F!=NULL)
                a=pop(&F);
        if(word[i]==')')
            if(P!=NULL)
                a=pop(&P);
        i++;
    }
    if(B ==NULL && P==NULL && F==NULL)
        return 1;
    else
        return  0;
    

}
}

int main(int ac,char**av)
{
    if (ac != 2)
        printf("print only one argument\n");
    int p=iterative_check(av[1]);
    if(p==1)
        printf("OK\n");
    if(p==0)
        printf("ERROR\n");
    return 0;
    
    // write main function
    // get string from argument line
    // use iterative check and recursive check
}
