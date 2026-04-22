import sys
import threading
import bisect

def main():
    import math
    sys.setrecursionlimit(1 << 25)
    N, P = map(int, sys.stdin.readline().split())
    posts = []
    for _ in range(P):
        x, y = map(int, sys.stdin.readline().split())
        posts.append((x, y))
    # Reconstruct the polygon
    # We need to find the order of the posts
    # Since the polygon is rectilinear and simple, we can sort the points

    # Build the edges
    # Sort points lexographically
    posts.sort()
    edges = []
    perimeter_positions = []
    pos_to_perimeter = {}
    perimeter = 0.0
    n = len(posts)
    for i in range(n):
        x1, y1 = posts[i]
        x2, y2 = posts[(i+1)%n]
        length = abs(x2 - x1) + abs(y2 - y1)
        perimeter_positions.append(perimeter)
        pos_to_perimeter[(x1, y1)] = perimeter
        perimeter += length
        edges.append(((x1, y1), (x2, y2), perimeter - length, perimeter))
    total_perimeter = perimeter

    # Build edge index
    horizontal_edges = {}
    vertical_edges = {}
    for (x1, y1), (x2, y2), start_p, end_p in edges:
        if x1 == x2:
            # Vertical edge
            x = x1
            y_start = min(y1, y2)
            y_end = max(y1, y2)
            if x not in vertical_edges:
                vertical_edges[x] = []
            vertical_edges[x].append((y_start, y_end, start_p, end_p))
        else:
            # Horizontal edge
            y = y1
            x_start = min(x1, x2)
            x_end = max(x1, x2)
            if y not in horizontal_edges:
                horizontal_edges[y] = []
            horizontal_edges[y].append((x_start, x_end, start_p, end_p))

    # For each cow, process starting and ending positions
    cows = []
    for _ in range(N):
        x1, y1, x2, y2 = map(int, sys.stdin.readline().split())
        # For each position, find which edge it lies on and compute its position along the perimeter
        def find_position(x, y):
            # Check horizontal edges first
            position = None
            if y in horizontal_edges:
                for x_start, x_end, start_p, end_p in horizontal_edges[y]:
                    if x_start <= x <= x_end:
                        # Point lies on this edge
                        length = abs(x - x_start)
                        if x_start == posts[edges.index(((x_start, y), (x_end, y)) % n)][0]:
                            edge_start_p = start_p
                        else:
                            edge_start_p = end_p
                        position = start_p + abs(x - x_start)
                        return position % total_perimeter
            if x in vertical_edges:
                for y_start, y_end, start_p, end_p in vertical_edges[x]:
                    if y_start <= y <= y_end:
                        # Point lies on this edge
                        length = abs(y - y_start)
                        position = start_p + abs(y - y_start)
                        return position % total_perimeter
            # If not found, raise error
            # For debugging purposes
            raise ValueError(f"Starting or ending position ({x}, {y}) not found on any edge.")
        pos1 = find_position(x1, y1)
        pos2 = find_position(x2, y2)
        cows.append((pos1, pos2))

    # Process cows and build difference array
    events = []
    for pos1, pos2 in cows:
        if pos1 <= pos2:
            dist_cw = pos2 - pos1
            dist_ccw = total_perimeter - dist_cw
            if dist_cw < dist_ccw:
                # Cow goes from pos1 to pos2 in clockwise direction
                events.append((pos1, 1))
                events.append((pos2, -1))
            else:
                # Cow goes from pos2 to pos1 in clockwise direction
                events.append((pos2, 1))
                events.append((pos1 + total_perimeter, -1))
        else:
            dist_cw = total_perimeter - (pos1 - pos2)
            dist_ccw = pos1 - pos2
            if dist_cw < dist_ccw:
                # Cow goes from pos1 to pos2 in clockwise direction
                events.append((pos1, 1))
                events.append((pos2 + total_perimeter, -1))
            else:
                # Cow goes from pos2, wraps around, to pos1
                events.append((pos2, 1))
                events.append((pos1, -1))
    # Now, sort the events
    events.sort()
    # Now, process the events and compute counts at each post
    post_positions = sorted(perimeter_positions)
    post_counts = [0]*n
    idx = 0
    count = 0
    event_idx = 0
    num_events = len(events)
    while idx < n:
        pos = post_positions[idx]
        while event_idx < num_events and events[event_idx][0] <= pos:
            count += events[event_idx][1]
            event_idx += 1
        post_counts[idx] = count
        idx += 1
    # Handle wrap-around events
    while event_idx < num_events:
        if events[event_idx][0] >= total_perimeter:
            break
        count += events[event_idx][1]
        event_idx += 1
    idx = 0
    while idx < n and events[event_idx-1][0] >= total_perimeter:
        pos = post_positions[idx]
        post_counts[idx] += count
        idx += 1
    # Output the counts
    for cnt in post_counts:
        print(int(cnt))
