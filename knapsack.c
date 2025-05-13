#include<stdio.h>
#define MAX 50
int p[MAX];
int w[MAX];
int x[MAX];
int t[MAX];
double maxprofit;
int n, m, i, j;
void bubblesort(int n, int w[], int p[], int t[]) {
 int temp, i, j;
 for (i = 1; i <= n; i++)
 t[i] = i;
 for (i = 1; i < n; i++)
 for (j = 1; j <= n - i; j++)
 if ((double)p[t[j]] / w[t[j]] < (double)p[t[j+1]] / w[t[j+1]]) {
 temp = t[j];
 t[j] = t[j+1];
 t[j+1] = temp;
 }
}
void greedyknapsack(int n, int w[], int p[], int m) {
 int rc = m;
 maxprofit = 0;
 bubblesort(n, w, p, t);
 for (i = 1; i <= n; i++) {
 if (w[t[i]] > rc) continue;
 x[t[i]] = 1;
 rc -= w[t[i]];
 maxprofit += p[t[i]];
 }
 printf("Optimal solution for greedy method: %lf\n", maxprofit);
 printf("Solution vector for greedy method: \n");
 for (i = 1; i <= n; i++)
 printf("%d\t", x[i]);
 printf("\n");
}
void continuousKnapsack(int n, int w[], int p[], int m) {
 double rc = m;
 double totalProfit = 0;
 double fraction;
 bubblesort(n, w, p, t);
 for (i = 1; i <= n; i++) {
 if (w[t[i]] <= rc) {
 rc -= w[t[i]];
 totalProfit += p[t[i]];
 } else {
 fraction = rc / w[t[i]];
 totalProfit += p[t[i]] * fraction;
 break;
 }
 }
 printf("Optimal solution for continuous knapsack method: %lf\n", totalProfit);
}
int main() {
 printf("Enter the number of Objects: ");
 scanf("%d", &n);
 printf("Enter the object's weights: ");
 for (i = 1; i <= n; i++)
 scanf("%d", &w[i]);
 printf("Enter the object's profits: ");
 for (i = 1; i <= n; i++)
 scanf("%d", &p[i]);
 printf("Enter the maximum capacity: ");
 scanf("%d", &m);
 for (i = 1; i <= n; i++)
 x[i] = 0;
 greedyknapsack(n, w, p, m);
 continuousKnapsack(n, w, p, m);
 return 0;
}
