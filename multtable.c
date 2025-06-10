#include <stdio.h>
void printTable(int *multTable, int num, int n){
    printf("\n\n\n");
    printf("The multiplication table of %d is :\n", num);
    for(int i=0; i<n; i++){
       multTable[i] = num*(i+1);
    }
printf("******************************************************\n");
    for(int i=0; i<n; i++){
    printf("%d * %d = %d\n", num, i+1, multTable[i]); // Contains three %d placeholders for integers
}
}
int main(){
    int multTable[4][10];  //Declares a 2D array multTable[3][10]. This creates space for 3 rows (tables), each with 10 entries.
    printTable(multTable[0], 2, 10);
    printTable(multTable[1], 3, 10);
    printTable(multTable[2], 4, 10);
    printTable(multTable[3], 5, 10);

    return 0;
};
