#include <cstdio>
#include <windows.h>
#include <cstdlib>
#include <random>

#define Height 27 //游戏画面尺寸
#define Width 133
int Cells[Height][Width]; //所有位置随机置1或0
int tempCells[Height][Width]; //临时矩阵
std::default_random_engine r;
void hideCursor() {
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};  // 第二个值为0表示隐藏光标
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void movexy(int x, int y) {
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void startup() {
    for (auto & Cell : Cells) {
        for (int & j : Cell) {
            j = r() % 2;
        }
    }
    hideCursor();
}

void show() {
    movexy(0, 0);
    for (auto & Cell : Cells) {
        for (int j : Cell) {
            if (j) printf("*"); //活的细胞输出
            else printf(" ");             //死的细胞为空
        }
        printf("\n");
    }
    Sleep(150);
}

void updateWithoutInput() { //游戏内部更新
    int NeighbourNum;   //周边细胞的数目
    for (int i = 1; i < Height - 1; ++i) {
        for (int j = 1; j < Width - 1; ++j) {
            NeighbourNum = Cells[i - 1][j - 1] + Cells[i - 1][j] + Cells[i - 1][j + 1] +
                           Cells[i][j - 1] + Cells[i][j] + Cells[i][j + 1] +
                           Cells[i + 1][j - 1] + Cells[i + 1][j] + Cells[i + 1][j + 1];
            if (Cells[i][j] == 1) { //Any live cell
                if (NeighbourNum < 2)
                    tempCells[i][j] = 0; //fewer than two live neighbours dies, underpopulation
                else if ((NeighbourNum == 2 || NeighbourNum == 3))
                    tempCells[i][j] = 1; //two or three live neighbours lives on to the next generation
                else if (NeighbourNum > 3)
                    tempCells[i][j] = 0; //more than three live neighbours dies, overpopulation
            }
            else if (NeighbourNum == 3 && Cells[i][j] == 0) //Any dead cell
                tempCells[i][j] = 1; //exactly three live neighbours becomes a live cell,reproduction.

        }
    }
    for (int i = 1; i < Height - 1; ++i)
        for (int j = 1; j < Width - 1; ++j)
            Cells[i][j] = tempCells[i][j];
}

void updateWithInput() { //用户输入相关更新
    for(int i=Height/2-3;i<Height/2+3;i++)
        for(int j=Width/2-3;j<Width/2+3;j++)
            Cells[i][j]=1;
}

int main() {
    startup();
    while (1) {
        system("cls");
        show();
        updateWithoutInput();
        updateWithInput();
    }
    return 0;
}

