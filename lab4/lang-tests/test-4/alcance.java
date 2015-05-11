class Global {
    public static int global_var = 1;
}

class Alcance {
    
    public static int fun_a(int z){
        System.out.println("esto es z en fun_a");
        System.out.println(z);
        System.out.println("esto es global_var en fun_a");
        System.out.println(Global.global_var);
        return (z + Global.global_var);
    }
    
    public static int fun_b(int y){
        /*int global_var = 0;*/

        System.out.println("esto es y en fun_b");
        System.out.println(y);
        System.out.println("esto es global_var en fun_b");
        System.out.println(Global.global_var);

        Global.global_var = y + 1;
        System.out.println("ahora global_var = y+1 (sigo en fun_b)");
        System.out.println(Global.global_var);
        return fun_a(Global.global_var * y);
    }

    public static void main(String[] args){
        System.out.println("hola a todos esto es main");
        
        int result;
        result = fun_b(3);

        System.out.println(result);
    }

}

/*en fun_b redefini el global_var, dandole el valor de y+1
  la deficinicion tendria que tener el alcance del bloque,
  por lo que si toma valor 4 en fun_a, significa que al compilar,
  la variable toma el valor del ultimo ACTIVATION-RECORD por lo tanto
  JAVA es de alcance DINAMICO*/
