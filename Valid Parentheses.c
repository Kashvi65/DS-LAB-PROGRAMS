#define STACK_SIZE 10000

void push(char s[],char item,int *top){
    if(*top == STACK_SIZE-1){
        printf("Stack Overflow.");
    }
    else{
        *top=*top+1;
        s[*top]=item;
    }
}
char pop(char s[],int *top){
    if(*top==-1){
        printf("Stack Underflow.");
        return '\0';
    }
    else{
        char item_deleted=s[*top];
        *top=*top-1;
        return item_deleted;
    }
}


bool isValid(char* str) {
    char s[STACK_SIZE];
    int top=-1,length = 0;
    while (str[length] != '\0') {
        length++;
    }
    if(length%2!=0){
        return false;
    }

    for(int i=0;i<length;i++){
        if(str[i]=='(' || str[i]=='[' || str[i]=='{'){
            push(s,str[i],&top);
        }
        else{
            if (top == -1) {
                return false;
            }
            if(str[i]==')'){
                if(s[top]=='('){
                pop(s,&top);}
                else{return false;}
            }
            else if(str[i]==']'){
                if(s[top]=='['){
                pop(s,&top);}
                else{return false;}
            }
            else{
                if(s[top]=='{'){
                pop(s,&top);}
                else{return false;}
            }
        }
    }
    return top == -1;
}
