// 350. Intersection of Two Arrays II
// https://leetcode.com/problems/intersection-of-two-arrays-ii/
// Difficulty: easy
// Time: O(?) Space: O(?)
//
// Given two integer arrays nums1 and nums2, return an array of their
// intersection. Each element in the result must appear as many times as it
// shows in both arrays and you may return the result in any order.

// --- Rust signature ---
// impl Solution {
//     pub fn intersect(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
//
//     }
// }

use std::collections::HashMap;

/**
* pseudo-code 1:
* make a Set<i32>, add all from nums2
* go through nums1, if not in the set, remove from num1 -> return nums1
*
* or
*
* make same set
* make new list
* append all from nums1 that exist in nums2
*
*
*
* feel like there should be some set union function we can do here,
* make 2 sets, do some .union() of them??
*
*/
pub fn intersect(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
    let mut counts = nums2.iter().fold(HashMap::new(), |mut acc, &x| {
        *acc.entry(x).or_insert(0) += 1;
        acc
    });
    nums1.into_iter()
        .filter(|x| {
            counts.get_mut(x).is_some_and(|c| {
                *c -= 1;
                *c >= 0
            })
        })
        .collect()
}

#[cfg(test)]
mod tests {
    use super::*;

    // Input: nums1 = [1,2,2,1], nums2 = [2,2] | Output: [2,2]
    #[test]
    fn test_1() {
        assert_eq!(intersect(vec![1, 2, 2, 1], vec![2, 2]), vec![2, 2]);
    }

    // Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4] | Output: [4,9]
    #[test]
    fn test_2() {
        assert_eq!(intersect(vec![4, 9, 5], vec![9, 4, 9, 8, 4]), vec![4, 9]);
    }
}
