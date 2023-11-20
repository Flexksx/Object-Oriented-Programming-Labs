package StackQueueLab.classes;

import StackQueueLab.interfaces.IList;

public class MyList<T> implements IList<T> {

    private Node head;
    private int size;

    @Override
    public void add(T element) {
        Node newNode = new Node(element);
        if (head == null) {
            head = newNode;
        } else {
            Node temp = head;
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = newNode;
        }
        size++;
    }

    @Override
    public T remove() {
        if (isEmpty()) {
            throw new IllegalStateException("Cannot remove from empty list");
        }
        Node temp = head;
        head = temp.next;
        size--;
        return temp.element;
    }

    @Override
    public T get(int index) {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException("Index " + index + " out of bounds");
        }
        Node temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp.next;
        }
        return temp.element;
    }

    @Override
    public int size() {
        return size;
    }

    @Override
    public boolean isEmpty() {
        return size == 0;
    }

    @Override
    public void clear() {
        head = null;
        size = 0;
    }

    @Override
    public boolean contains(T element) {
        Node temp = head;
        while (temp != null) {
            if (temp.element.equals(element)) {
                return true;
            }
            temp = temp.next;
        }
        return false;
    }

    @Override
    public int indexOf(T element) {
        int index = 0;
        Node temp = head;
        while (temp != null) {
            if (temp.element.equals(element)) {
                return index;
            }
            index++;
            temp = temp.next;
        }
        return -1;
    }

    private class Node {
        private T element;
        private Node next;

        public Node(T element) {
            this.element = element;
            this.next = null;
        }
    }
}
