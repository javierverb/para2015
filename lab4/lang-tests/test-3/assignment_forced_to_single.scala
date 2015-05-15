object Assignment {

    def main (args: Array[String]) {
        
        val CONSTANT_m_assignment = 0;
        System.out.println("var multiple_assignment: "+CONSTANT_m_assignment);
        /* Dado que una constante no puede cambiar
        este programa no compilará */
        CONSTANT_m_assignment = 222;
    }
}