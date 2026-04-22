use std::cmp::Reverse;
use std::collections::BinaryHeap;

const INF: i32 = 999_999_999;

#[derive(Clone, Copy)]
struct Node {
    now: usize,
    cost: i32,
    time: i32,
}

impl PartialEq for Node {
    fn eq(&self, other: &Self) -> bool {
        self.time == other.time
    }
}

impl Eq for Node {}

impl PartialOrd for Node {
    fn partial_cmp(&self, other: &Self) -> Option<std::cmp::Ordering> {
        Some(self.cmp(other))
    }
}

impl Ord for Node {
    fn cmp(&self, other: &Self) -> std::cmp::Ordering {
        other.time.cmp(&self.time)
    }
}

fn dijkstra(start: usize, end: usize, vc: &Vec<Vec<Node>>, m: i32) -> i32 {
    let mut dp = vec![vec![INF; (m + 1) as usize]; 110];
    let mut pq = BinaryHeap::new();

    pq.push(Node {
        now: start,
        cost: 0,
        time: 0,
    });
    dp[start][0] = 0;

    while let Some(Node { now, cost, time }) = pq.pop() {
        if dp[now][cost as usize] < time {
            continue;
        }

        for &Node {
            now: next,
            cost: ncost,
            time: ntime,
        } in &vc[now]
        {
            if cost + ncost > m {
                continue;
            }

            if dp[next][cost as usize + ncost as usize] > dp[now][cost as usize] + ntime {
                dp[next][cost as usize + ncost as usize] = dp[now][cost as usize] + ntime;
                pq.push(Node {
                    now: next,
                    cost: cost + ncost,
                    time: dp[now][cost as usize] + ntime,
                });
            }
        }
    }

    dp[end]
        .iter()
        .take((m + 1) as usize)
        .min()
        .cloned()
        .unwrap_or(INF)
}

fn main() {
    let mut t = String::new();
    std::io::stdin().read_line(&mut t).unwrap();
    let t: i32 = t.trim().parse().unwrap();

    for _ in 0..t {
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        let mut iter = input.split_whitespace();
        let n: usize = iter.next().unwrap().parse().unwrap();
        let m: i32 = iter.next().unwrap().parse().unwrap();
        let k: usize = iter.next().unwrap().parse().unwrap();

        let mut vc: Vec<Vec<Node>> = vec![Vec::new(); 110];

        for _ in 0..k {
            let mut input = String::new();
            std::io::stdin().read_line(&mut input).unwrap();
            let mut iter = input.split_whitespace();
            let u: usize = iter.next().unwrap().parse().unwrap();
            let v: usize = iter.next().unwrap().parse().unwrap();
            let c: i32 = iter.next().unwrap().parse().unwrap();
            let t: i32 = iter.next().unwrap().parse().unwrap();
            vc[u].push(Node {
                now: v,
                cost: c,
                time: t,
            });
        }

        let result = dijkstra(1, n, &vc, m);
        if result == INF {
            println!("Poor KCM");
        } else {
            println!("{}", result);
        }
    }
}
