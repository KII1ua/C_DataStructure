#include <stdio.h>

int main() {
    int ken[3][3] = {{2, 3, 4}, {5, 6, 7}, {8, 9, 10}};
    int boo[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int yoo[3][3], soo[3][3] = {0,}, i, j, k;
    int Trans_A[3][3] = {0,};
    int S[4][5] = {{0, 0, 0, 0, 0}, {0, 0, 7, 0, 0}, {0, 0, 0, 0, 0}, {0, -3, 0, 0, 0}};
    int S_M[3][3] = {{4, 5, 2}, {2, 3, 7}, {4, 2, -3}};
    int S_M_T[4][5] = {0,}, x, y, z, m, n;

    printf("********* result **********\n\n");
    printf("=== 원시행렬 ken[3][3] ===\n");

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%4d", ken[i][j]);
        }
        printf("\n");
    }

    printf("\n=== 원시행렬 boo[3][3] ===\n");

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%4d", boo[i][j]);
        }
        printf("\n");
    }

    printf("\n=== 행렬 빼기(ken[3][3]-boo[3][3])===\n");

    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            yoo[i][j] = ken[i][j] - boo[i][j];

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++)
            printf("%4d", yoo[i][j]);
        printf("\n");
    }

    printf("\n=== 행렬 곱하기(ken[3][3] * boo[3][3]) ===\n");

    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            for(k = 0; k < 3; k++)
                soo[i][j] += ken[i][k] * boo[k][j];

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++)
            printf("%4d", soo[i][j]);
        printf("\n");
    }

    printf("\n=== 전치행렬 of(ken[3][3]) ===\n");       // 전치행렬은 A = (m,n) 행렬에서 행과 열을 바꾸어 생기는 A' = (n,m) 행렬이다.

    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            Trans_A[j][i] = ken[i][j];

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++)
            printf("%4d", Trans_A[i][j]);
        printf("\n");
    }

    printf("\n=== 희소행렬 S[4][5] ===\n");     // 희소행렬은 행렬을 구성하는 요소 중 많은 항들이 0으로 되어 있는 행렬이다.

    for(i = 0; i < 4; i++) {
        for(j = 0; j < 5; j++)
            printf("%4d", S[i][j]);
        printf("\n");
    }

    printf("\n=== 메모리 절약 배열 S_M[3][3] ===\n");

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++)
            printf("%4d", S_M[i][j]);
        printf("\n");
    }

    printf("\n=== 전치행렬 of 메모리 절약 배열 S_M[3][3] ===\n");

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++)
            printf("%4d", S_M[j][i]);
        printf("\n");
    }

    printf("\n=== 메모리 절약 배열 S_M[3][3]에서 희소행렬 S_M_T[4][5]로 변환 ===");

    for(i = 0; i < S_M[0][0]; i++) {
        printf("\n");
        for(j = 0; j < S_M[0][1]; j++) {
            S_M_T[i][j] = 0;
            for(x = 1; x < 3; x++) {
                m = S_M[x][0];
                n = S_M[x][1];
                S_M_T[m-1][n-1] = S_M[x][2];
            }
            printf("%4d", S_M_T[i][j]);
        }
    }
    getchar();
}