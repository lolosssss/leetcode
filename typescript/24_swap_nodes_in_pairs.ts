class ListNode {
  val: number;
  next: ListNode | null;

  constructor(val?: number, next?: ListNode | null) {
    this.val = val === undefined ? 0 : val;
    this.next = next === undefined ? null : next;
  }
}

function swapPairs(head: ListNode | null): ListNode | null {
  if (head === null || head.next === null) {
    return head;
  }

  let cur = head;
  let n1 = cur.next;
  if (!n1.next) {
    n1.next = cur;
    cur.next = null;
    return n1;
  }
  let n2 = n1.next;
  head = n1;

  while (cur && n1 && n2) {
    n1.next = cur;

    if (!n2.next) {
      cur.next = n2;
      break;
    } else {
      cur.next = n2.next;
    }

    cur = n2;
    n1 = cur.next;
    n2 = n1.next;
  }

  if (!n2) {
    n1.next = cur;
    cur.next = null;
  }

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

for (let i = 0; i < 7; i++) {
  let nodes = createNodes(i);
  console.log(`-------- ${i} -------`);
  // printNodes(nodes);
  printNodes(swapPairs(nodes));
}
