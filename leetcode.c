bool isValid(char * s){
    char stack[10000];
    int i=0,top=-1;
    while(s[i]!='\0'){
        if(s[i]=='('|| s[i]=='{'|| s[i]=='['){
            top++;
            stack[top]=s[i];
            // printf("%c",stack[top]);
        }
        else if(top != -1) {
           if(stack[top]== '(' && s[i]==')'){
                top--;
            }else if(stack[top]== '{'&& s[i]=='}'){
                top--;
            }else if(stack[top]== '[' && s[i]==']'){
                top--;
            }
            else
                return false; 
        }
        else{
            return false;
        }
        i++;
    }
    if(top==-1){
        return true;
    }
    else{
        return false;
    }
}