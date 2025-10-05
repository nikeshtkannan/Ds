#include <stdio.h>
#include <string.h>

void main(){
    char meal[10];
    int count=0;
    printf("Welcome to our hotel\n");
    while(1){
        printf("Plz select our menu\n");
        printf("1. Porotta \n2. Meal\n3. Biriyani\n4. CoolDrinks\n");
        printf("Enter what you want:\n");
        scanf("%s" ,meal);
        if(strcmp(meal,"porotta")==0)
        {
            count++;
            printf("You have selected 'Porotta'!!!!, %d items selected\n",count);
        }
        else if (strcmp(meal,"meal")==0)
        {
            count++;
            printf("You have selected 'Meal'!!!!, %d items selected\n",count);
        }
        else if (strcmp(meal,"biriyani")==0)
        {
            count++;
            printf("You have selected 'Biriyani'!!!!, %d items selected\n",count);
        }
        else if (strcmp(meal,"cooldrinks")==0)
        {
            count++;
            printf("You have selected 'CoolDrinks'!!!!, %d items selected\n",count);
        }
        else{
            printf("Wrong input!!!!!!!!");
            break;
        }
    }
}