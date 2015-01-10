#include <cstdio>
#include <cstring>
using namespace std;
int N;
char d[1005];

int main(void) {
  scanf("%d", &N);
  while((scanf("%s", d + 1) != EOF)) {
    int l = strlen(d + 1);
    printf("%s %d\n", d + 1, l);
  }

  return 0;
}
