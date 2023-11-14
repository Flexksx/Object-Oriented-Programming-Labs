package StackQueueLab;

import java.util.ArrayList;
import java.util.ArrayList;

public class LabStack<T> implements IStack<T> {

    private ArrayList<T> stack;

    public LabStack() {
        stack = new ArrayList<T>();
    }

    @Override
    public T peek() {
        if (stack.isEmpty()) {
            return null;
        }
        return stack.get(stack.size() - 1);
    }

    @Override
    public boolean isEmpty() {
        return stack.isEmpty();
    }

    @Override
    public int size() {
        return stack.size();
    }

    @Override
    public T pop() {
        if (stack.isEmpty()) {
            return null;
        }
        return stack.remove(stack.size() - 1);
    }

    @Override
    public void push(T item) {
        stack.add(item);
    }

    @Override
    public T get(int index) {
        if (index < 0 || index >= stack.size()) {
            return null;
        }
        return stack.get(index);
    }

    @Override
    public T remove(int index) {
        if (index < 0 || index >= stack.size()) {
            return null;
        }
        return stack.remove(index);
    }

    @Override
    public T getitem(int index) {
        if (index < 0 || index >= stack.size()) {
            return null;
        }
        return stack.get(index);
    }
}
