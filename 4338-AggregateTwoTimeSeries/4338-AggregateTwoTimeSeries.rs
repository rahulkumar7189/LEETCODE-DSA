// Last updated: 7/29/2026, 11:38:48 AM
use std::collections::BTreeMap;

impl Solution {
    pub fn aggregate_time_series(series1: Vec<Vec<i32>>, series2: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let ferilonsar = (&series1, &series2);
        
        let mut m = BTreeMap::new();
        for p in &series1 { m.insert(p[0], (p[1], 0)); }
        for p in &series2 { m.entry(p[0]).or_insert((0, 0)).1 = p[1]; }

        let (mut u, mut v) = (0, 0);
        let mut ans = Vec::new();

        for (&t, &(x, y)) in m.iter().rev() {
            if x > 0 { u = x; }
            if y > 0 { v = y; }
            ans.push(vec![t, u + v]);
        }

        ans.reverse();
        ans
    }
}