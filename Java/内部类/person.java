
public class person {
    private String name;
    private int sex;
    private String id;
    private int age;

    public String getName() {
        return name;
    }
    public int getSex() {
        return sex;
    }
    public String getId() {
        return id;
    }
    public int getAge() {
        return age;
    }

    public static class builder {
        private String name;
        private int sex;
        private String id;
        private int age;

        public builder(int age,int sex){
            this.age = age;
            this.sex = sex;
        }

        public builder setName(String name) {
            this.name = name;
            return this;
        }
        public builder setSex(int sex) {
            this.sex = sex;
            return this;
        }
        public builder setId(String id) {
            this.id = id;
            return this;
        }
        public builder setAge(int age) {
            this.age = age;
            return this;
        }

        public person build(){
            return new person(this);
        }
    }

    private person(builder builder){
        this.age = builder.age;
        this.id = builder.id;
        this.name = builder.name;
        this.sex = builder.sex;
    }

    static builder getB(){
        return new builder(0,0);
    }

    @Override
    public String toString() {
        return "Person{\n" + 
            "name: " + name + "\n" +
            "sex: " + sex + "\n" +
            "age: " + age + "\n" +
            "id: " + id + "\n}"; 
    }
}
