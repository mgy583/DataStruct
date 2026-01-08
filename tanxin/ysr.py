import math, random, itertools
from typing import List, Tuple, Dict

RC = 5, 5          # 棋盘尺寸
START = (2, 2)     # 启动器坐标
BASE = 2.0         # 距离衰减底数
W_SYN = 1.0        # 合成潜力权重
W_DIS = 0.6        # 距离权重
W_BLK = 0.4        # 堵路惩罚权重
K_PERTURB = 30     # 微扰轮数

class Unit:
    def __init__(self, typ: str, lvl: int = 1, mul: int = 1):
        self.typ = typ          # 'troop' or 'mul'
        self.lvl = lvl          # 等级或倍率值
        self.mul = mul          # 倍率齿轮的数值

    def value(self) -> float:
        return self.lvl * (self.mul if self.typ == 'mul' else 1)

    def __repr__(self):
        return f"{self.typ[0]}{self.lvl}" if self.typ == 'troop' else f"×{self.mul}"


class Board:
    def __init__(self, rc: Tuple[int, int], start: Tuple[int, int]):
        self.R, self.C = rc
        self.start = start
        self.grid: Dict[Tuple[int, int], Unit] = {}  # (r,c) -> Unit

    def copy(self):
        b = Board((self.R, self.C), self.start)
        b.grid = self.grid.copy()
        return b

    def empty_cells(self) -> List[Tuple[int, int]]:
        all_cells = [(r, c) for r in range(self.R) for c in range(self.C)]
        return [p for p in all_cells if p not in self.grid]

    def manhattan(self, p):
        return abs(p[0] - self.start[0]) + abs(p[1] - self.start[1])

    def cell_score(self, p) -> float:
        return BASE ** (-self.manhattan(p))

    def neighbours(self, p):
        r, c = p
        for dr, dc in ((0, 1), (1, 0), (0, -1), (-1, 0)):
            nr, nc = r + dr, c + dc
            if 0 <= nr < self.R and 0 <= nc < self.C:
                yield (nr, nc)
                

def expect_score(board: Board) -> float:
    """纯公式算期望总输出，不物理模拟"""
    total = 0.0
    for p, u in board.grid.items():
        if u.typ == 'troop':
            # 倍率链 = 相邻所有倍率齿轮的乘积
            chain = 1.0
            for q in board.neighbours(p):
                nb = board.grid.get(q)
                if nb and nb.typ == 'mul':
                    chain *= nb.mul
            # 被激活期望次数 ∝ 启动器距离衰减
            act = board.cell_score(p)
            total += u.lvl * chain * act
    return total


def synth_potential(board: Board, p: Tuple[int, int], u: Unit) -> float:
    if u.typ == 'mul':
        # 倍率齿轮：看相邻最高 troop 等级
        return max((board.grid[q].lvl for q in board.neighbours(p)
                   if q in board.grid and board.grid[q].typ == 'troop'), default=0)
    else:
        # troop：统计同等级邻居
        same = 0
        for q in board.neighbours(p):
            if q in board.grid and board.grid[q].typ == 'troop' and board.grid[q].lvl == u.lvl:
                same += 1
        return same
    

def placement_score(board: Board, p: Tuple[int, int], u: Unit) -> float:
    pot = synth_potential(board, p, u)
    dis = board.cell_score(p)
    # 简单堵路：空邻居越少越差
    empty_nei = sum(1 for q in board.neighbours(p) if q not in board.grid)
    block = max(0, 2 - empty_nei)
    return W_SYN * pot + W_DIS * dis - W_BLK * block


def greedy_place(units: List[Unit], board: Board) -> Board:
    units = sorted(units, key=lambda u: u.value(), reverse=True)
    for u in units:
        best_p = max(board.empty_cells(),
                    key=lambda p: placement_score(board, p, u))
        board.grid[best_p] = u
    return board


def perturb(board: Board, k: int = K_PERTURB) -> Board:
    best = board.copy()
    best_score = expect_score(best)
    cells = list(best.grid.keys())
    for _ in range(k):
        p, q = random.sample(cells, 2)
        # 交换
        best.grid[p], best.grid[q] = best.grid[q], best.grid[p]
        sc = expect_score(best)
        if sc > best_score:
            best_score = sc
        else:
            # 回退
            best.grid[p], best.grid[q] = best.grid[q], best.grid[p]
    return best


def solve(units: List[Unit]) -> List[Tuple[Tuple[int, int], Unit]]:
    board = greedy_place(units, Board(RC, START))
    board = perturb(board)
    return [(p, u) for p, u in board.grid.items()]


if __name__ == "__main__":
    # 随机生成一局商店购物车
    random_units = [Unit('troop', lvl=random.randint(1, 3)) for _ in range(15)] + \
                  [Unit('mul', mul=random.choice([2, 3])) for _ in range(7)]
    random.shuffle(random_units)
    solution = solve(random_units)
    board = Board(RC, START)
    board.grid = {p: u for p, u in solution}
    print("期望总输出:", expect_score(board))
    # 打印棋盘
    for r in range(RC[0]):
        print(" ".join(str(board.grid.get((r, c), "__")) for c in range(RC[1])))