// 2058. Concatenation of Array
// https://leetcode.com/problems/concatenation-of-array/
// Difficulty: easy
// Time: O(?) Space: O(?)
//
// Given an integer array nums of length n, you want to create an array ans of
// length 2n where ans[i] == nums[i] and ans[i + n] == nums[i] for 0 <= i < n
// (0-indexed).
//
// Specifically, ans is the concatenation of two nums arrays.
//
// Return the array ans.

// --- Rust signature ---
// impl Solution {
//     pub fn get_concatenation(nums: Vec<i32>) -> Vec<i32> {
//         
//     }
// }

pub fn get_concatenation(nums: Vec<i32>) -> Vec<i32> {
    let mut target = Vec::new();
    target.extend(&nums);
    target.extend(&nums);
    target
}

#[cfg(test)]
mod tests {
    use super::*;

    // Input: nums = [1,2,1] | Output: [1,2,1,1,2,1]
    #[test]
    fn test_1() {
        assert_eq!(get_concatenation(vec![1,2,1]), vec![1,2,1,1,2,1]);
    }

    // Input: nums = [1,3,2,1] | Output: [1,3,2,1,1,3,2,1]
    #[test]
    fn test_2() {
        assert_eq!(get_concatenation(vec![1,3,2,1]), vec![1,3,2,1,1,3,2,1]);
    }
}
