/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

class ListNode {
  val: number;
  next: ListNode | null;

  constructor(val?: number, next?: ListNode | null) {
    this.val = val === undefined ? 0 : val;
    this.next = next === undefined ? null : next;
  }
}

function addTwoNumbers(l1: ListNode | null, l2: ListNode | null): ListNode | null {
  let ret = new ListNode();
  let p = ret,
    p1 = l1,
    p2 = l2;
  let v1 = l1.val,
    v2 = l2.val;
  let tmpSum = v1 + v2;
  let carry = Math.floor(tmpSum / 10);
  p.val = tmpSum > 9 ? tmpSum - 10 : tmpSum;

  while (p1.next || p2.next) {
    if (p1.next) {
      p1 = p1.next;
      v1 = p1.val;
    } else {
      v1 = 0;
    }
    if (p2.next) {
      p2 = p2.next;
      v2 = p2.val;
    } else {
      v2 = 0;
    }

    tmpSum = v1 + v2 + carry;
    carry = Math.floor(tmpSum / 10);
    let n = new ListNode();
    n.val = tmpSum > 9 ? tmpSum - 10 : tmpSum;
    p.next = n;
    p = p.next;
  }

  if (carry === 1) {
    p.next = new ListNode(1);
  }

  return ret;
}
