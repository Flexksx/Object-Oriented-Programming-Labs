package StackQueueLab;

public interface IStack<T> {
    public void push(T item);
    public T pop();
    public T peek();
    public boolean isEmpty();
    public int size();
    public T get(int index);
    public T remove(int index);
    public T getitem(int index);
}
