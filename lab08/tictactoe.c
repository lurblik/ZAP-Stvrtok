#include <stdio.h>

void draw(const int size, char field[][size]);
int add_cross(const int size, char field[][size], const int y, const int x, const char player);
int is_solved(const int size, char field[][size]);
int main(){
    int size = 0;
    do{
        printf("Enter the size of field: ");
        scanf("%d", &size);
    }while(size < 4 || size > 9);
    char field[size][size];
    for(int y=0; y<size; y++){
        for(int x=0; x<size; x++){
            field[y][x] = ' ';
        }
    }
    draw(size, field);
    char player = 'B';
    do{
        player = (player == 'A') ? 'B' : 'A';
        printf("Player %c:", player);
        int x = 0;
        int y = 0;
        scanf("%d %d", &x, &y);
        int result = add_cross(size, field, y, x, player);
        if(result == -1){
            printf("Wrong position!\n");
        } else if(result == 0){
            printf("X is already there!\n");
        }
        draw(size, field);
    }while(is_solved(size, field) == 0);
    printf("Player %c wins!\n", player);
    return 0;
}

void draw(const int size, char field[][size]){
    for(int y=size; y>0; y--){
        printf("  ");
        for(int i=0; i<size; i++){
            printf("+-");
        }
        printf("+\n");
        printf("%d ", y);
        for(int i=0; i<size; i++){
            printf("|%c", field[size-y][i]);
        }
        printf("|\n");
        printf("  ");
        for(int i=0; i<size; i++){
            printf("+-");
        }
        printf("+\n");
    }
    
    for(int i=0; i<size; i++){
        printf(" %d", i+1);
    }
    printf(" \n");
}

int add_cross(const int size, char field[][size], const int y, const int x, const char player){
    if(x-1 < 0 || x-1 > size || size-y < 0 || size-y > size){
        return -1;
    }
    if(field[size-y][x-1] == 'X' || field[size-y][x-1] == 'O'){
        return 0;
    }
    field[size-y][x-1] = (player == 'A') ? 'X' : 'O';
    return 1;
}

int is_solved(const int size, char field[][size]){
    for(int y = 0; y < size-2; y++){
        for(int x = 0; x < size-2; x++){
            char tmp = field[y][x];
            if(tmp == ' '){
                continue;
            }
            // horizontal check
            if(field[y][x+1] == tmp && field[y][x+2] == tmp){
                return 1;
            }
            // vertical check
            if(field[y+1][x] == tmp && field[y+2][x] == tmp){
                return 1;
            }
            // diagonal 1
            if(field[y+1][x+1] == tmp && field[y+2][x+2] == tmp){
                return 1;
            }
        }
    }
    // diagonal 2
    for(int y = 2; y < size; y++){
        for(int x = 0; x < size-2; x++){
            char tmp = field[y][x];
            if(tmp == ' '){
                continue;
            }
            if(field[y-1][x+1] == tmp && field[y-2][x+2] == tmp){
                return 1;
            }
        }
    }

    return 0;
}
