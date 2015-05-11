public class tipado {
    public static void main(String[] args) {

        int num = 10;
        System.out.println(num);

        String word = new String("hola!!");
        System.out.println(word);

        String word2 = new String("chau!!");
        System.out.println(word2);

        String result = word + num;
        System.out.println(result);

        System.out.println("word * num es error");
        System.out.println("word * word es error");
        System.out.println("word + num es valido : 'hola!!10'");
        System.out.println("word + word es valido: 'hola!!chau!!'");

        System.out.println("java es de tipado DEBIL");

    }
}