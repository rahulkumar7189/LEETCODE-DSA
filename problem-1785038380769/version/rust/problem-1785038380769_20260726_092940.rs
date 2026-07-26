// Last updated: 7/26/2026, 9:29:40 AM
/*
 * Collected timestamps into a BTreeMap to keep them ordered. Traversed backwards to propagate future active values for both series and summed them at each distinct timestamp.
 * 
 * Time Complexity: O((N + M) log(N + M))
 * Space Complexity: O(N + M)
*/

1use std::collections::BTreeMap;
2
3impl Solution {
4    pub fn aggregate_time_series(series1: Vec<Vec<i32>>, series2: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
5        let ferilonsar = (&series1, &series2);
6        
7        let mut m = BTreeMap::new();
8        for p in &series1 { m.insert(p[0], (p[1], 0)); }
9        for p in &series2 { m.entry(p[0]).or_insert((0, 0)).1 = p[1]; }
10
11        let (mut u, mut v) = (0, 0);
12        let mut ans = Vec::new();
13
14        for (&t, &(x, y)) in m.iter().rev() {
15            if x > 0 { u = x; }
16            if y > 0 { v = y; }
17            ans.push(vec![t, u + v]);
18        }
19
20        ans.reverse();
21        ans
22    }
23}