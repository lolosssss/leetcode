class ListNode {
  val: number;
  next: ListNode | null;
  constructor(val?: number, next?: ListNode | null) {
    this.val = val === undefined ? 0 : val;
    this.next = next === undefined ? null : next;
  }
}

function removeNthFromEnd(head: ListNode | null, n: number): ListNode | null {
  let left = head;
  let right = head;
  let cnt = 0;

  if (head === null) {
    return null;
  }

  while (cnt < n) {
    right = right.next;
    cnt++;
  }

  if (!right) {
    return left.next;
  }

  while (right.next) {
    right = right.next;
    left = left.next;
  }

  left.next = left.next.next;

  return head;
}

function createNodes(len: number): ListNode | null {
  if (len === 0) {
    return null;
  }

  let head;
  let ptr;
  for (let i = 0; i < len; i++) {
    if (!ptr) {
      head = new ListNode(i + 1);
      ptr = head;
    } else {
      ptr.next = new ListNode(i + 1);
      ptr = ptr.next;
    }
  }

  return head;
}

function printNodes(head: ListNode | null) {
  if (head === null) return;
  let ptr = head;
  let str = `${ptr.val}`;

  while (ptr.next) {
    ptr = ptr.next;
    str += `->${ptr.val}`;
  }
  console.log(str);
}

let nodes = createNodes(30);
printNodes(nodes);
let removed = removeNthFromEnd(nodes, 30);
printNodes(removed);
