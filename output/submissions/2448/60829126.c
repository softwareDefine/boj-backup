#include <stdio.h>
#include <stdlib.h> 
void recursive(char **arr, int x, int y,int h, int offset); 
void print(char **arr,int w, int h);

int main(void) { 
    char **arr; 
    int w,i,h,j; 
    scanf("%d", &h);
    arr = (char**)malloc(sizeof(*arr) * h); 
    w = h * 2 + 1;
    for (i = 0; i < h; ++i) { 
        arr[i] = (char*)malloc(sizeof(*arr) * w + 1); 
        arr[i][w] = '\0'; } 
    for(i=0;i<h;++i) {
        for(j=0;j<w;++j) { 
            arr[i][j] = ' '; 
        } 
    } 
    recursive(arr, 0, 0, h, h-1); 
    print(arr, w, h); 
    free(arr); 
    return 0; } 
void print(char **arr,int w,int h) { 
    int i, j; 
    for (i = 0; i < h; ++i) { 
        printf("%s\n", arr[i]); 
    } 
} 
void recursive(char **arr, int x, int y, int h,int offset) {
    int i,pad = offset - y; 
    if(h==3) { 
        arr[y][x + pad--] = '*';
        arr[y + 1][x + pad] = '*';
        arr[y + 1][x + 2 + pad--] = '*';
        for(i=0;i<5;++i) 
            arr[y + 2][x + i + pad] = '*';
        return;
        } 
    else { 
        recursive(arr,x+h,y+h/2,h/2,offset); 
        recursive(arr,x,y+h/2,h/2,offset); recursive(arr,x,y,h/2,offset); 
    }
    }
