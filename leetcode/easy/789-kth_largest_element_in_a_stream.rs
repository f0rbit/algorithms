// 789. Kth Largest Element in a Stream
// https://leetcode.com/problems/kth-largest-element-in-a-stream/
// Difficulty: easy
// Time: O(?) Space: O(?)
//
// You are part of a university admissions office and need to keep track of the
// kth highest test score from applicants in real-time. This helps to determine
// cut-off marks for interviews and admissions dynamically as new applicants
// submit their scores.
//
// You are tasked to implement a class which, for a given integer k, maintains
// a stream of test scores and continuously returns the kth highest test score
// after a new score has been submitted. More specifically, we are looking for
// the kth highest score in the sorted list of all scores.
//
// Implement the KthLargest class:
//
// - KthLargest(int k, int[] nums) Initializes the object with the integer k
// and the stream of test scores nums.
// - int add(int val) Adds a new test score val to the stream and returns the
// element representing the kth largest element in the pool of test scores so
// far.

use std::{cmp::Reverse, collections::BinaryHeap};

// --- Rust signature ---
// struct KthLargest {
//
// }
//
//
// /**
//  * `&self` means the method takes an immutable reference.
//  * If you need a mutable reference, change it to `&mut self` instead.
//  */
// impl KthLargest {
//
//     fn new(k: i32, nums: Vec<i32>) -> Self {
//
//     }
//
//     fn add(&self, val: i32) -> i32 {
//
//     }
// }
//
// /**
//  * Your KthLargest object will be instantiated and called as such:
//  * let obj = KthLargest::new(k, nums);
//  * let ret_1: i32 = obj.add(val);
//  */
struct KthLargest {
    k: usize,
    heap: BinaryHeap<Reverse<i32>>,
}

impl KthLargest {
    fn new(k: i32, nums: Vec<i32>) -> Self {
        let mut s = KthLargest { k: k as usize, heap: BinaryHeap::new() };
        for n in nums { s.add(n); }
        s
    }


    fn add(&mut self, val: i32) -> i32 {
        // brute force: add to list, resort, return k (TLE 10/12)
        // self.nums.push(val);
        // self.nums.sort();
        // self.nums.reverse();
        // return self.nums[self.k - 1];

        // slightly better, dont sort -> reverse, do in one. (Pass, bottom 5% time)
        // self.nums.push(val);
        // self.nums.sort_by(|a, b| b.cmp(a));
        // return self.nums[self.k - 1];

        // with some googling, found that rust has Vec#binary_search to give us the index to insert
        // on. because rust's .sort() and .binary_search are reverse, we need to lookup by end - k,
        // rather than start + k
        //let idx = self.nums.binary_search(&val).unwrap_or_else(|e| e);
        //self.nums.insert(idx, val);
        //return self.nums[self.nums.len() - self.k];
        self.heap.push(Reverse(val));
        if self.heap.len() > self.k {
            self.heap.pop();
        }
        self.heap.peek().unwrap().0
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_1() {
        let mut obj = KthLargest::new(4, vec![7, 7, 7, 7, 8, 3]);
        assert_eq!(obj.add(2), 7);
        assert_eq!(obj.add(10), 7);
        assert_eq!(obj.add(9), 7);
        assert_eq!(obj.add(9), 8);
    }
}
