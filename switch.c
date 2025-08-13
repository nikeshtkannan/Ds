#include <stdio.h>
void c(int chose){
    printf("Choose 1 or 2");
    scanf("%d",&chose)
    switch (chose)
    {
    case 1:
        printf("noob");
        break;
    case 2:
        printf("pro");
    
    default:
        printf("errror");
        break;
    }
}

int main(){
    int choose;
    printf("Enter any num");
    printf("1 for c\n2 for python");
    scanf("%d",&choose);
    switch(choose){
        case 1:
            c();
            break;
        case 2:
            python();
            break;
        default:
            printf("invalid entering");
    }
    return 0;
}