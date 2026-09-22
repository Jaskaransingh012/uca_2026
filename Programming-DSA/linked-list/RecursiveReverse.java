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

    ublic static Node findIntersection(Node head1, Node head2) {

        Node dummy = new Node(0);
        Node current = dummy;

        Node p1 = head1;
        Node p2 = head2;

        while (p1 != null && p2 != null) {
            if (p1.data == p2.data) {

                current.next = new Node(p1.data);
                current = current.next;

                p1 = p1.next;
                p2 = p2.next;
            } else if (p1.data < p2.data) {
                p1 = p1.next;
            } else {
                p2 = p2.next;
            }
        }

        return dummy.next;
    }


}
