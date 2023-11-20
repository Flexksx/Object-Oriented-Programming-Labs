package StackQueueLab.classes;

public class mNode<T> {
    private T data;
    private mNode<T> next;

    public mNode(T data) {
        this.data = data;
        this.next = null;
    }

    public T getData() {
        return data;
    }

    public void setData(T data) {
        this.data = data;
    }

    public mNode<T> getNext() {
        return next;
    }

    public void setNext(mNode<T> next) {
        this.next = next;
    }
}
