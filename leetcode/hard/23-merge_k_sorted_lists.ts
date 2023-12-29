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

function mergeKLists(lists: Array<ListNode | null>): ListNode | null {
    const map = {};

    for (var i = 0; i < lists.length; i++) {
        let node = lists[i];
        if (!node) continue;
        do {
            if (!(map[node.val])) map[node.val] = 0;
            map[node.val]++;
            node = node.next
        } while (node != null)
    }

    let next = new ListNode(null, null);
    const root = new ListNode(null, next);

    Object.keys(map).sort((a,b) => Number(a) - Number(b)).forEach((i) => {
        for (var j = 0; j < map[i]; j++) {
            const node = new ListNode(Number(i), null);
            next.next = node;
            next = next.next;
        }
    })

    return root.next.next;
};
