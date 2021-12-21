int main()
{
    SqStack S;
    ElemType x;
    int i;

    InitStack(&S);
    for ( i = 0; i < 10; i++)
    {
        Push(&S,i);
    }
    TraverseStack(S,visit);
    Pop(&S,&x);
    printf("Now this element (%d) has been popped up\n",x);
    TraverseStack(S,visit);
    DestoryStack(&S);
    return 0;
}