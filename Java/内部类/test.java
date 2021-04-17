
public class test {
    public static void main(String[] args) {
        person jack = new person.builder(25, 1).setName("Jack").setId("4231").build(); 
        //这里new的是内部类builder,最后build()返回person实例引用
        //正因builder是静态内部类,所以可以在外部未实例化的情况下实例化
        System.out.println(jack);

        person.builder bb = person.getB(); //这里通过静态方法不实例化person获取内部类实例
        System.out.println(bb.setName("WOW").build()); 
        //build内部类通过build()实例化person外部类
        //实际上和上一段的代码逻辑是一样的

        pet tom = new pet();
        tom.perName(); //CAT
        pet.cat jerry = tom.new cat(); //实例化内部类
        jerry.name = "Jerry";
        tom.perName(); //CAT
    }
}