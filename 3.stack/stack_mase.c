#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100

typedef struct StackNode {
    int data[MAXSIZE];
    int top;
} StackNode;

void initStack(StackNode* stack) {
    stack->top = -1;
}

int isFull(StackNode* stack) {
    return stack->top == MAXSIZE - 1;
}

int isEmpty(StackNode* stack) {
    return stack->top == -1;
}

int push(StackNode* stack, int value) {
    if (isFull(stack)) {
        return -1; // Stack overflow
    }
    stack->data[++(stack->top)] = value;
    return 0; // Success
}

int pop(StackNode* stack, int* value) {
    if (isEmpty(stack)) {
        return -1; // Stack underflow
    }
    if (value) { *value = stack->data[stack->top]; }
    stack->top--;
    return 0; // Success
}

int peek(StackNode stack, int* value) {
    if (isEmpty(&stack)) {
        return -1; // Stack is empty
    }
    *value = stack.data[stack.top];
    return 0; // Success
}

static int pack_pos(int r, int c, int cols) { return r * cols + c; }
static void unpack_pos(int code, int cols, int* r, int* c) { *r = code / cols; *c = code % cols; }

int solve_maze(int rows, int cols, int map[6][6], int* out_path, int max_path, int* out_len) {
    int i, j;
    int entries[24];
    int entry_count = 0;
    for (j = 0; j < cols; ++j) {
        if (map[0][j] == 1) entries[entry_count++] = pack_pos(0, j, cols);
        if (rows > 1 && map[rows - 1][j] == 1) entries[entry_count++] = pack_pos(rows - 1, j, cols);
    }
    for (i = 1; i < rows - 1; ++i) {
        if (map[i][0] == 1) entries[entry_count++] = pack_pos(i, 0, cols);
        if (cols > 1 && map[i][cols - 1] == 1) entries[entry_count++] = pack_pos(i, cols - 1, cols);
    }
    if (entry_count < 2) return -1;
    int start = entries[0];
    int goal = entries[entry_count - 1];
    int visited[6][6] = {0};
    StackNode st; initStack(&st);
    push(&st, start);
    int sr, sc; unpack_pos(start, cols, &sr, &sc); visited[sr][sc] = 1;
    const int dr[4] = {-1,0,1,0};
    const int dc[4] = {0,1,0,-1};
    while (!isEmpty(&st)) {
        int cur_code; peek(st, &cur_code);
        int r, c; unpack_pos(cur_code, cols, &r, &c);
        if (cur_code == goal) {
            int len = st.top + 1; if (len > max_path) return -2;
            for (i = 0; i < len; ++i) out_path[i] = st.data[i];
            *out_len = len; return 0;
        }
        int moved = 0;
        for (i = 0; i < 4; ++i) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && map[nr][nc] == 1 && !visited[nr][nc]) {
                visited[nr][nc] = 1; push(&st, pack_pos(nr, nc, cols)); moved = 1; break;
            }
        }
        if (!moved) { int tmp; pop(&st, &tmp); }
    }
    return -3;
}

int main() {
    int map[][6] = {
        0,0,1,0,0,0,
        0,0,1,1,1,0,
        0,0,1,0,0,0,
        0,1,1,1,1,0,
        0,0,1,0,1,0,
        0,0,0,0,1,0
    };

    const int ROWS = 6, COLS = 6;
    int path[MAXSIZE];
    int path_len = 0;
    int rc = solve_maze(ROWS, COLS, map, path, MAXSIZE, &path_len);
    if (rc != 0) {
        printf("No path found or error (code %d)\n", rc);
        return 0;
    }

    printf("Path length: %d\n", path_len);
    for (int k = 0; k < path_len; ++k) {
        int r, c; unpack_pos(path[k], COLS, &r, &c);
        printf("(%d,%d)%s", r, c, (k == path_len - 1 ? "\n" : " -> "));
    }

    char render[6][6];
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            render[i][j] = map[i][j] ? '.' : '#';
        }
    }
    for (int k = 0; k < path_len; ++k) {
        int r, c; unpack_pos(path[k], COLS, &r, &c);
        render[r][c] = '*';
    }
    printf("\nMaze with path (*):\n");
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            printf("%c ", render[i][j]);
        }
        printf("\n");
    }

    return 0;
}
