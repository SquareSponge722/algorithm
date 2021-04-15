package Java.内部类学习;

public class pet {
    cat tom = new cat();
    public class cat{
        public String name = "CAT";
        void sayName(){
            System.out.println(name);
        }
    }
    public void perName(){
        System.out.println(tom.name);
    }
}
