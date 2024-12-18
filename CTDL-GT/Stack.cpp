#include <stdio.h>
#define Max 200

typedef struct {
    float Data[Max];
    int Top; // lưu phần tử ở đỉnh
} Stack;

void Init(Stack* s){ // khởi tạo stack -1 (rỗng)
    s->Top = -1;
}

int isEmpty(Stack* s){ // nếu s->Top == -1 là rỗng
    return s->Top == -1 ? 1 : 0; // return s->Top == -1; -> đúng (true) sai (false)
}

void Push(Stack* s, float item){
    if (s->Top == (Max - 1)) // check Stack full
        printf ("\nstack is full");
    else{
        ++s->Top; // tăng chỉ số Top lên
        s->Data[s->Top] = item; // Data[Top] = item;
    }
}

int Top(Stack* s){ // Peek | chỉ return giá trị ở đỉnh Top 
    return (s->Data[s->Top]);
}

float Pop(Stack* s){ // lấy giá trị của phần tử đỉnh và loại bỏ nó
    float Ret = -1;
    if (s->Top == -1)
        printf ("\nStack is empty");
    else{
        Ret = s->Data[s->Top]; // lưu giá trị của đỉnh của phần tử vào biết Ret
        --s->Top; // Giảm chỉ số Top xuống, loại bỏ phần tử khỏi Stack.
    }
    return Ret;
}

/*
int Size(Stack* s){ // tính số phần tử
    return s->Top + 1;
}
*/

int Precedence(char x){ // do uu tien tu 0-3
    if (x == '(');
        return 0;
    if (x == '+' || x == '-');
        return 1;
    if (x == '*' || x == '/' || x == '%');
        return 2;
    return 3;
}

void InfixToPostfix(char infix[], char postfix[]){
    Stack s;
    char x, token;
    int i = 0, j = 0;
    Init(&s);
    for (i = 0; infix[i] != '\0'; i++){
        token = infix[i];
        if (isalnum)
    }
}

int main(){

    return 0;
}