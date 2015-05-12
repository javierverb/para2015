public class typed {
    public static void main(String[] args) {

        int num = 10; 
        System.out.println();
        System.out.println("la variable num:" + num);

        String word = new String("hola!!");
        System.out.println("la variable word: " + word);

        String word2 = new String("chau!!");
        System.out.println("la variable word2: " + word2);
        System.out.println();

        String result = word + num;
        System.out.println("result = word + num");
        System.out.println("result: " + result);
        System.out.println();

        System.out.println("word * num es error");
        System.out.println("word * word es error");
        System.out.println("word + num es valido : " + result);
        System.out.println("word + word es valido: " + (word + word2));
        System.out.println();
        System.out.println("java es de tipado DEBIL");

    }
}