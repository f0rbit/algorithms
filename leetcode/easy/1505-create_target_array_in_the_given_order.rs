// 1505. Create Target Array in the Given Order
// https://leetcode.com/problems/create-target-array-in-the-given-order/
// Difficulty: easy
// Time: O(?) Space: O(?)
//
// Given two arrays of integers nums and index. Your task is to create target
// array under the following rules:
//
// - Initially target array is empty.
// - From left to right read nums[i] and index[i], insert at index index[i] the
// value nums[i] in target array.
// - Repeat the previous step until there are no elements to read in nums and
// index.
//
// Return the target array.
//
// It is guaranteed that the insertion operations will be valid.

// --- Rust signature ---
// impl Solution {
//     pub fn create_target_array(nums: Vec<i32>, index: Vec<i32>) -> Vec<i32> {
//         
//     }
// }

pub fn create_target_array(nums: Vec<i32>, index: Vec<i32>) -> Vec<i32> {
    let mut target = Vec::new();
    nums.iter().zip(index.iter()).for_each(|(&num, &idx)| {
        target.insert(idx as usize, num);
    });
    return target
}

#[cfg(test)]
mod tests {
    use super::*;

    // Input: nums = [0,1,2,3,4], index = [0,1,2,2,1] | Output: [0,4,1,3,2]
    #[test]
    fn test_1() {
        assert_eq!(create_target_array(vec![0,1,2,3,4], vec![0,1,2,2,1]), vec![0,4,1,3,2]);
    }

    // Input: nums = [1,2,3,4,0], index = [0,1,2,3,0] | Output: [0,1,2,3,4]
    #[test]
    fn test_2() {
        assert_eq!(create_target_array(vec![1,2,3,4,0], vec![0,1,2,3,0]), vec![0,1,2,3,4]);
    }

    // Input: nums = [1], index = [0] | Output: [1]
    #[test]
    fn test_3() {
        assert_eq!(create_target_array(vec![1], vec![0]), vec![1]);
    }
}
