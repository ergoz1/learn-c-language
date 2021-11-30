#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <windows.system.h>

/**
*   使用递归解决汉诺塔问题
*/

// 定义结构体用来存放每个柱子当前的塔片情况
typedef struct _tower_array{
    int len;
    int array[];
}tower_array;

typedef struct _hanNuoTower{
    tower_array* p_data;
    char name;
}hanNuoTower;

hanNuoTower* han_a = NULL;
hanNuoTower* han_b = NULL;
hanNuoTower* han_c = NULL;

void hanNuoTowerMove(int n, hanNuoTower* a, hanNuoTower* b, hanNuoTower* c);
void move(hanNuoTower* from hanNuoTower* to);
int total;

void printf_han_data(hanNuoTower* han){
    int i = 0;
    printf("%c:", han->name);
    for(i = 0;i<han->p_data->len;i++){
        printf("%d-",han->p_data->array[i]);
    }
    printf("\n");
}

int main(){
    int i, n = 0;
    printf("请先确认A柱子上一共有多少个塔片：\n");
    scanf("%d", &n);
    total = n;

    //初始化第一根柱子
    han_a = (hanNuoTower*) malloc(sizeof(hanNuoTower));
    han_a->name = 'A';
    han_a->p_data = (tower_array*) malloc(sizeof(tower_array) + sizeof(int) * n);
    han_a->p_data->len = n;
    for(i = 0;i < n;i++){
        han_a->p_data->array[i] = i+1;
    }
    printf_han_data(han_a);

    //初始化第二根柱子
    han_b = (hanNuoTower*) malloc(sizeof(hanNuoTower));
    han_b->name = 'B';
    han_b->p_data = (tower_array*) malloc(sizeof(tower_array) + sizeof(int) * n);
    memset(han_b->p_data, 0, sizeof(tower_array) + sizeof(int) * n);
    han_b->p_data->len = n;
    printf_han_data(han_b);

    //初始化第三根柱子
    han_c = (hanNuoTower*) malloc(sizeof(hanNuoTower));
    han_c->name = 'C';
    han_c->p_data = (tower_array*) malloc(sizeof(tower_array) + sizeof(int) * n);
    memset(han_c->p_data, 0, sizeof(tower_array) + sizeof(int) * n);
    han_c->p_data->len = n;
    printf_han_data(han_c);
    printf("---------------------------\n");

    hanNuoTowerMove(n, han_a, han_b, han_c);
    printf("\n");
    system("pause");
    return 0;
}

void hanNuoTowerMove(int n, hanNuoTower* a, hanNuoTower* b, hanNuoTower* c){
    int j = 0;
    if(n == 1){
        for(j = 0;j < total; j++){
            if(a->p_data->array[j] != 0){
                a->p_data->array[j] = 0;
                break;
            }
        }
        for(j = total - 1;j >= 0; j--){
            if(c->p_data->array[j] == 0){
                c->p_data->array[j] = 1;
                break;
            }
        }
        printf_han_data(han_a);
        printf_han_data(han_b);
        printf_han_data(han_c);
        printf("---------------------------\n");
    } else {
        hanNuoTowerMove(n-1, a, c, b);
        move(a, c);
        printf_han_data(han_a);
        printf_han_data(han_b);
        printf_han_data(han_c);
        printf("---------------------------\n");
        hanNuoTowerMove(n-1, b, a, c);
    }
}

void move(hanNuoTower* from, hanNuoTower* to){
    int i, tmp = 0;
    for(i = 0;i < total;i++){
        if(from->p_data->array[i] != 0){
            tmp = from->p_data->array[i];
            from->p_data->array[i] = 0;
            break;
        }
    }
    for(i = total - 1;i >= 0;i--){
        if(to->p_data->array[i] == 0){
            to->p_data->array[i] = tmp;
            break;
        }
    }
}