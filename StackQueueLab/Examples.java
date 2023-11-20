
package StackQueueLab;

import StackQueueLab.classes.MyList;

public class Examples {
    public static void main(String[] args) {
        MyList<Integer> list = new MyList<>();
        list.add(1);
        list.add(2);
        list.add(3);
        System.out.println(list.contains(4));
    }
}

