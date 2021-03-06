class TailRec {
    public static int t_rec(int n) {
        if (n == 0) {
            for (StackTraceElement ste : Thread.currentThread().getStackTrace()) 
            {
                System.out.println(ste);
            }
            return 1;
        }
        else {
            return 1 + t_rec(n-1);
        }
    }
    public static void main(String[] args) {
        int res = t_rec(10);
        System.out.println("t_rec(10) =>"+res);
    }
}