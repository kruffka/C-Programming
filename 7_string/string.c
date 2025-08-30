#include <stdio.h>
#include <string.h> // for strlen()

int main() {

    char ch = 's';
    printf("%c == %d\n", ch, ch);

    char *str1 = "one";
    char str2[4] = "two";
    char str3[] = "three";
    char str4[] = {'f', 'o', 'u', 'r', '\0'};
    
    printf("str1 = %s; str2 = %s; str3 = %s str4 = %s\n", str1, str2, str3, str4);
    printf("%d == %c\n", str4[0], str4[0]);
    printf("strlen str3 = %ld; sizeof of str3 = %ld\n", strlen(str3), sizeof(str3));


    char name[20];
    printf("Enter name: ");
    scanf("%s", name);
    printf("Your name is %s", name);
    
    // char name1[20];
    // printf("Enter name: ");
    // fgets(name1, sizeof(name1), stdin);  // read string
    // printf("Name: ");
    // puts(name1);    // display string



    return 0;
}