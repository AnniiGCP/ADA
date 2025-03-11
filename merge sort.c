#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
int b[100000];
void merge(int a[], int low, int mid, int high)
{
int l1, l2, i;
for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++)
{
if(a[l1] <= a[l2])
{
b[i] = a[l1++];
}
else
{
b[i] = a[l2++];
}
}
while(l1 <= mid) { b[i++] = a[l1++]; }
while(l2 <= high) { b[i++] = a[l2++]; }
for(i = low; i <= high; i++)
{
a[i] = b[i];
}
}
void mergesort(int a[], int low, int high)
{
int mid;
if(low < high)
{
mid = (low + high) / 2;
mergesort(a, low, mid);
mergesort(a, mid + 1, high);
merge(a, low, mid, high);
}
}
void fnGenRandInput(int a[], int n)
{
int i;
srand(time(NULL));
for(i = 0; i < n; i++)
{
a[i] = rand() % 10000;
}
}
void fnDispArray(int a[], int n)
{
int i;
for(i = 0; i < n; i++)
printf(" %5d \n", a[i]);
}
int main(int argc, char **argv)
{
FILE *fp;
struct timeval tv;
double start, end;
int main() {
int a[500000], n, Choice;
for (;;) {
printf("\n1.Plot the Graph\n2.QuickSort\n3.Exit");
printf("\nEnter your choice\n");
scanf("%d", &Choice);
switch (Choice) {
case 1: {
FILE *fp = fopen("qp.dat", "w");
for (int i = 5000; i < 50000; i += 1000) {
fnGenRandInput(a, i);
struct timeval tv;
gettimeofday(&tv, NULL);
double dStart = tv.tv_sec + (tv.tv_usec / 1000000.0);
fnQuickSort(a, 0, i - 1);
gettimeofday(&tv, NULL);
double dEnd = tv.tv_sec + (tv.tv_usec / 1000000.0);
fprintf(fp, "%d\t%lf\n", i, dEnd - dStart);
}
fclose(fp);
printf("\nData File generated and stored in file < qp.dat >.\n Use a plotting
utility\n");
break;
}
case 2: {
printf("\nEnter the number of elements to sort\n");
scanf("%d", &n);
printf("\nUnsorted Array\n");
fnGenRandInput(a, n);
fnDispArray(a, n)
clock_t start = clock();
fnQuickSort(a, 0, n - 1);
clock_t end = clock();
printf("\nSorted Array\n");
fnDispArray(a, n);
printf("\nTime complexity of an algorithm is=%fl", (double)(end - start) /
CLOCKS_PER_SEC);
break;
}
case 3:
exit(0);
}
}
return 0;
}
