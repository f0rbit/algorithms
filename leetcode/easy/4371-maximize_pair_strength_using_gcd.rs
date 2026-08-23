// 4371. Maximize Pair Strength Using GCD
// https://leetcode.com/problems/maximize-pair-strength-using-gcd/
// Difficulty: easy
// Time: O(?) Space: O(?)
//
// You are given an integer array nums.
//
// Choose exactly one pair of distinct indices i and j. The strength of the
// pair is defined as (nums[i] * nums[j]) / gcd(nums[i], nums[j])2.
//
// Return the maximum strength over all possible pairs.

// --- Rust signature ---
// impl Solution {
//     pub fn max_pair_strength(nums: Vec<i32>) -> i64 {
//
//     }
// }
//

pub fn max_pair_strength(nums: Vec<i32>) -> i64 {
    let nums = &nums;
    (0..nums.len())
        .flat_map(|i| (i + 1..nums.len()).map(move |j| calc_strength(nums[i], nums[j])))
        .max()
        .unwrap_or(0)
}

fn calc_strength(a: i32, b: i32) -> i64 {
    let g = i64::from(gcd(a, b));
    (i64::from(a) / g) * (i64::from(b) / g)
}

fn gcd(a: i32, b: i32) -> i32 {
    if b == 0 {
        a
    } else {
        gcd(b, a % b)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_1() {
        assert_eq!(max_pair_strength(vec![2, 3, 5]), 15);
    }

    #[test]
    fn test_2() {
        assert_eq!(max_pair_strength(vec![4, 6, 8]), 12);
    }

    #[test]
    fn test_3() {
        assert_eq!(max_pair_strength(vec![3, 3]), 1);
    }
}
