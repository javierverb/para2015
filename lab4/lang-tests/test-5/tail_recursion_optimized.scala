object Assignment {

    @tailrec def factorialAcc(acc: Int, n: Int): Int = {
        if (n <= 1) 1/0
        else factorialAcc(n * acc, n - 1)
    }

    def main (args: Array[String]) {
        factorialAcc(1, 10);
    }
}