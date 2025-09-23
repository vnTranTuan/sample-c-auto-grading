#include <stdio.h>
#include "my_functions.h"

int main() {
    int so1, so2;
    int Tong;

    printf("Nhap vao so thu nhat: ");
    scanf("%d", &so1);

    printf("Nhap vao so thu hai: ");
    scanf("%d", &so2);

    Tong = Tinh_Tong(so1, so2);

    printf("Tong hai so la: %d\n", Tong);

    return 0;
}
