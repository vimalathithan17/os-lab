#include<stdlib.h>
#include<stdio.h>
void findSafeSequence(int n, int m, int alloc[n][m], int max[n][m], int avail[m], int f[n], int ans[n]) {
    int need[n][m];
    int ind = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (f[i] == 0) {
                int flag = 0;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    ans[ind++] = i;
                    for (int y = 0; y < m; y++) {
                        avail[y] += alloc[i][y];
                    }
                    f[i] = 1;
                }
            }
        }
    }
}

int main() {
    int n, m;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);

    int alloc[n][m], max[n][m], avail[m];
    int f[n], ans[n];

    printf("Enter the Allocation Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter the Max Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the Available Resources:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &avail[i]);
    }

    for (int i = 0; i < n; i++) {
        f[i] = 0;
    }

    findSafeSequence(n, m, alloc, max, avail, f, ans);
    
    int flag=0;
    for(int i=0;i<n;i++){
        if(f[i]==0){
            flag=1;
            break;
        }
    }
    if(flag==0){
    printf("Following is the SAFE Sequence\n");
    for (int i = 0; i < n - 1; i++) {
        printf(" P%d ->", ans[i]);
    }
    printf(" P%d\n", ans[n - 1]);
    }
    else{
        printf("no safe seq");
    }
    
    return 0;
}