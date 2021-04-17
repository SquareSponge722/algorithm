
public class sample {
    public static void main(String[] args) {
        StringBuffer buffer = new StringBuffer("Hello");
        System.out.println(buffer); //Hello
        change(buffer);
        System.out.println(buffer); //Hello world!
        anotherChange(buffer);
        System.out.println(buffer); //Hello world!
    }
    public static void change(StringBuffer buffer){
        buffer.append(" world!");
    }
    public static void anotherChange(StringBuffer buffer){
        buffer = new StringBuffer("asdfsdfsdf");
        buffer.append("wowowowowow");
    }
}

//JAVA中对象参数传递的是其引用的副本
//基础类型参数传递的是值