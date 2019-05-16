#include <stdio.h>
#include <stdlib.h>

int fact_2halves(int st, int ed){

    int p;

    printf("(%d,%d),", st,ed);

    printf("    (st,ed) = (%d,%d)\n", st,ed);

    if (st==ed) return st;

    p = (st+ed)/2;

    return fact_2halves(st, p)*fact_2halves(p+1,ed);

}

int main(){
    int i;
    i = fact_2halves(1,7);
    printf("%d", i);
}
