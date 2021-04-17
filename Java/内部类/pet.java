
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
