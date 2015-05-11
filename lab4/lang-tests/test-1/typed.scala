object Typed {

    def main (args: Array[String]) {
        
        var tstatic = 0;

        /* Esto dará un error en tiempo de compilación: 
        Se esperaba un int. Ademas de que no permite
        reescribir el valor */
        tstatic = "Never will be this value";
    }
}