class TailRec {
    public static int t_rec(int n, int acc) {
        if (n == 0) {
            for (StackTraceElement ste : Thread.currentThread().getStackTrace()) 
            {
                System.out.println(ste);
            }
            return 1+acc;
        }
        else {
            return t_rec(n-1, acc+1);
        }
    }
    public static void main(String[] args) {
        int res = t_rec(10, 0);
        System.out.println("t_rec(10) =>"+res);
    }
}