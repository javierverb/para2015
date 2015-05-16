class Scope {
    
    int y = 1;
    int fun_print(int z) {
        System.out.format("El valor de y es: %d\n", z);
        System.out.format("El valor de y es: %d\n", y);
        System.out.format("Java tiene alcance Estático\n");
        return z;
    }

    int fun_write(int z){
        int y = 3;
        System.out.format("El valor de y en fun_write es: %d\n", y);
        return fun_print(y + z);
    }

    public static void main (String args[]) {
        
        int y = 2;
        System.out.format("El valor de y en main es: %d\n", y);
        Scope a = new Scope();
        a.fun_write(y);
  }
}
