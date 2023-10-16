#include <stdio.h>
int n;

void Conjuction() {
    for (char ch = 'p'; ch < 'p'+n; ch++) printf("%c\t", ch);
    printf("Conjuction\n");
    for (int i = 0; i < 9*n; i++) printf("-");
    printf("\n");

    for (int i = 0; i < (1 << n); i++) {
        int conjuction;
        for (int j = n-1; j >= 0; j--) {
            int bit = i & (1 << j);
            if (bit) bit = 1;

            printf("%d\t", bit);
            if (j == n-1) conjuction = bit;
            else conjuction = (conjuction & bit);
        }
        printf("%d\n", conjuction);
    }
    printf("\n");
}

void Disjunction() {
    for (char ch = 'p'; ch < 'p'+n; ch++) printf("%c\t", ch);
    printf("Disjunction\n");
    for (int i = 0; i < 9*n; i++) printf("-");
    printf("\n");

    for (int i = 0; i < (1 << n); i++) {
        int disjunction;
        for (int j = n-1; j >= 0; j--) {
            int bit = i & (1 << j);
            if (bit) bit = 1;

            printf("%d\t", bit);
            if (j == n-1) disjunction = bit;
            else disjunction = (disjunction | bit);
        }
        printf("%d\n", disjunction);
    }
    printf("\n");
}

void ExclusiveOR() {
    for (char ch = 'p'; ch < 'p'+n; ch++) printf("%c\t", ch);
    printf("Exclusive OR\n");
    for (int i = 0; i < 9*n; i++) printf("-");
    printf("\n");

    for (int i = 0; i < (1 << n); i++) {
        int xorV;
        for (int j = n-1; j >= 0; j--) {
            int bit = i & (1 << j);
            if (bit) bit = 1;

            printf("%d\t", bit);
            if (j == n-1) xorV = bit;
            else xorV = !(xorV == bit);
        }
        printf("%d\n", xorV);
    }
    printf("\n");
}

void Conditional() {
    for (char ch = 'p'; ch < 'p'+n; ch++) printf("%c\t", ch);
    printf("Conditional\n");
    for (int i = 0; i < 11*n; i++) printf("-");
    printf("\n");

    for (int i = 0; i < (1 << n); i++) {
        int con;
        for (int j = n-1; j >= 0; j--) {
            int bit = i & (1 << j);
            if (bit) bit = 1;

            printf("%d\t", bit);
            if (j == n-1) con = bit;
            else con = !(con && !bit);
        }

        printf("%d\n", con);
    }
    printf("\n");
}

void Biconditional() {
    for (char ch = 'p'; ch < 'p'+n; ch++) printf("%c\t", ch);
    printf("Biconditional\n");
    for (int i = 0; i < 11*n; i++) printf("-");
    printf("\n");

    for (int i = 0; i < (1 << n); i++) {
        int bicon;
        for (int j = n-1; j >= 0; j--) {
            int bit = i & (1 << j);
            if (bit) bit = 1;

            printf("%d\t", bit);
            if (j == n-1) bicon = bit;
            else bicon = (bicon == bit);
        }
        printf("%d\n", bicon);
    }
    printf("\n");
}


int main()
{
    scanf("%d", &n);

    Conjuction();
    Disjunction();
    ExclusiveOR();
    Conditional();
    Biconditional();

    return 0;
}
