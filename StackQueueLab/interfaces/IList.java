package StackQueueLab.interfaces;

public interface IList<T> {
    public void add(T element);

    public T remove();

    public T get(int index);

    public int size();

    public boolean isEmpty();

    public void clear();

    public boolean contains(T element);

    public int indexOf(T element);
}
