import java.io.*;
import java.util.StringTokenizer;
 
// Counting Inversions
public class Main {
 
    private static int N;
    private static long result;
    private static int[] segmentTree;
 
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        segmentTree = new int[N * 4];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            int X = Integer.parseInt(st.nextToken());
            result += X - 1 - query(1, N, 1, 1, X - 1);
            update(1, N, 1, X);
        }
 
        System.out.println(result);
    }
 
    private static int update(int start, int end, int node, int pos) {
        if (pos < start || end < pos) return segmentTree[node];
        if (start == end) return segmentTree[node] += 1;
        int mid = (start + end) >> 1;
        return segmentTree[node] = update(start, mid, node * 2, pos) + update(mid + 1, end, node * 2 + 1, pos);
    }
 
   
    private static int query(int start, int end, int node, int left, int right) {
        if (right < start || end < left) return 0;
        if (left <= start && end <= right) return segmentTree[node];
        int mid = (start + end) >> 1;
        return query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2 + 1, left, right);
    }
}