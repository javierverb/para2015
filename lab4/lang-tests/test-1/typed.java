class StrongerTyped {

    public static void main(String[] args)
    {

        int tStatic = 0;
        /* Intentamos cambiar el tipo de
        la variable "tStatic"*/
        
        tStatic = "I'm a string";
        /* Esto dará un error en tiempo de compilación: 
        Se esperaba un int. */
    }
}