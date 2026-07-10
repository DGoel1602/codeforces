import java.util.*;

public class Solution {
    private static final int MOD = 1000000007;
    private static int[] knowledge;
    private static int maxDiff;
    private static int maxStudents;
    private static Map<Integer, Long> memo = new HashMap<>();
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Read input
        int nStudents = sc.nextInt();
        maxDiff = sc.nextInt();
        maxStudents = sc.nextInt();
        
        knowledge = new int[nStudents];
        for (int i = 0; i < nStudents; i++) {
            knowledge[i] = sc.nextInt();
        }
        
        // Sort the knowledge array
        Arrays.sort(knowledge);
        
        // Solve and print result
        System.out.println(build(0));
        
        sc.close();
    }
    
    private static long build(int currIdx) {
        // Check memoization
        if (memo.containsKey(currIdx)) {
            return memo.get(currIdx);
        }
        
        // Base case
        if (currIdx == knowledge.length) {
            return 1;
        }
        
        long tot = 0;
        
        // Try all possible group sizes
        for (int i = 1; i <= maxStudents; i++) {
            // Check if we have enough students left
            if (currIdx + i > knowledge.length) {
                continue;
            }
            
            // Check if knowledge difference is within maxDiff
            if (knowledge[currIdx + i - 1] - knowledge[currIdx] > maxDiff) {
                continue;
            }
            
            // Add this possibility
            tot = (tot + build(currIdx + i)) % MOD;
        }
        
        // Memoize and return
        memo.put(currIdx, tot);
        return tot;
    }
}
