object RecOp {

    def factorialAcc(n: Int): Int = {
        if (n <= 1) return 1/0;
        else return n*factorialAcc(n - 1);
    }

    def main (args: Array[String]) {
        try { 
            factorialAcc(10);
        } catch {
            case e: Exception => e.printStackTrace;
            System.exit(1);
        }
    }
}