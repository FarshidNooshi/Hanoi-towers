//In The Name Of GOD
#include<math.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<stdbool.h>

const int MAXN = 131072 + 15;
int typ[MAXN], v[MAXN], fr[MAXN], to[MAXN];
int typ2[MAXN], v2[MAXN], fr2[MAXN], to2[MAXN];
int n, pt, pt2;

int main(void) {
    scanf("%d", &n);
    typ[pt] = 0, v[pt] = n, fr[pt] = 1, to[pt++] = 3;
    while (pt--) {
        if (v[pt] == 0)
            continue;
        if (typ[pt] == 1)
            typ2[pt2] = 0, v2[pt2] = v[pt], fr2[pt2] = fr[pt], to2[pt2++] = to[pt];
        else {
            if (fr[pt] == 1) {
				if (to[pt] == 3) {
                    typ[pt] = 0, v[pt] -= 1, fr[pt] = 1, to[pt++] = 2;
                    typ[pt] = 1, v[pt] = v[pt - 1] + 1, fr[pt] = 1, to[pt++] = 3;
                    typ[pt] = 0, v[pt] = v[pt - 1] - 1, fr[pt] = 2, to[pt++] = 3;
				}
				else if (to[pt] == 2) {
                    typ[pt] = 0, v[pt] -= 1, fr[pt] = 1, to[pt++] = 3;
                    typ[pt] = 1, v[pt] = v[pt - 1] + 1, fr[pt] = 1, to[pt++] = 2;
                    typ[pt] = 0, v[pt] = v[pt - 1] - 1, fr[pt] = 3, to[pt++] = 2;
				}
			}
			else if (fr[pt] == 2) {
				if (to[pt] == 3) {
                    typ[pt] = 0, v[pt] -= 1, fr[pt] = 2, to[pt++] = 1;
                    typ[pt] = 1, v[pt] = v[pt - 1] + 1, fr[pt] = 2, to[pt++] = 3;
                    typ[pt] = 0, v[pt] = v[pt - 1] - 1, fr[pt] = 1, to[pt++] = 3;
				}
				else if (to[pt] == 1) {
                    typ[pt] = 0, v[pt] -= 1, fr[pt] = 2, to[pt++] = 3;
                    typ[pt] = 1, v[pt] = v[pt - 1] + 1, fr[pt] = 2, to[pt++] = 1;
                    typ[pt] = 0, v[pt] = v[pt - 1] - 1, fr[pt] = 3, to[pt++] = 1;
				}
			}
			else {
				if (to[pt] == 1) {// az 3 be 1
                    typ[pt] = 0, v[pt] -= 1, fr[pt] = 3, to[pt++] = 2;
                    typ[pt] = 1, v[pt] = v[pt - 1] + 1, fr[pt] = 3, to[pt++] = 1;
                    typ[pt] = 0, v[pt] = v[pt - 1] - 1, fr[pt] = 2, to[pt++] = 1;
				}
				else if (to[pt] == 2) { // az 3 be 2
                    typ[pt] = 0, v[pt] -= 1, fr[pt] = 3, to[pt++] = 1;
                    typ[pt] = 1, v[pt] = v[pt - 1] + 1, fr[pt] = 3, to[pt++] = 2;
                    typ[pt] = 0, v[pt] = v[pt - 1] - 1, fr[pt] = 1, to[pt++] = 2;
				}
			}
        }
    }
    while (pt2-- != 0) 
        printf("%d from %d to %d\n", v2[pt2], fr2[pt2], to2[pt2]);
    return 0;
}