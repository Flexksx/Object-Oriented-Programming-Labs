package Challenges;

public class challenge {
    public static void main(String[] args) {
        // Initials challenge
        // User usr = new User("John", "Doe");
        // System.out.println(usr.get_initials());

        // Diamond challenge
        // Diamond dmnd = new Diamond(7);
        // dmnd.draw();

        // Member Challenge
        // Member member = new Member(69, 10);
        // member.printCategory();

        // Multiples Challenge
        // MathUtils math = new MathUtils();
        // math.SumOfMultiples(10);

        //Find next perfect square
        // math.FindNextPerfect(143);
        
        //Find if number is narcissistic
        // math.isNarcissistic(1634);
    }
}

class User {
    private String firstName;
    private String lastName;

    public User(String _firstName, String _lastName) {
        this.firstName = _firstName;
        this.lastName = _lastName;
    }

    public String get_initials() {
        String initials = firstName.charAt(0) + ". " + lastName.charAt(0) + '.';
        return initials;
    }
}

class Diamond {
    private int size;

    public Diamond(int size) {
        this.size = size;
    }

    public void draw() {
        for (int i = 1; i <= this.size; i += 2) {
            int spaces = this.size - i;
            // System.out.println(spaces);
            int stars = i;
            String space = " ";
            String star = "*";
            String row = space.repeat(spaces / 2) + star.repeat(stars);// + space.repeat(spaces / 2);
            System.out.println(row);
        }
        for (int i = this.size - 2; i > 0; i -= 2) {
            int stars = i;
            int spaces = this.size - i;
            String space = " ";
            String star = "*";
            String row = space.repeat(spaces / 2) + star.repeat(stars);// + space.repeat(spaces / 2);
            System.out.println(row);
        }
    }

}

class Member {

    private int age;
    private int handicap;
    private boolean isOpen=true;

    public Member(int age, int handicap) {
        this.age = age;
        this.handicap = handicap;
        this.isOpen = (this.age>55 && this.handicap>7);
    }

    public void printCategory() {
        System.out.println((this.age > 55 && this.handicap > 7) ? "SENIOR" : "OPEN");
    }

}

class MathUtils {
    public void SumOfMultiples(int limit) {
        int sum = 0;
        for (int i = 3; i < limit; i += 3)
            sum += i;
        for (int i = 5; i < limit; i += 5)
            sum += i;
        System.out.println(sum);
    }

    public void FindNextPerfect(int sqr) {
        double curr_root = Math.sqrt(sqr);
        if (!(curr_root % 10 == 0)) {
            curr_root = Math.round(curr_root);
            System.out.println(curr_root * curr_root);
        } else {
            curr_root += 1;
            System.out.println(curr_root * curr_root);
        }
    }

    public void isNarcissistic(int num) {
        double sum = 0;
        double original_num = num;
        int pow = Integer.toString(num).length();
        while (num != 0) {
            sum = sum + Math.pow(num % 10, pow);
            num = num / 10;
        }
        System.out.println((original_num == sum) ? "Is Narcissistic" : "Is not narcissistic");

    }
}