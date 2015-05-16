public class Point {
    public int x;
    public int y;

    public Point(int x, int y){
        System.out.println("\tadentro de Point");
        this.x = x;
        this.y = y;
        System.out.println("\tthis.x = " + this.x + ", x = " + x);
        System.out.println("\tthis.y = " + this.y + ", y = " + y);
        System.out.println("\tafuera de Point");
    }

    public static void tricky1(Point arg1, Point arg2)
    {
        arg1.x = 100;
        arg1.y = 100;
        System.out.println("DENTRO DE tricky1");
        System.out.println("\targ1.x = " + arg1.x + " arg1.y = " + arg1.y);
        System.out.println("\targ2.x = " + arg2.x + " arg2.y = " + arg2.y);
        Point temp = arg1;
        System.out.println("\ttemp = arg1");
        System.out.println("\targ1.x = " + arg1.x + " arg1.y = " + arg1.y);
        System.out.println("\targ2.x = " + arg2.x + " arg2.y = " + arg2.y);
        arg1 = arg2;
        System.out.println("\targ1 = arg2");
        System.out.println("\targ1.x = " + arg1.x + " arg1.y = " + arg1.y);
        System.out.println("\targ2.x = " + arg2.x + " arg2.y = " + arg2.y);
        arg2 = temp;
        System.out.println("\targ2 = temp");
        System.out.println("\targ1.x = " + arg1.x + " arg1.y = " + arg1.y);
        System.out.println("\targ2.x = " + arg2.x + " arg2.y = " + arg2.y);
        System.out.println("FUERA DE tricky1");
    }

    public static void tricky2(Point arg1, Point arg2)
    {
        arg1 = null;
        arg2 = null;
    }

    public static void main(String[] args)
    {
        System.out.println("\nINICIALIZACION");
        Point pnt1 = new Point(0,0);
        Point pnt2 = new Point(0,0);
        System.out.println("\npnt1 X: " + pnt1.x + " pnt1 Y: " + pnt1.y);
        System.out.println("pnt2 X: " + pnt2.x + " pnt2 Y: " + pnt2.y);
        System.out.println("-------------------------------------------");
        System.out.println("\ntricky1");
        tricky1(pnt1, pnt2);
        System.out.println("pnt1 X: " + pnt1.x + " pnt1 Y: " + pnt1.y);
        System.out.println("pnt2 X: " + pnt2.x + "   pnt2 Y: " + pnt2.y);
        System.out.println("-------------------------------------------");
        System.out.println("\ntricky2");
        tricky2(pnt2, pnt2);
        System.out.println("pnt1 X: " + pnt1.x + " pnt1 Y: " + pnt1.y);
        System.out.println("pnt2 X: " + pnt2.x + "   pnt2 Y: " + pnt2.y);
        System.out.println("-------------------------------------------");
    }
}