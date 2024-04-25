## things to study
- [ ] dynamic programming
- [ ] two pointer solutions
- [ ] left/right solutions

### problems i had troubles with in interviews
> given array of n timestamps and an array of bounds return maximum amount of partitions of the array where a set of valid partitions has every partition following the rule `# of timestamps inside the bounds is > # of timestamps outside the bounds`

```
example
timestamps = [ 1, 3, 4, 6, 7, 9 ]

bounds = { left: 1, right: 6 }

output = 2 => [ 1, 3, 7 ], [ 4, 6, 9 ]
           or [ 1 ], [ 3, 4, 6, 7, 9 ]
```
