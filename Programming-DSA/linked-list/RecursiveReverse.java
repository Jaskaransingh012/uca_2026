class Node {

    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }

}

public class RecursiveReverse {


    public static Node reverse(Node head) {

        if(head == null || head.next == null) return head;

        Node newHead = reverse(head.next);

        head.next.next = head;

        head.next = null;

        return newHead;

    }

    public static void printList(Node head) {
        Node current = head;
        while (current != null) {
            System.out.print(current.data + " -> ");
            current = current.next;
        }
        System.out.println("null");
    }

    public static void main(String[] args) {

        Node head = new Node(1);
        head.next = new Node(2);
        head.next.next = new Node(3);
        head.next.next.next = new Node(4);

        System.out.println("Original List:");
        printList(head);

        head = reverseRecursive(head);

        System.out.println("Reversed List:");
        printList(head);
    }


}
