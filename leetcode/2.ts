class ListNode {
  val: number;
  next?: ListNode | null;
  constructor(val?: number, next?: ListNode | null) {
    this.val = val ?? 0;
    this.next = next ?? null;
  }
}

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

function addTwoNumbers(
  l1?: ListNode | null,
  l2?: ListNode | null,
  carry?: number
): ListNode | null {
  if (!l1 && !l2) return carry ? new ListNode(carry) : null;
  const k = (l1?.val ?? 0) + (l2?.val ?? 0) + (carry ?? 0);
  return new ListNode(
    k % 10,
    addTwoNumbers(l1?.next, l2?.next, k >= 10 ? 1 : 0)
  );
}
