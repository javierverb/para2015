object Scope {
    
    var y : Int = 0;
    def fun_print(z: Int) {
        println("El valor de z en fun_print es: " + z);
        println("El valor de y en fun_print es: " + y);
        println("Java tiene alcance Estático");
    }

    def rewrite(z: Int){
        var y : Int = 3;
        println("El valor de y en rewrite es: " + y);
        return fun_print(y + z);
    }

    def main(args: Array[String]) {

        // val a = new Alcance()
        var y : Int = 2
        println(" la variable y en main vale: " + y);
        rewrite(y)
    }
}

//scala es de alcance estatico