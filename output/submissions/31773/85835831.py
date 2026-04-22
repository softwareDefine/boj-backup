import sys
import threading

def main():
    import sys
    import math
    sys.setrecursionlimit(1 << 25)
    N, P = map(int, sys.stdin.readline().split())
    posts = []
    for _ in range(P):
        x, y = map(int, sys.stdin.readline().split())
        posts.append((x, y))

    # 울타리의 변과 누적 둘레 길이 계산
    edges = []
    perimeter_positions = [0]
    total_perimeter = 0
    for i in range(len(posts)):
        x1, y1 = posts[i]
        x2, y2 = posts[(i + 1) % len(posts)]
        length = abs(x2 - x1) + abs(y2 - y1)
        total_perimeter += length
        perimeter_positions.append(total_perimeter)
        edges.append({
            'start': (x1, y1),
            'end': (x2, y2),
            'perimeter_start': perimeter_positions[-2],
            'perimeter_end': perimeter_positions[-1]
        })

    # 엣지 인덱싱
    horizontal_edges = {}
    vertical_edges = {}
    for edge in edges:
        x1, y1 = edge['start']
        x2, y2 = edge['end']
        if y1 == y2:
            y = y1
            x_start, x_end = sorted([x1, x2])
            if y not in horizontal_edges:
                horizontal_edges[y] = []
            horizontal_edges[y].append({
                'x_start': x_start,
                'x_end': x_end,
                'perimeter_start': edge['perimeter_start'],
                'perimeter_end': edge['perimeter_end']
            })
        elif x1 == x2:
            x = x1
            y_start, y_end = sorted([y1, y2])
            if x not in vertical_edges:
                vertical_edges[x] = []
            vertical_edges[x].append({
                'y_start': y_start,
                'y_end': y_end,
                'perimeter_start': edge['perimeter_start'],
                'perimeter_end': edge['perimeter_end']
            })

    # 각 소에 대해 시작점과 끝점의 둘레 위치 계산
    cow_distances = []
    for _ in range(N):
        x1, y1, x2, y2 = map(int, sys.stdin.readline().split())

        def find_position(x, y):
            # 수평 엣지에서 찾기
            if y in horizontal_edges:
                for edge in horizontal_edges[y]:
                    if edge['x_start'] <= x <= edge['x_end']:
                        proportion = (x - edge['x_start']) / (edge['x_end'] - edge['x_start'])
                        position = edge['perimeter_start'] + proportion * (edge['perimeter_end'] - edge['perimeter_start'])
                        return position
            # 수직 엣지에서 찾기
            if x in vertical_edges:
                for edge in vertical_edges[x]:
                    if edge['y_start'] <= y <= edge['y_end']:
                        proportion = (y - edge['y_start']) / (edge['y_end'] - edge['y_start'])
                        position = edge['perimeter_start'] + proportion * (edge['perimeter_end'] - edge['perimeter_start'])
                        return position
            # 엣지를 찾지 못한 경우
            raise ValueError(f"Point ({x}, {y}) is not on any edge.")

        pos_start = find_position(x1, y1)
        pos_end = find_position(x2, y2)

        # 최단 거리 계산
        distance_clockwise = abs(pos_end - pos_start)
        distance_counter_clockwise = total_perimeter - distance_clockwise
        min_distance = min(distance_clockwise, distance_counter_clockwise)
        cow_distances.append(int(round(min_distance)))

    # 결과 출력
    for dist in cow_distances:
        print(dist)

if __name__ == '__main__':
    threading.Thread(target=main).start()
