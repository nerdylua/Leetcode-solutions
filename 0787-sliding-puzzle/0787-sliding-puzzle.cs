public class Solution {
    public int SlidingPuzzle(int[][] board) {
        string target = "123450";
        string start = string.Join("", board[0]) + string.Join("", board[1]);
        if (start == target) return 0;
        int[][] directions = new int[][] {
            new int[] {1, 3},        
            new int[] {0, 2, 4},     
            new int[] {1, 5},        
            new int[] {0, 4},        
            new int[] {1, 3, 5},     
            new int[] {2, 4}         
        };
        
        Queue<string> queue = new Queue<string>();
        HashSet<string> visited = new HashSet<string>();
        
        queue.Enqueue(start);
        visited.Add(start);
        int steps = 0;
        
        while (queue.Count > 0) {
            int size = queue.Count;
            for (int i = 0; i < size; i++) {
                string current = queue.Dequeue();
                if (current == target) return steps;
                
                int zeroPos = current.IndexOf('0');
                foreach (int nextPos in directions[zeroPos]) {
                    char[] newConfig = current.ToCharArray();
                    newConfig[zeroPos] = newConfig[nextPos];
                    newConfig[nextPos] = '0';
                    string newConfigStr = new string(newConfig);
                    
                    if (!visited.Contains(newConfigStr)) {
                        visited.Add(newConfigStr);
                        queue.Enqueue(newConfigStr);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
}