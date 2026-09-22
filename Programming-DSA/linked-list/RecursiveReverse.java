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

        public static boolean isSubList(Node list1, Node list2) {

        if (list1 == null) {
            return true;
        }

        if (list2 == null) {
            return false;
        }

        Node ptr2 = list2;


        while (ptr2 != null) {

            Node temp2 = ptr2;
            Node temp1 = list1;

            while (temp1 != null && temp2 != null) {
                if (temp1.data == temp2.data) {
                    temp1 = temp1.next;
                    temp2 = temp2.next;
                } else {
                    break;
                }
            }

            if (temp1 == null) {
                return true;
            }

            ptr2 = ptr2.next;
        }

        return false;
    }

}
