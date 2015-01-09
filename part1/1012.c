#include <stdio.h>

#ifndef __BIG_NUM_H
#define __BIG_NUM_H

#define	MAXDIGITS	6000		/* maximum length bignum */

#define PLUS		1		/* positive sign bit */
#define MINUS		-1		/* negative sign bit */

typedef struct {
        char digits[MAXDIGITS];         /* represent the number */
        int signbit;			/* 1 if positive, -1 if negative */
        int lastdigit;			/* index of high-order digit */
} bignum;


void print_bignum(bignum *n);

void int_to_bignum(int s, bignum *n);

void initialize_bignum(bignum *n);

void add_bignum(bignum *a, bignum *b, bignum *c);

void subtract_bignum(bignum *a, bignum *b, bignum *c);

int compare_bignum(bignum *a, bignum *b);

void zero_justify(bignum *n);

void digit_shift(bignum *n, int d);		/* multiply n by 10^d */

void multiply_bignum(bignum *a, bignum *b, bignum *c);

//void divide_bignum(bignum *a, bignum *b, bignum *c);




#endif

static inline int max(int a, int b) { return a < b ? b : a; }

static inline int abs(int a) { return a < 0 ? - a : a; }

void print_bignum(bignum *n) {
        int i;

        if (n->signbit == MINUS) printf("- ");
        for (i=n->lastdigit; i>=0; i--)
                printf("%c",'0'+ n->digits[i]);

        printf("\n");
}

void int_to_bignum(int s, bignum *n)
{
        int i;				/* counter */
        int t;				/* int to work with */

        if (s >= 0) n->signbit = PLUS;
        else n->signbit = MINUS;

        for (i=0; i<MAXDIGITS; i++) n->digits[i] = (char) 0;

        n->lastdigit = -1;

        t = abs(s);

        while (t > 0) {
                n->lastdigit ++;
                n->digits[ n->lastdigit ] = (t % 10);
                t = t / 10;
        }

        if (s == 0) n->lastdigit = 0;
}

void initialize_bignum(bignum *n)
{
        int_to_bignum(0,n);
}




void add_bignum(bignum *a, bignum *b, bignum *c)
{
        int carry;			/* carry digit */
        int i;				/* counter */

        initialize_bignum(c);

        if (a->signbit == b->signbit) c->signbit = a->signbit;
        else {
                if (a->signbit == MINUS) {
                        a->signbit = PLUS;
                        subtract_bignum(b,a,c);
                        a->signbit = MINUS;
                } else {
                        b->signbit = PLUS;
                        subtract_bignum(a,b,c);
                        b->signbit = MINUS;
                }
                return;
        }

        c->lastdigit = max(a->lastdigit,b->lastdigit)+1;
        carry = 0;

        for (i=0; i<=(c->lastdigit); i++) {
                c->digits[i] = (char) (carry+a->digits[i]+b->digits[i]) % 10;
                carry = (carry + a->digits[i] + b->digits[i]) / 10;
        }

        zero_justify(c);
}


void subtract_bignum(bignum *a, bignum *b, bignum *c)
{
        int borrow;			/* has anything been borrowed? */
        int v;				/* placeholder digit */
        int i;				/* counter */

        initialize_bignum(c);

        if ((a->signbit == MINUS) || (b->signbit == MINUS)) {
                b->signbit = -1 * b->signbit;
                add_bignum(a,b,c);
                b->signbit = -1 * b->signbit;
                return;
        }

        if (compare_bignum(a,b) == PLUS) {
                subtract_bignum(b,a,c);
                c->signbit = MINUS;
                return;
        }

        c->lastdigit = max(a->lastdigit,b->lastdigit);
        borrow = 0;

        for (i=0; i<=(c->lastdigit); i++) {
                v = (a->digits[i] - borrow - b->digits[i]);
                if (a->digits[i] > 0)
                        borrow = 0;
                if (v < 0) {
                        v = v + 10;
                        borrow = 1;
                }

                c->digits[i] = (char) v % 10;
        }

        zero_justify(c);
}

int compare_bignum(bignum *a, bignum *b)
{
        int i;				/* counter */

        if ((a->signbit == MINUS) && (b->signbit == PLUS)) return(PLUS);
        if ((a->signbit == PLUS) && (b->signbit == MINUS)) return(MINUS);

        if (b->lastdigit > a->lastdigit) return (PLUS * a->signbit);
        if (a->lastdigit > b->lastdigit) return (MINUS * a->signbit);

        for (i = a->lastdigit; i>=0; i--) {
                if (a->digits[i] > b->digits[i]) return(MINUS * a->signbit);
                if (b->digits[i] > a->digits[i]) return(PLUS * a->signbit);
        }

        return(0);
}

void zero_justify(bignum *n)
{
        while ((n->lastdigit > 0) && (n->digits[ n->lastdigit ] == 0))
                n->lastdigit --;

        if ((n->lastdigit == 0) && (n->digits[0] == 0))
                n->signbit = PLUS;	/* hack to avoid -0 */
}


void digit_shift(bignum *n, int d)		/* multiply n by 10^d */
{
        int i;				/* counter */

        if ((n->lastdigit == 0) && (n->digits[0] == 0)) return;

        for (i=n->lastdigit; i>=0; i--)
                n->digits[i+d] = n->digits[i];

        for (i=0; i<d; i++) n->digits[i] = 0;

        n->lastdigit = n->lastdigit + d;
}



void multiply_bignum(bignum *a, bignum *b, bignum *c)
{
        bignum row;			/* represent shifted row */
        bignum tmp;			/* placeholder bignum */
        int i,j;			/* counters */

        initialize_bignum(c);

        row = *a;

        for (i=0; i<=b->lastdigit; i++) {
                for (j=1; j<=b->digits[i]; j++) {
                        add_bignum(c,&row,&tmp);
                        *c = tmp;
                }
                digit_shift(&row,1);
        }

        c->signbit = a->signbit * b->signbit;

        zero_justify(c);
}


int main(void) {
  int N, K;
  scanf("%d  %d", &N, &K);
  bignum nonzero, zero, z, co;
  int_to_bignum(K - 1, &co);
  int_to_bignum(K - 1, &nonzero);
  initialize_bignum(&zero);
  initialize_bignum(&z);
  for(int i = 1; i < N; i++) {
    bignum s, temp, mu;
    add_bignum(&z, &nonzero, &temp);
    add_bignum(&nonzero, &zero, &s);
    multiply_bignum(&s, &co, &mu);
    add_bignum(&z, &mu, &nonzero);
    add_bignum(&z, &temp, &zero);
  }
  bignum s;
  add_bignum(&nonzero, &zero, &s);
  print_bignum(&s);
  return 0;
}
