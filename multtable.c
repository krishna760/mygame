#include <stdio.h>
void printTable(int *multTable, int num, int n){
    printf("\n\n\n");
    printf("The multiplication table of %d is :\n", num);
    for(int i=0; i<n; i++){
       multTable[i] = num*(i+1);
    }
printf("******************************************************\n");
    for(int i=0; i<n; i++){
    printf("%d * %d = %d\n", num, i+1, multTable[i]);
}
}
int main(){
    int multTable[3][10];
    printTable(multTable[0], 2, 100);
    printTable(multTable[1], 3, 100);
    printTable(multTable[2], 4, 100);
    printTable(multTable[3], 5, 100);

    return 0;
};